#include "zgl.h"
#include <stdio.h>
#include "ztriangle.h"
#include "light.h"
/* glVertex */
void gl_vertex_transform(GLContext * c, GLVertex * v);
void glopMaterial(GLContext *c,GLParam *p);

 
class GraphDrawLib
{
public:
inline void gl_matrix_update(GLContext *c);
inline void gl_eval_viewport(GLContext * c);
inline void glVertex4f(float x,float y,float z,float w);
inline void glVertex3f(float x,float y,float z); 
inline void glVertex3fv(float *v); 
inline void glNormal3f(float x,float y,float z);
inline void glColor4f(float r,float g,float b,float a);
inline void glColor3f(float x,float y,float z); 
inline void glTexCoord4f(float s,float t,float r,float q);
inline void glTexCoord2f(float s,float t);
inline void GL_EnableDisable(GLContext *c,GLParam *p);
inline void glEnable(int cap);
inline void glDisable(int cap);
 
inline void glBegin(int mode);
inline void glEnd(void);
inline void glMatrixMode(int mode);
inline void glLoadIdentity(void);
inline void glMultMatrixf(const float *mm);
inline void glPushMatrix(void);
inline void glPopMatrix(void);
inline void glRotatef(float angle,float x,float y,float z);
inline void glTranslatef(float x,float y,float z);
inline void glScalef(float x,float y,float z);
inline void glViewport(int x,int y,int width,int height);
inline void glFrustum(double left,double right,double bottom,double top,
               double near,double farp);
inline void gluPerspective( GLdouble fovy, GLdouble aspect,
		     GLdouble zNear, GLdouble zFar );
inline void glMaterialfv(int mode,int type,float *v);
inline void glMaterialf(int mode,int type,float val);
inline void glLightfv(int light,int type,float *val);
inline void glTexImage2D( int target, int level, int components,
                   int width, int height, int border,
                   int format, int type, void *pixels);
GLTexture * alloc_texture(GLContext *c,int h);
GLTexture * find_texture(GLContext *c,int h);
inline void glBindTexture(int target,int texture);
};

inline void GraphDrawLib::gl_matrix_update(GLContext *c)
{
  c->matrix_model_projection_updated=(c->matrix_mode<=1);
}

inline void GraphDrawLib::gl_eval_viewport(GLContext * c)
{
    GLViewport *v;
    float zsize = (1 << (ZB_Z_BITS + ZB_POINT_Z_FRAC_BITS));
	int dgbzsize = zsize;

    v = &c->viewport;

    v->trans.X = ((v->xsize - 0.5) / 2.0) + v->xmin;
    v->trans.Y = ((v->ysize - 0.5) / 2.0) + v->ymin;
    v->trans.Z = ((zsize - 0.5) / 2.0) + ((1 << ZB_POINT_Z_FRAC_BITS)) / 2;

    v->scale.X = (v->xsize - 0.5) / 2.0;
    v->scale.Y = -(v->ysize - 0.5) / 2.0;
    v->scale.Z = -((zsize - 0.5) / 2.0);
}

inline void GraphDrawLib::glVertex4f(float x,float y,float z,float w)
{
  GLContext *c=gl_get_context(); 
  GLVertex *v;

    int n, i, cnt;

    assert(c->in_begin != 0);

    n = c->vertex_n;
    cnt = c->vertex_cnt;
    cnt++;
    c->vertex_cnt = cnt;

    /* quick fix to avoid crashes on large polygons */
    if (n >= c->vertex_max) {
	GLVertex *newarray;
	c->vertex_max <<= 1;	/* just double size */
	newarray = (GLVertex *)gl_malloc(sizeof(GLVertex) * c->vertex_max);
	if (!newarray) {
	   exit(0);// gl_fatal_error("unable to allocate GLVertex array.\n");
	}
	memcpy(newarray, c->vertex, n * sizeof(GLVertex));
	gl_free(c->vertex);
	c->vertex = newarray;
    }
    /* new vertex entry */
    v = &c->vertex[n];
    n++;

    v->coord.X = x;
    v->coord.Y = y;
    v->coord.Z = z;
    v->coord.W = w;

    gl_vertex_transform(c, v);

    /* color */

    if (c->lighting_enabled) {
	gl_shade_vertex(c, v);
    } else {
	v->color = c->current_color;
    }

    /* tex coords */

    if (c->texture_2d_enabled) {
	if (c->apply_texture_matrix) {
	    M4::gl_M4_MulV4(&v->tex_coord, c->TkGLMat[KH_TEXTURE].get_current_matrix(), &c->current_tex_coord);
	} else {
	    v->tex_coord = c->current_tex_coord;
	}
    }
    /* precompute the mapping to the viewport */
    if (v->clip_code == 0)
	gl_transform_to_viewport(c, v);

    /* edge flag */

    v->edge_flag = c->current_edge_flag;

    switch (c->begin_type) {
     

    case GL_TRIANGLES:
	if (n == 3) {
	    gl_draw_triangle(c, &c->vertex[0], &c->vertex[1], &c->vertex[2]);
	    n = 0;
	}
	break;
  
    case GL_QUADS:
	if (n == 4) {
	    c->vertex[2].edge_flag = 0;
	    gl_draw_triangle(c, &c->vertex[0], &c->vertex[1], &c->vertex[2]);
	    c->vertex[2].edge_flag = 1;
	    c->vertex[0].edge_flag = 0;
	    gl_draw_triangle(c, &c->vertex[0], &c->vertex[2], &c->vertex[3]);
	    n = 0;
	}
	break;

    }

    c->vertex_n = n;
  
}

 
inline void GraphDrawLib::glVertex3f(float x,float y,float z) 
{
  glVertex4f(x,y,z,1);
}

inline void GraphDrawLib::glVertex3fv(float *v) 
{
  glVertex4f(v[0],v[1],v[2],1);
}

/* glNormal */

inline void GraphDrawLib::glNormal3f(float x,float y,float z)
{
  GLContext *c=gl_get_context(); 
  c->current_normal.X = x;
  c->current_normal.Y = y;
  c->current_normal.Z = z;
  c->current_normal.W = 0;
}

 

/* glColor */

inline void GraphDrawLib::glColor4f(float r,float g,float b,float a)
{
  GLContext *c=gl_get_context(); 
  
    c->current_color.X = r;
    c->current_color.Y = g;
    c->current_color.Z = b;
    c->current_color.W = a;
    c->longcurrent_color[0] = (unsigned int) (r * (ZB_POINT_RED_MAX - ZB_POINT_RED_MIN) + 
                            ZB_POINT_RED_MIN);
    c->longcurrent_color[1] = (unsigned int) (g * (ZB_POINT_GREEN_MAX - ZB_POINT_GREEN_MIN) + 
                            ZB_POINT_GREEN_MIN);
    c->longcurrent_color[2] = (unsigned int) (b * (ZB_POINT_BLUE_MAX - ZB_POINT_BLUE_MIN) + 
                            ZB_POINT_BLUE_MIN);

    if (c->color_material_enabled) {
	GLParam q[7];
	//q[0].op = OP_Material;
	q[1].i = c->current_color_material_mode;
	q[2].i = c->current_color_material_type;
	q[3].f = r;
	q[4].f = g;
	q[5].f = b;
	q[6].f = a;
	glopMaterial(c, q);
    }
}

 

inline void GraphDrawLib::glColor3f(float x,float y,float z) 
{
  glColor4f(x,y,z,1);
}

 

/* TexCoord */
inline void GraphDrawLib::glTexCoord4f(float s,float t,float r,float q)
{
    GLContext *c=gl_get_context(); 
    c->current_tex_coord.X =  s;
    c->current_tex_coord.Y =  t;
    c->current_tex_coord.Z =  r;
    c->current_tex_coord.W =  q;
}

inline void GraphDrawLib::glTexCoord2f(float s,float t)
{
  glTexCoord4f(s,t,0,1);
}

 
 
inline void GraphDrawLib::GL_EnableDisable(GLContext *c,GLParam *p)
{
  int code=p[1].i;
  int v=p[2].i;

  switch(code) {
  case GL_CULL_FACE:
    c->cull_face_enabled=v;
    break;
  case GL_LIGHTING:
    c->lighting_enabled=v;
    break;
  case GL_COLOR_MATERIAL:
    c->color_material_enabled=v;
      break;
  case GL_TEXTURE_2D:
    c->texture_2d_enabled=v;
    break;
  case GL_NORMALIZE:
    c->normalize_enabled=v;
    break;
  case GL_DEPTH_TEST:
    c->depth_test = v;
    break;
 
  default:
    if (code>=GL_LIGHT0 && code<GL_LIGHT0+MAX_LIGHTS) {
      gl_enable_disable_light(c,code - GL_LIGHT0, v);
    } 
    break;
  }
}
   

/* glEnable / glDisable */

inline void GraphDrawLib::glEnable(int cap)
{
  GLParam p[3];
  //p[0].op=OP_EnableDisable;
  p[1].i=cap; p[2].i=1;

   GLContext *c=gl_get_context(); 
   GL_EnableDisable( c, p);
   
}

inline void GraphDrawLib::glDisable(int cap)
{
  GLParam p[3];
  //p[0].op=OP_EnableDisable;
  p[1].i=cap;  p[2].i=0;
  
  GLContext *c=gl_get_context();
  GL_EnableDisable( c, p);
}

/* glBegin / glEnd */
 
inline void GraphDrawLib::glBegin(int mode)
{
   GLContext *c=gl_get_context(); 
   
   int type;
   M4 tmp;

    assert(c->in_begin == 0);

    type = mode;
    c->begin_type = type;
    c->in_begin = 1;
    c->vertex_n = 0;
    c->vertex_cnt = 0;

    if (c->matrix_model_projection_updated) {

	if (c->lighting_enabled) {
	    /* precompute inverse modelview */
	    M4::gl_M4_Inv(&tmp, c->TkGLMat[KH_ModelView].get_current_matrix());
	    M4::gl_M4_Transpose(&c->matrix_model_view_inv, &tmp);
	} else {
	    float *m = &c->matrix_model_projection.m[0][0];
	    /* precompute projection matrix */
	    M4::gl_M4_Mul(&c->matrix_model_projection,
		      c->TkGLMat[KH_PROJECTION].get_current_matrix(),
		      c->TkGLMat[KH_ModelView].get_current_matrix());
	    /* test to accelerate computation */
	    c->matrix_model_projection_no_w_transform = 0;
	    if (m[12] == 0.0 && m[13] == 0.0 && m[14] == 0.0)
		c->matrix_model_projection_no_w_transform = 1;
	}

	/* test if the texture matrix is not Identity */
	c->apply_texture_matrix = !M4::gl_M4_IsId(c->TkGLMat[KH_TEXTURE].get_current_matrix());

	c->matrix_model_projection_updated = 0;
    }
    /*  viewport */
    if (c->viewport.updated) {
	gl_eval_viewport(c);
	c->viewport.updated = 0;
    }
     
	 
	switch (c->polygon_mode_front) {
 
	default:
	    c->draw_triangle_front = gl_draw_triangle_fill;
	    break;
	}

	switch (c->polygon_mode_back) {
 
	default:
	    c->draw_triangle_back = gl_draw_triangle_fill;
	    break;
	}
     
}

inline void GraphDrawLib::glEnd(void)
{
  GLContext *c=gl_get_context();
   

    if (c->begin_type == GL_LINE_LOOP) {
	 
    } else if (c->begin_type == GL_POLYGON) {
	int i = c->vertex_cnt;
	while (i >= 3) {
	    i--;
	    gl_draw_triangle(c, &c->vertex[i], &c->vertex[0], &c->vertex[i - 1]);
	}
    }
    c->in_begin = 0;
}

/* matrix */
 

inline void GraphDrawLib::glMatrixMode(int mode)
{
  GLContext *c=gl_get_context(); 
  //==================================
   //int mode=p[1].i;
  switch(mode) {
  case GL_MODELVIEW:
    c->matrix_mode=0;
    break;
  case GL_PROJECTION:
    c->matrix_mode=1;
    break;
  case GL_TEXTURE:
    c->matrix_mode=2;
    break;
  default:
    assert(0);
  }
}

 

inline void GraphDrawLib::glLoadIdentity(void)
{
  GLContext *c=gl_get_context(); 
  M4::gl_M4_Id(c->TkGLMat[c->matrix_mode].get_current_matrix());
  gl_matrix_update(c);
}

inline void GraphDrawLib::glMultMatrixf(const float *mm)
{
   GLContext *c=gl_get_context(); 
   M4 m1,m;
   memcpy( &m1.m[0][0], mm,16*sizeof(float));
   M4::gl_M4_Transpose(&m, &m1);
  
  /*GLParam p[17];
  for(int i=0;i<16;i++) p[i+1].f = mm[i];//glRunFunc(p);
  GLParam *q; q=p+1;
  for(i=0;i<4;i++) {
    m.m[0][i]=q[0].f; m.m[1][i]=q[1].f;
    m.m[2][i]=q[2].f; m.m[3][i]=q[3].f;
    q+=4; }  */

  M4::gl_M4_MulLeft(c->TkGLMat[c->matrix_mode].get_current_matrix(),&m);

  gl_matrix_update(c);
}

inline void GraphDrawLib::glPushMatrix(void)
{
  GLContext *c=gl_get_context();  
  c->TkGLMat[c->matrix_mode].push_matrix();
  gl_matrix_update(c);
}


inline void GraphDrawLib::glPopMatrix(void)
{
   GLContext *c=gl_get_context(); 
   c->TkGLMat[c->matrix_mode].pop_matrix();
   gl_matrix_update(c);
}

inline void GraphDrawLib::glRotatef(float angle,float x,float y,float z)
{
  GLContext *c=gl_get_context(); 
  
   M4 m;
  float u[3];
//  float angle;
  int dir_code;

  angle = angle * M_PI / 180.0;
  u[0]=x;
  u[1]=y;
  u[2]=z;

  /* simple case detection */
  dir_code = ((u[0] != 0)<<2) | ((u[1] != 0)<<1) | (u[2] != 0);

  switch(dir_code) {
  case 0:
    M4::gl_M4_Id(&m);
    break;
  case 4:
    if (u[0] < 0) angle=-angle;
    M4::gl_M4_Rotate(&m,angle,0);
    break;
  case 2:
    if (u[1] < 0) angle=-angle;
    M4::gl_M4_Rotate(&m,angle,1);
    break;
  case 1:
    if (u[2] < 0) angle=-angle;
    M4::gl_M4_Rotate(&m,angle,2);
    break;
  default:
    {
      float cost, sint;

      /* normalize vector */
      float len = u[0]*u[0]+u[1]*u[1]+u[2]*u[2];
      if (len == 0.0f) return;
      len = 1.0f / sqrt(len);
      u[0] *= len;
      u[1] *= len;
      u[2] *= len;

      /* store cos and sin values */
      cost=cos(angle);
      sint=sin(angle);

      /* fill in the values */
      m.m[3][0]=m.m[3][1]=m.m[3][2]=
        m.m[0][3]=m.m[1][3]=m.m[2][3]=0.0f;
      m.m[3][3]=1.0f;

      /* do the math */
      m.m[0][0]=u[0]*u[0]+cost*(1-u[0]*u[0]);
      m.m[1][0]=u[0]*u[1]*(1-cost)-u[2]*sint;
      m.m[2][0]=u[2]*u[0]*(1-cost)+u[1]*sint;
      m.m[0][1]=u[0]*u[1]*(1-cost)+u[2]*sint;
      m.m[1][1]=u[1]*u[1]+cost*(1-u[1]*u[1]);
      m.m[2][1]=u[1]*u[2]*(1-cost)-u[0]*sint;
      m.m[0][2]=u[2]*u[0]*(1-cost)-u[1]*sint;
      m.m[1][2]=u[1]*u[2]*(1-cost)+u[0]*sint;
      m.m[2][2]=u[2]*u[2]+cost*(1-u[2]*u[2]);
    }
  }

  M4::gl_M4_MulLeft(c->TkGLMat[c->matrix_mode].get_current_matrix(),&m);

  gl_matrix_update(c);
}

inline void GraphDrawLib::glTranslatef(float x,float y,float z)
{
  GLContext *c=gl_get_context(); 
 // glRunFunc(p);
   float *m;
   M4 mm;
 // float x=p[1].f,y=p[2].f,z=p[3].f;
   mm.m[0][0] = 1; mm.m[0][1] = 0; mm.m[0][2] = 0; mm.m[0][3] = x; 
   mm.m[1][0] = 0; mm.m[1][1] = 1; mm.m[1][2] = 0; mm.m[1][3] = y;  
   mm.m[2][0] = 0; mm.m[2][1] = 0; mm.m[2][2] = 1; mm.m[2][3] = z; 
   mm.m[3][0] = 0; mm.m[3][1] = 0; mm.m[3][2] = 0; mm.m[3][3] = 1; 

   M4::gl_M4_MulLeft(c->TkGLMat[c->matrix_mode].get_current_matrix(),&mm);
 

  gl_matrix_update(c);
}

inline void GraphDrawLib::glScalef(float x,float y,float z)
{
   GLContext *c=gl_get_context(); 
   float *m;
   M4 mm;
 // float x=p[1].f,y=p[2].f,z=p[3].f;
   mm.m[0][0] = x; mm.m[0][1] = 0; mm.m[0][2] = 0; mm.m[0][3] = 0; 
   mm.m[1][0] = 0; mm.m[1][1] = y; mm.m[1][2] = 0; mm.m[1][3] = 0;  
   mm.m[2][0] = 0; mm.m[2][1] = 0; mm.m[2][2] = z; mm.m[2][3] = 0; 
   mm.m[3][0] = 0; mm.m[3][1] = 0; mm.m[3][2] = 0; mm.m[3][3] = 1; 
   M4::gl_M4_MulLeft(c->TkGLMat[c->matrix_mode].get_current_matrix(),&mm);

  gl_matrix_update(c);
}


inline void GraphDrawLib::glViewport(int x,int y,int width,int height)
{
	GLContext *c=gl_get_context(); 
   
  int  xsize_req,ysize_req;
  
 // xmin=p[1].i;
 // ymin=p[2].i;
  int xmin(x), ymin(y);
  int xsize=width;
  int ysize=height;

  /* we may need to resize the zbuffer */

  if (c->viewport.xmin != xmin ||
      c->viewport.ymin != ymin ||
      c->viewport.xsize != xsize ||
      c->viewport.ysize != ysize) {

    xsize_req=xmin+xsize;
    ysize_req=ymin+ysize;

    if (c->gl_resize_viewport && 
        c->gl_resize_viewport(c,&xsize_req,&ysize_req) != 0) {
      exit(0);//gl_fatal_error("glViewport: error while resizing display");
    }

    xsize=xsize_req-xmin;
    ysize=ysize_req-ymin;
    if (xsize <= 0 || ysize <= 0) {
    exit(0);//  gl_fatal_error("glViewport: size too small");
    }

    //tgl_trace("glViewport: %d %d %d %d\n",
     //         xmin, ymin, xsize, ysize);
    c->viewport.xmin=xmin;
    c->viewport.ymin=ymin;
    c->viewport.xsize=xsize;
    c->viewport.ysize=ysize;
    
    c->viewport.updated=1;
  }
}


inline void GraphDrawLib::glFrustum(double left,double right,double bottom,double top,
               double near,double farp)
{
  GLContext *c=gl_get_context(); 
  float *r;
  M4 m;
 
  float x,y,A,B,C,D;

  x = (2.0*near) / (right-left);
  y = (2.0*near) / (top-bottom);
  A = (right+left) / (right-left);
  B = (top+bottom) / (top-bottom);
  C = -(farp+near) / ( farp-near);
  D = -(2.0*farp*near) / (farp-near);

  r=&m.m[0][0];
  r[0]= x; r[1]=0; r[2]=A; r[3]=0;
  r[4]= 0; r[5]=y; r[6]=B; r[7]=0;
  r[8]= 0; r[9]=0; r[10]=C; r[11]=D;
  r[12]= 0; r[13]=0; r[14]=-1; r[15]=0;

  M4::gl_M4_MulLeft(c->TkGLMat[c->matrix_mode].get_current_matrix(),&m);

  gl_matrix_update(c);
}

inline void GraphDrawLib::gluPerspective( GLdouble fovy, GLdouble aspect,
		     GLdouble zNear, GLdouble zFar )
{
   GLdouble xmin, xmax, ymin, ymax;

   ymax = zNear * tan( fovy * M_PI / 360.0 );
   ymin = -ymax;

   xmin = ymin * aspect;
   xmax = ymax * aspect;

   glFrustum( xmin, xmax, ymin, ymax, zNear, zFar );
}

/* lightening */

inline void GraphDrawLib::glMaterialfv(int mode,int type,float *v)
{
  GLContext *c=gl_get_context(); 
  int i,n;
  n=4;
  GLParam p[7]; p[1].i=mode; p[2].i=type;
  for(i=0;i<4;i++) p[3+i].f=v[i];
  for(i=n;i<4;i++) p[3+i].f=0;
  

  assert(mode == GL_FRONT  || mode == GL_BACK || mode==GL_FRONT_AND_BACK);
  
  if (type == GL_SHININESS) n=1;
   
  GLMaterial *m;

  if (mode == GL_FRONT_AND_BACK) {
    p[1].i=GL_FRONT;
    glopMaterial(c,p);
    mode=GL_BACK;
  }
  if (mode == GL_FRONT) 
	  m=&c->materials[0];
  else
	  m=&c->materials[1];

  switch(type) {
  case GL_EMISSION:
    memcpy(m->emission.v, v, 4*sizeof(float));
    break;
  case GL_AMBIENT:
    memcpy(m->ambient.v,  v, 4*sizeof(float));
    break;
  case GL_DIFFUSE:
    memcpy(m->diffuse.v,  v, 4*sizeof(float));
    break;
  case GL_SPECULAR:
    memcpy(m->specular.v, v, 4*sizeof(float));
    break;
  case GL_SHININESS:
    m->shininess=v[0];
    m->shininess_i = (v[0]/128.0f)*SPECULAR_BUFFER_RESOLUTION;
    break;
  case GL_AMBIENT_AND_DIFFUSE:
      memcpy(m->diffuse.v,  v, 4*sizeof(float));
	  memcpy(m->ambient.v,  v, 4*sizeof(float));
    break;
  default:
    assert(0);
  }
}

inline void GraphDrawLib::glMaterialf(int mode,int type,float val)
{
  GLContext *c=gl_get_context(); 
  GLParam p[7];
  int i;

  //p[0].op=OP_Material;
  p[1].i=mode;
  p[2].i=type;
  p[3].f=val;
  for(i=0;i<3;i++) p[4+i].f=0;

  
  float v[4];
  v[0] = p[3].f;
  v[1] = p[4].f;
  v[2] = p[5].f;
  v[3] = p[6].f;
  //float *v=v;//&p[3].f;
 // float *v=&p[3].f;
//  int i;
  GLMaterial *m;

  if (mode == GL_FRONT_AND_BACK) {
    p[1].i=GL_FRONT;
    glopMaterial(c,p);
    mode=GL_BACK;
  }
  if (mode == GL_FRONT) m=&c->materials[0];
  else m=&c->materials[1];

  switch(type) {
  case GL_EMISSION:
    for(i=0;i<4;i++)
      m->emission.v[i]=v[i];
    break;
  case GL_AMBIENT:
    for(i=0;i<4;i++)
      m->ambient.v[i]=v[i];
    break;
  case GL_DIFFUSE:
    for(i=0;i<4;i++)
      m->diffuse.v[i]=v[i];
    break;
  case GL_SPECULAR:
    for(i=0;i<4;i++)
      m->specular.v[i]=v[i];
    break;
  case GL_SHININESS:
    m->shininess=v[0];
    m->shininess_i = (v[0]/128.0f)*SPECULAR_BUFFER_RESOLUTION;
    break;
  case GL_AMBIENT_AND_DIFFUSE:
    for(i=0;i<4;i++)
      m->diffuse.v[i]=v[i];
    for(i=0;i<4;i++)
      m->ambient.v[i]=v[i];
    break;
  default:
    assert(0);
  }
}

/*
void glColorMaterial(int mode,int type)
{
  GLContext *c=gl_get_context(); 
  c->current_color_material_mode=mode;
  c->current_color_material_type=type;
}*/

inline void GraphDrawLib::glLightfv(int light,int type,float *val)
{ GLContext *c=gl_get_context(); 
  GLParam p[7];
  int i;

  //p[0].op=OP_Light;
  p[1].i=light;
  p[2].i=type;
  /* TODO: 3 composants ? */
  for(i=0;i<4;i++) p[3+i].f=val[i];

 
  V4 v;
  GLLight *l;
//  int i;
  
  assert(light >= GL_LIGHT0 && light < GL_LIGHT0+MAX_LIGHTS );

  l=&c->lights[light-GL_LIGHT0];

  for(i=0;i<4;i++) v.v[i]= val[i];//p[3+i].f;

  switch(type) {
  case GL_AMBIENT:
    l->ambient=v;
    break;
  case GL_DIFFUSE:
    l->diffuse=v;
    break;
  case GL_SPECULAR:
    l->specular=v;
    break;
  case GL_POSITION:
    {
      V4 pos;
      M4::gl_M4_MulV4(&pos,c->TkGLMat[KH_ModelView].get_current_matrix(),&v);

      l->position=pos;

      if (l->position.v[3] == 0) {
        l->norm_position.X=pos.X;
        l->norm_position.Y=pos.Y;
        l->norm_position.Z=pos.Z;
        
        gl_V3_Norm(&l->norm_position);
      }
    }
    break;
  case GL_SPOT_DIRECTION:
    for(i=0;i<3;i++) {
      l->spot_direction.v[i]=v.v[i];
      l->norm_spot_direction.v[i]=v.v[i];
    }
    gl_V3_Norm(&l->norm_spot_direction);
    break;
  case GL_SPOT_EXPONENT:
    l->spot_exponent=v.v[0];
    break;
  case GL_SPOT_CUTOFF:
    {
      float a=v.v[0];
      assert(a == 180 || (a>=0 && a<=90));
      l->spot_cutoff=a;
      if (a != 180) l->cos_spot_cutoff=cos(a * M_PI / 180.0);
    }
    break;
  case GL_CONSTANT_ATTENUATION:
    l->attenuation[0]=v.v[0];
    break;
  case GL_LINEAR_ATTENUATION:
    l->attenuation[1]=v.v[0];
    break;
  case GL_QUADRATIC_ATTENUATION:
    l->attenuation[2]=v.v[0];
    break;
  default:
    assert(0);
  }
}


 
/* textures */
inline void GraphDrawLib::glTexImage2D( int target, int level, int components,
                   int width, int height, int border,
                   int format, int type, void *pixels)
{
  GLContext *c=gl_get_context(); 
  
 
  GLImage *im;
  unsigned char *pixels1;
  int do_free;

  if (!(target == GL_TEXTURE_2D && level == 0 && components == 3 && 
        border == 0 && format == GL_RGB &&
        type == GL_UNSIGNED_BYTE)) {
    exit(0);//gl_fatal_error("glTexImage2D: combinaison of parameters not handled");
  }
  
  do_free=0;
  if (width != 256 || height != 256) {
    pixels1 = (unsigned char*)gl_malloc(256 * 256 * 3);
    /* no interpolation is done here to respect the original image aliasing ! */
    gl_resizeImageNoInterpolate(pixels1,256,256,(unsigned char*)pixels,width,height);
    do_free=1;
    width=256;
    height=256;
  } else {
    pixels1=(unsigned char*)pixels;
  }

  im=&c->current_texture->images[level];
  im->xsize=width;
  im->ysize=height;
  if (im->pixmap!=NULL) gl_free(im->pixmap);
//#if TGL_FEATURE_RENDER_BITS == 24 
  im->pixmap=gl_malloc(width*height*3);
  if(im->pixmap) {
      memcpy(im->pixmap,pixels1,width*height*3);
  }
 
  if (do_free) gl_free(pixels1);
}

inline GLTexture * GraphDrawLib::alloc_texture(GLContext *c,int h)
{
  GLTexture *t,**ht;
  
  t= (GLTexture *)gl_zalloc(sizeof(GLTexture));

  ht=&c->shared_state.texture_hash_table[h % TEXTURE_HASH_TABLE_SIZE];

  t->next=*ht;
  t->prev=NULL;
  if (t->next != NULL) t->next->prev=t;
  *ht=t;

  t->handle=h;
  
  return t;
}
 
inline GLTexture * GraphDrawLib::find_texture(GLContext *c,int h)
{
  GLTexture *t;

  t=c->shared_state.texture_hash_table[h % TEXTURE_HASH_TABLE_SIZE];
  while (t!=NULL) {
    if (t->handle == h) return t;
    t=t->next;
  }
  return NULL;
}

inline void GraphDrawLib::glBindTexture(int target,int texture)
{
  GLContext *c=gl_get_context(); 
  GLParam p[3];

 
  GLTexture *t;

  assert(target == GL_TEXTURE_2D && texture >= 0);

  t=find_texture(c,texture);
  if (t==NULL) {
    t=alloc_texture(c,texture);
  }
  c->current_texture=t;
}

