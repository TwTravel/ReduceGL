/*
 * The following constants come from Mesa
 */
#ifndef GL_H
#define GL_H
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <map>
#define GL_VERSION_1_1 1
#define M_PI 3.141592653

#include "c24bitmap.h"
#include "c256bitmap.h"

#include "zmath.h"
#include "zbuffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

enum {
	/* Boolean values */
	GL_FALSE			= 0,
	GL_TRUE				= 1,
	/* Data types */
	GL_BYTE				= 0x1400,
	GL_UNSIGNED_BYTE	= 0x1401,
	GL_SHORT			= 0x1402,
	GL_UNSIGNED_SHORT	= 0x1403,
	GL_INT				= 0x1404,
	GL_UNSIGNED_INT		= 0x1405,
	GL_FLOAT			= 0x1406,
	GL_DOUBLE			= 0x140A,
	
	/* Primitives */
	GL_LINES			= 0x0001,
	GL_POINTS			= 0x0000,
	GL_LINE_STRIP			= 0x0003,
	GL_LINE_LOOP			= 0x0002,
	GL_TRIANGLES			= 0x0004,
	GL_TRIANGLE_STRIP		= 0x0005,
	GL_TRIANGLE_FAN			= 0x0006,
	GL_QUADS			= 0x0007,
	GL_QUAD_STRIP			= 0x0008,
	GL_POLYGON			= 0x0009,
	GL_EDGE_FLAG			= 0x0B43,

	/* Matrix Mode */
	GL_MATRIX_MODE		 = 0x0BA0,


	/* Points */
	GL_POINT_SMOOTH			= 0x0B10,
	GL_POINT_SIZE			= 0x0B11,
	GL_POINT_SIZE_GRANULARITY 	= 0x0B13,
	GL_POINT_SIZE_RANGE		= 0x0B12,

	/* Lines */
	GL_LINE_SMOOTH			= 0x0B20,
	GL_LINE_STIPPLE			= 0x0B24,
	GL_LINE_STIPPLE_PATTERN		= 0x0B25,
	GL_LINE_STIPPLE_REPEAT		= 0x0B26,
	GL_LINE_WIDTH			= 0x0B21,
	GL_LINE_WIDTH_GRANULARITY	= 0x0B23,
	GL_LINE_WIDTH_RANGE		= 0x0B22,

	/* Polygons */
	GL_POINT			= 0x1B00,
	GL_LINE				= 0x1B01,
	GL_FILL				= 0x1B02,
	GL_CCW				= 0x0901,
	GL_CW				= 0x0900,
	GL_FRONT			= 0x0404,
	GL_BACK				= 0x0405,
	GL_CULL_FACE			= 0x0B44,
	GL_CULL_FACE_MODE		= 0x0B45,
	GL_POLYGON_SMOOTH		= 0x0B41,
	GL_POLYGON_STIPPLE		= 0x0B42,
	GL_FRONT_FACE			= 0x0B46,
	GL_POLYGON_MODE			= 0x0B40,
	
	//Depth buffer 
	GL_DEPTH_TEST			= 0x0B71,

	/* Lighting */
	GL_LIGHTING			= 0x0B50,
	GL_LIGHT0			= 0x4000,
	GL_LIGHT1			= 0x4001,
	GL_LIGHT2			= 0x4002,
	GL_LIGHT3			= 0x4003,
	GL_LIGHT4			= 0x4004,
	GL_LIGHT5			= 0x4005,
	GL_LIGHT6			= 0x4006,
	GL_LIGHT7			= 0x4007,
	GL_SPOT_EXPONENT		= 0x1205,
	GL_SPOT_CUTOFF			= 0x1206,
	GL_CONSTANT_ATTENUATION		= 0x1207,
	GL_LINEAR_ATTENUATION		= 0x1208,
	GL_QUADRATIC_ATTENUATION	= 0x1209,
	GL_AMBIENT			= 0x1200,
	GL_DIFFUSE			= 0x1201,
	GL_SPECULAR			= 0x1202,
	GL_SHININESS			= 0x1601,
	GL_EMISSION			= 0x1600,
	GL_POSITION			= 0x1203,
	GL_SPOT_DIRECTION		= 0x1204,
	GL_AMBIENT_AND_DIFFUSE		= 0x1602,
	GL_COLOR_INDEXES		= 0x1603,
	GL_LIGHT_MODEL_TWO_SIDE		= 0x0B52,
	GL_LIGHT_MODEL_LOCAL_VIEWER	= 0x0B51,
	GL_LIGHT_MODEL_AMBIENT		= 0x0B53,
	GL_FRONT_AND_BACK		= 0x0408,
	GL_SHADE_MODEL			= 0x0B54,
	GL_FLAT				= 0x1D00,
	GL_SMOOTH			= 0x1D01,
	GL_COLOR_MATERIAL		= 0x0B57,
	GL_COLOR_MATERIAL_FACE		= 0x0B55,
	GL_COLOR_MATERIAL_PARAMETER	= 0x0B56,
	GL_NORMALIZE			= 0x0BA1,

	/* Render Mode */
	GL_FEEDBACK			= 0x1C01,
	GL_RENDER			= 0x1C00,
	GL_SELECT			= 0x1C02,
	
	GL_RGB				= 0x1907,
	GL_RGBA				= 0x1908,
	 

	/* Implementation limits */
	GL_MAX_LIST_NESTING		= 0x0B31,
	GL_MAX_ATTRIB_STACK_DEPTH	= 0x0D35,
	GL_MAX_MODELVIEW_STACK_DEPTH	= 0x0D36,
	GL_MAX_NAME_STACK_DEPTH		= 0x0D37,
	GL_MAX_PROJECTION_STACK_DEPTH	= 0x0D38,
	GL_MAX_TEXTURE_STACK_DEPTH	= 0x0D39,
	GL_MAX_EVAL_ORDER		= 0x0D30,
	GL_MAX_LIGHTS			= 0x0D31,
	GL_MAX_CLIP_PLANES		= 0x0D32,
	GL_MAX_TEXTURE_SIZE		= 0x0D33,
	GL_MAX_PIXEL_MAP_TABLE		= 0x0D34,
	GL_MAX_VIEWPORT_DIMS		= 0x0D3A,
	GL_MAX_CLIENT_ATTRIB_STACK_DEPTH= 0x0D3B,

 
	/* Texture mapping */
	GL_TEXTURE_ENV			= 0x2300,
	GL_TEXTURE_ENV_MODE		= 0x2200,
	GL_TEXTURE_1D			= 0x0DE0,
	GL_TEXTURE_2D			= 0x0DE1

};
 

/* some types */
typedef int		GLenum;
typedef void		GLvoid;
typedef unsigned char	GLboolean;
typedef signed char	GLbyte;		/* 1-byte signed */
typedef short		GLshort;	/* 2-byte signed */
typedef int		GLint;		/* 4-byte signed */
typedef unsigned char	GLubyte;	/* 1-byte unsigned */
typedef unsigned short	GLushort;	/* 2-byte unsigned */
typedef unsigned int	GLuint;		/* 4-byte unsigned */
typedef float		GLfloat;	/* single precision float */
typedef double		GLdouble;	/* double precision float */
typedef int GLsizei;
//==================================================

//==================================================
/* initially # of allocated GLVertexes (will grow when necessary) */
#define POLYGON_MAX_VERTEX 16

/* Max # of specular light pow buffers */
#define MAX_SPECULAR_BUFFERS 8
/* # of entries in specular buffer */
#define SPECULAR_BUFFER_SIZE 1024
/* specular buffer granularity */
#define SPECULAR_BUFFER_RESOLUTION 1024


#define MAX_MODELVIEW_STACK_DEPTH  32
#define MAX_PROJECTION_STACK_DEPTH 8
#define MAX_TEXTURE_STACK_DEPTH    8
#define MAX_NAME_STACK_DEPTH       64
#define MAX_TEXTURE_LEVELS         11
#define MAX_LIGHTS                 16

#define VERTEX_HASH_SIZE 1031

#define MAX_DISPLAY_LISTS 1024
#define OP_BUFFER_MAX_SIZE 512

#define TGL_OFFSET_FILL    0x1
#define TGL_OFFSET_LINE    0x2
#define TGL_OFFSET_POINT   0x4
//==================================================
//struct GLSpecBuf;
class GLContext;
 extern GLContext  gl_ctx;
class GLSpecBuf {
public:
  int shininess_i;
  int last_used;
  float buf[SPECULAR_BUFFER_SIZE+1];
  GLSpecBuf *next;

#define MAX_SPECULAR_BUFFERS 8    // # of entries in specular buffer
#define SPECULAR_BUFFER_SIZE 1024 // specular buffer granularity 
#define SPECULAR_BUFFER_RESOLUTION 1024

void  calc_buf( const float shininess);
};// GLSpecBuf;

inline void GLSpecBuf::calc_buf(const float shininess)
{
  GLSpecBuf *buf = this; 
  int i;
  float val, inc;
  val = 0.0f;
  inc = 1.0f/SPECULAR_BUFFER_SIZE;
  for (i = 0; i <= SPECULAR_BUFFER_SIZE; i++) {
    buf->buf[i] = pow(val, shininess);
    val += inc;
  }
}
typedef struct GLLight {
  V4 ambient;
  V4 diffuse;
  V4 specular;
  V4 position;	
  V3 spot_direction;
  float spot_exponent;
  float spot_cutoff;
  float attenuation[3];
  /* precomputed values */
  float cos_spot_cutoff;
  V3 norm_spot_direction;
  V3 norm_position;
  /* we use a linked list to know which are the enabled lights */
  int enabled;
  struct GLLight *next,*prev;
} GLLight;

typedef struct GLMaterial {
  V4 emission;
  V4 ambient;
  V4 diffuse;
  V4 specular;
  float shininess;

  /* computed values */
  int shininess_i;
  int do_specular;  
} GLMaterial;


typedef struct GLViewport {
  int xmin,ymin,xsize,ysize;
  V3 scale;
  V3 trans;
  int updated;
} GLViewport;

typedef union {
  int op;
  float f;
  int i;
  unsigned int ui;
  void *p;
} GLParam;

typedef struct GLParamBuffer {
  GLParam ops[OP_BUFFER_MAX_SIZE];
  struct GLParamBuffer *next;
} GLParamBuffer;

typedef struct GLList {
  GLParamBuffer *first_op_buffer;
  /* TODO: extensions for an hash table or a better allocating scheme */
} GLList;

typedef struct GLVertex {
  int edge_flag;
  V3 normal;
  V4 coord;
  V4 tex_coord;
  V4 color;
  
  /* computed values */
  V4 ec;                /* eye coordinates */
  V4 pc;                /* coordinates in the normalized volume */
  int clip_code;        /* clip code */
  ZBufferPoint zp;      /* integer coordinates for the rasterization */
} GLVertex;

typedef struct GLImage {
  //void *pixmap;
  vector<unsigned char>  pixmap;
  int xsize,ysize;
} GLImage;


#define TEXTURE_HASH_TABLE_SIZE 256

class GLTexture {
public:
  GLTexture(){};
  GLImage images[MAX_TEXTURE_LEVELS];
  int handle;
  struct GLTexture *next,*prev;
} ;//GLTexture;

 

//###################################################
 

 inline GLContext*gl_get_context(void)
{
  return &gl_ctx;
}


 void inline gl_free(void *p)
{
    free(p);
}

void inline *gl_malloc(int size)
{
	void * pt = malloc(size);
	memset(pt, 0, size);
    return pt;//malloc(size);
}

void inline *gl_zalloc(int size)
{
    return calloc(1, size);
}

//====================================================
//struct GLContext;

typedef void (*gl_draw_triangle_func)( GLContext *c,
                                      GLVertex *p0,GLVertex *p1,GLVertex *p2);

/* display context */
///###################################################################
///###################################################################
enum GDMatModel{GL_MODELVIEW, GL_PROJECTION	, GL_TEXTURE };
enum GDMatrixTye{KH_ModelView,KH_PROJECTION ,KH_TEXTURE};
 
//MatrixStack TkGLMat[3];
class MatrixStack
{

public:
  void set_stack_size(int size);
  vector<M4> stackbuff;
  void push_matrix();
  void pop_matrix();
  int  stack_pos;
  int matrix_stack_depth_max;
  M4*get_current_matrix();
};

void inline MatrixStack::pop_matrix()
{
	if(stack_pos>0)
	  stack_pos --;
}

void inline MatrixStack::push_matrix(void)
{
  stack_pos ++;
  M4::gl_M4_Move(&stackbuff[stack_pos], &stackbuff[stack_pos-1]);  
}

  inline  M4 * MatrixStack::get_current_matrix()
{
  return &stackbuff[stack_pos];
}

void  inline MatrixStack::set_stack_size(int size)
{
  stackbuff.resize(size);
  stack_pos = 0;
}
//#############################################################
//#############################################################
class GLContext {
public:
  /* Z buffer */
  ZBuffer zb;
  int image_w,  image_h;
  /* lights */
  GLLight lights[MAX_LIGHTS];
  GLLight *first_light;
  V4 ambient_light_model;
  int local_light_model;
  int lighting_enabled;
  int light_model_two_side;

  /* materials */
  GLMaterial materials[2];
  int color_material_enabled;
  int current_color_material_mode;
  int current_color_material_type;

  /* textures */
  GLTexture *current_texture;
  int texture_2d_enabled;

   

  /* current list */
  GLParamBuffer *current_op_buffer;
  int current_op_buffer_index;
  int exec_flag,compile_flag,print_flag;

  /* matrix */

  int matrix_mode;

  MatrixStack TkGLMat[3];
 

  M4 matrix_model_view_inv;
  M4 matrix_model_projection;
  int matrix_model_projection_updated;
  int matrix_model_projection_no_w_transform; 
  int apply_texture_matrix;

  /* viewport */
  GLViewport viewport;

  /* current state */
  int polygon_mode_back;
  int polygon_mode_front;

  int current_front_face;
  int current_shade_model;
  int current_cull_face;
  int cull_face_enabled;
  int normalize_enabled;
  gl_draw_triangle_func draw_triangle_front,draw_triangle_back;

  int render_mode;

  /* names */
  unsigned int name_stack[MAX_NAME_STACK_DEPTH];
  int name_stack_size;

  /* clear */
  float clear_depth;
  V4 clear_color;

  /* current vertex state */
  V4 current_color;
  unsigned int longcurrent_color[3]; /* precomputed integer color */
  V4 current_normal;
  V4 current_tex_coord;
  int current_edge_flag;

  /* glBegin / glEnd */
  int in_begin;
  int begin_type;
  int vertex_n,vertex_cnt;
  int vertex_max;
  GLVertex *vertex;
 
 
  /* specular buffer. could probably be shared between contexts, 
    but that wouldn't be 100% thread safe */
  GLSpecBuf *specbuf_first;
  int specbuf_used_counter;
  int specbuf_num_buffers;

  inline  GLSpecBuf *  specbuf_get_buffer(GLContext *c, const int shininess_i, 
                   const float shininess);
  /* opaque structure for user's use */
 // void *opaque;
  /* resize viewport function */
  int (*gl_resize_viewport)(GLContext *c,int *xsize,int *ysize);

  /* depth test */
  int depth_test;
  void inline glXSaveRenderImg( char* picture);
  inline void  glViewport(int x,int y,int width,int height);
  inline GLTexture *  find_texture(GLContext *c,int h);
  void inline  glInit(int xsize,int ysize);
  inline void glMatrixMode(int mode);
  inline void  GLContext::glInitTextures(GLContext *c);
  inline void  glLoadIdentity(void);

  map<int, GLTexture> glTextureHashTable;
};// GLContext;

 
 
inline void GLContext::glLoadIdentity(void)
{
  GLContext *c =  gl_get_context(); 
  M4::gl_M4_Id(c->TkGLMat[c->matrix_mode].get_current_matrix());
  c->matrix_model_projection_updated=(c->matrix_mode<=1);
  //gl_matrix_update(c);
}
inline void  GLContext::glInitTextures(GLContext *c)
{
  /* textures */

  c->texture_2d_enabled=0;
  c->current_texture=find_texture(c,0);
}

inline void GLContext::glMatrixMode(int mode)
{
  GLContext *c = gl_get_context(); 
  c->matrix_mode = mode;
}

void inline GLContext::glInit(int xsize,int ysize)
{
  //ZBuffer *zbuffer=(ZBuffer *)zbuffer1;
  GLContext *c;
  GLViewport *v;
  int i;

  //c= ;//(GLContext *)gl_zalloc(sizeof(GLContext));
   c =&gl_ctx;

   c->zb.ZB_open(xsize, ysize, 0,0,NULL,NULL,NULL);
  //c->zb=zbuffer;

  /* allocate GLVertex array */
  c->vertex_max = POLYGON_MAX_VERTEX;
  c->vertex = (GLVertex *)gl_malloc(POLYGON_MAX_VERTEX*sizeof(GLVertex));
  
  /* viewport */
  v=&c->viewport;
  v->xmin=0;
  v->ymin=0;
  v->xsize= xsize;
  v->ysize= ysize;
  v->updated=1;

  

  /* lists */
  c->exec_flag=1;
  c->compile_flag=0;
  c->print_flag=0;
  c->in_begin=0;

  /* lights */
  for(i=0;i<MAX_LIGHTS;i++) {
    GLLight *l=&c->lights[i];
    l->ambient=gl_V4_New(0,0,0,1);
    l->diffuse=gl_V4_New(1,1,1,1);
    l->specular=gl_V4_New(1,1,1,1);
    l->position=gl_V4_New(0,0,1,0);
    l->norm_position=gl_V3_New(0,0,1);
    l->spot_direction=gl_V3_New(0,0,-1);
    l->norm_spot_direction=gl_V3_New(0,0,-1);
    l->spot_exponent=0;
    l->spot_cutoff=180;
    l->attenuation[0]=1;
    l->attenuation[1]=0;
    l->attenuation[2]=0;
    l->enabled=0;
  }
  c->first_light=NULL;
  c->ambient_light_model=gl_V4_New(0.2,0.2,0.2,1);
  c->local_light_model=0;
  c->lighting_enabled=0;
  c->light_model_two_side = 0;

  /* default materials */
  for(i=0;i<2;i++) {
    GLMaterial *m=&c->materials[i];
    m->emission=gl_V4_New(0,0,0,1);
    m->ambient=gl_V4_New(0.2,0.2,0.2,1);
    m->diffuse=gl_V4_New(0.8,0.8,0.8,1);
    m->specular=gl_V4_New(0,0,0,1);
    m->shininess=0;
  }
  c->current_color_material_mode=GL_FRONT_AND_BACK;
  c->current_color_material_type=GL_AMBIENT_AND_DIFFUSE;
  c->color_material_enabled=0;

  /* textures */
  glInitTextures(c);

  /* default state */
  c->current_color.X=1.0;
  c->current_color.Y=1.0;
  c->current_color.Z=1.0;
  c->current_color.W=1.0;
  c->longcurrent_color[0] = 65535;
  c->longcurrent_color[1] = 65535;
  c->longcurrent_color[2] = 65535;

  c->current_normal.X=1.0;
  c->current_normal.Y=0.0;
  c->current_normal.Z=0.0;
  c->current_normal.W=0.0;

  c->current_edge_flag=1;
  
  c->current_tex_coord.X=0;
  c->current_tex_coord.Y=0;
  c->current_tex_coord.Z=0;
  c->current_tex_coord.W=1;

  c->polygon_mode_front=GL_FILL;
  c->polygon_mode_back=GL_FILL;

  c->current_front_face=0; /* 0 = GL_CCW  1 = GL_CW */
  c->current_cull_face=GL_BACK;
  c->current_shade_model=GL_SMOOTH;
  c->cull_face_enabled=0;
  
  /* clear */
  c->clear_color.v[0]=0;
  c->clear_color.v[1]=0;
  c->clear_color.v[2]=0;
  c->clear_color.v[3]=0;
  c->clear_depth=0;

  

  /* matrix */
  c->matrix_mode=0;
  
  c->TkGLMat[0].matrix_stack_depth_max = MAX_MODELVIEW_STACK_DEPTH;
  c->TkGLMat[1].matrix_stack_depth_max = MAX_PROJECTION_STACK_DEPTH;
  c->TkGLMat[2].matrix_stack_depth_max = MAX_TEXTURE_STACK_DEPTH;

  
 
  c->TkGLMat[KH_ModelView].set_stack_size(MAX_MODELVIEW_STACK_DEPTH); 
  c->TkGLMat[KH_PROJECTION].set_stack_size(MAX_PROJECTION_STACK_DEPTH);
  c->TkGLMat[KH_TEXTURE].set_stack_size(MAX_TEXTURE_STACK_DEPTH);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  c->matrix_model_projection_updated=1;

  
  
  /* clear the resize callback function pointer */
  c->gl_resize_viewport = NULL;
  
  /* specular buffer */
  c->specbuf_first = NULL;
  c->specbuf_used_counter = 0;
  c->specbuf_num_buffers = 0;

  /* depth test */
  c->depth_test = 0;
}

inline GLTexture * GLContext::find_texture(GLContext *c,int h)
{  GLTexture *t;
   c = gl_get_context(); 
   GLTexture temp;
   //map<int, GLTexture> KK;
   //KK[h] =temp;
   if( c->glTextureHashTable.find(h) != c->glTextureHashTable.end())
     t = &c->glTextureHashTable[h];
  else
  {  
     c->glTextureHashTable[h] = temp;
	 t = &c->glTextureHashTable[h]; 
  }
  return t;
  
}

inline void GLContext::glViewport(int x,int y,int width,int height)
{
	GLContext *c=this; 
   
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
void inline GLContext::glXSaveRenderImg(char* picture )
{
  GLContext *gl_context;

  gl_context=this;
 

  C24BitMap  CPic;
  CPic.FormatF(gl_context->image_w, gl_context->image_h);
  ZBuffer * zb =  &gl_context->zb;
  for(int i=0;i< gl_context->image_h ;i++)
     {
      char* ptr = (char*)zb->pbuf;
      ptr = &ptr[zb->linesize*i]; 
      for(int j=0; j<gl_context->image_w;j++)
      {
        C24PixVal Pix = get_pix_color(CPic, j, i);
		//ptr++;
        *Pix.r = *ptr; ptr++;      
        *Pix.g = *ptr; ptr++;
		*Pix.b = *ptr; ptr++;  		
      }
     }
  CPic.Save(picture);
   
  /* for non 16 bits visuals, a conversion is required */
  
}
 



inline  GLSpecBuf * GLContext::specbuf_get_buffer(GLContext *c, const int shininess_i, 
                   const float shininess)
{
  GLSpecBuf *found, *oldest;
  found = oldest = c->specbuf_first;
  while (found && found->shininess_i != shininess_i) {
    if (found->last_used < oldest->last_used) {
      oldest = found;
    }
    found = found->next; 
  }
  if (found) { // hey, found one! 
    found->last_used = c->specbuf_used_counter++;
    return found;
  }
  if (oldest == NULL || c->specbuf_num_buffers < MAX_SPECULAR_BUFFERS) {
    // create new buffer 
    GLSpecBuf *buf = (GLSpecBuf *)gl_malloc(sizeof(GLSpecBuf));
    if (!buf) 
		exit(0);
		//gl_fatal_error("could not allocate specular buffer");
    c->specbuf_num_buffers++;
    buf->next = c->specbuf_first;
    c->specbuf_first = buf;
    buf->last_used = c->specbuf_used_counter++;
    buf->shininess_i = shininess_i;
    buf->calc_buf( shininess);
    return buf;     
  }
  // overwrite the lru buffer  
  // tgl_trace("overwriting spec buffer :(\n");
  oldest->shininess_i = shininess_i;
  oldest->last_used = c->specbuf_used_counter++;
  oldest->calc_buf( shininess);
  return oldest;
}/**/

void gl_transform_to_viewport(GLContext *c,GLVertex *v);
void gl_vertex_transform(GLContext * c, GLVertex * v);
//================================================================================================
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

inline void glBindTexture(int target,int texture);
void inline gl_draw_triangle_fill(GLContext *c,
                           GLVertex *p0,GLVertex *p1,GLVertex *p2);
void inline  gl_draw_triangle(GLContext *c,
                      GLVertex *p0,GLVertex *p1,GLVertex *p2);
inline void GraphDrawLib::gl_draw_triangle_clip(GLContext *c,
                                  GLVertex *p0,GLVertex *p1,GLVertex *p2,int clip_bit);

void inline gl_enable_disable_light(GLContext *c,int light,int v);
void inline gl_shade_vertex(GLContext *c,GLVertex *v);
inline void  gl_resizeImageNoInterpolate(unsigned char *dest,int xsize_dest,int ysize_dest,
                                 unsigned char *src,int xsize_src,int ysize_src);
void inline glInit(int xsize,int ysize);
void inline glClose(void);

inline  void  glDeleteTextures(int n, const unsigned int *textures);
inline  void  glGenTextures(int n, unsigned int *textures);
inline  void  glInitTextures(GLContext *c);
inline  void  free_texture(GLContext *c,int h);
//inline GLTexture *  alloc_texture(GLContext *c,int h);
//inline GLTexture *  find_texture(GLContext *c,int h);
inline void gluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx,
	  GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy,
	  GLdouble upz);
};

 void inline  __gluMakeIdentityf(GLfloat m[16])
{
    m[0+4*0] = 1; m[0+4*1] = 0; m[0+4*2] = 0; m[0+4*3] = 0;
    m[1+4*0] = 0; m[1+4*1] = 1; m[1+4*2] = 0; m[1+4*3] = 0;
    m[2+4*0] = 0; m[2+4*1] = 0; m[2+4*2] = 1; m[2+4*3] = 0;
    m[3+4*0] = 0; m[3+4*1] = 0; m[3+4*2] = 0; m[3+4*3] = 1;
}

 

#define __glPi 3.14159265358979323846


 
 
  void inline normalize(float v[3])
{
    float r;

    r = sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
    if (r == 0.0) return;

    v[0] /= r;
    v[1] /= r;
    v[2] /= r;
}

 void inline cross(float v1[3], float v2[3], float result[3])
{
    result[0] = v1[1]*v2[2] - v1[2]*v2[1];
    result[1] = v1[2]*v2[0] - v1[0]*v2[2];
    result[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

inline void GraphDrawLib::  
gluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx,
	  GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy,
	  GLdouble upz)
{
    float forward[3], side[3], up[3];
    GLfloat m[4][4];

    forward[0] = centerx - eyex;
    forward[1] = centery - eyey;
    forward[2] = centerz - eyez;

    up[0] = upx;
    up[1] = upy;
    up[2] = upz;

    normalize(forward);

    /* Side = forward x up */
    cross(forward, up, side);
    normalize(side);

    /* Recompute up as: up = side x forward */
    cross(side, forward, up);

    __gluMakeIdentityf(&m[0][0]);
    m[0][0] = side[0];
    m[1][0] = side[1];
    m[2][0] = side[2];

    m[0][1] = up[0];
    m[1][1] = up[1];
    m[2][1] = up[2];

    m[0][2] = -forward[0];
    m[1][2] = -forward[1];
    m[2][2] = -forward[2];

    glMultMatrixf((const float *)&m[0][0]);
    glTranslatef(-eyex, -eyey, -eyez);
}




 

void inline GraphDrawLib::glClose(void)
{
  GLContext *c=gl_get_context();
  
}

void inline ZB_fillTriangleMappingPerspective(ZBuffer *zb,
                            ZBufferPoint *p0,ZBufferPoint *p1,ZBufferPoint *p2);
void inline ZB_fillTriangleSmooth(ZBuffer *zb,
			   ZBufferPoint *p0,ZBufferPoint *p1,ZBufferPoint *p2);

void inline GraphDrawLib::gl_draw_triangle_fill(GLContext *c,
                           GLVertex *p0,GLVertex *p1,GLVertex *p2)
{
 
    
  if (c->texture_2d_enabled) {
 
    c->zb.ZB_setTexture((PIXEL *)(&c->current_texture->images[0].pixmap[0]));
    ZB_fillTriangleMappingPerspective(&c->zb,&p0->zp,&p1->zp,&p2->zp);
  } else if (c->current_shade_model == GL_SMOOTH) {
    ZB_fillTriangleSmooth(&c->zb,&p0->zp,&p1->zp,&p2->zp);
  } 
}
 

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
  GLContext *c = gl_get_context(); 
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

 void inline glopMaterial(GLContext *c,GLParam *p);

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
  c->matrix_mode = mode;
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
  //if (im->pixmap!=NULL) gl_free(im->pixmap);
//#if TGL_FEATURE_RENDER_BITS == 24 
  //im->pixmap=gl_malloc(width*height*3);
  im->pixmap.resize(width*height*3);
  
  memcpy(&im->pixmap[0],pixels1,width*height*3);
 
  if (do_free) gl_free(pixels1);
}

 
 


inline void GraphDrawLib::glBindTexture(int target,int texture)
{
  GLContext *c=gl_get_context(); 
  GLParam p[3];
  GLTexture *t;

  assert(target == GL_TEXTURE_2D && texture >= 0);

  t = c->find_texture(c,texture);
  c->current_texture=t;
}

//###################################################################################
/* fill triangle profile */
/* #define PROFILE */

#define CLIP_XMIN   (1<<0)
#define CLIP_XMAX   (1<<1)
#define CLIP_YMIN   (1<<2)
#define CLIP_YMAX   (1<<3)
#define CLIP_ZMIN   (1<<4)
#define CLIP_ZMAX   (1<<5)

/* this clip epsilon is needed to avoid some rounding errors after
   several clipping stages */

#define CLIP_EPSILON (1E-5)

static inline int gl_clipcode(float x,float y,float z,float w1)
{
  float w;

  w=w1 * (1.0 + CLIP_EPSILON);
  return (x<-w) |
    ((x>w)<<1) |
    ((y<-w)<<2) |
    ((y>w)<<3) |
    ((z<-w)<<4) | 
    ((z>w)<<5) ;
}

void inline gl_transform_to_viewport(GLContext *c,GLVertex *v)
{
  float winv;

  /* coordinates */
  winv=1.0/v->pc.W;
  v->zp.x= (int) ( v->pc.X * winv * c->viewport.scale.X 
                   + c->viewport.trans.X );
  v->zp.y= (int) ( v->pc.Y * winv * c->viewport.scale.Y 
                   + c->viewport.trans.Y );
  v->zp.z= (int) ( v->pc.Z * winv * c->viewport.scale.Z 
                   + c->viewport.trans.Z );
  /* color */
  if (c->lighting_enabled) {
      v->zp.r=(int)(v->color.v[0] * (ZB_POINT_RED_MAX - ZB_POINT_RED_MIN) 
                    + ZB_POINT_RED_MIN);
      v->zp.g=(int)(v->color.v[1] * (ZB_POINT_GREEN_MAX - ZB_POINT_GREEN_MIN) 
                    + ZB_POINT_GREEN_MIN);
      v->zp.b=(int)(v->color.v[2] * (ZB_POINT_BLUE_MAX - ZB_POINT_BLUE_MIN) 
                    + ZB_POINT_BLUE_MIN);
  } else {
      /* no need to convert to integer if no lighting : take current color */
      v->zp.r = c->longcurrent_color[0];
      v->zp.g = c->longcurrent_color[1];
      v->zp.b = c->longcurrent_color[2];
  }
  
  /* texture */

  if (c->texture_2d_enabled) {
    v->zp.s=(int)(v->tex_coord.X * (ZB_POINT_S_MAX - ZB_POINT_S_MIN) 
                  + ZB_POINT_S_MIN);
    v->zp.t=(int)(v->tex_coord.Y * (ZB_POINT_T_MAX - ZB_POINT_T_MIN) 
                  + ZB_POINT_T_MIN);
  }
}

/* coords, tranformation , clip code and projection */
/* TODO : handle all cases */
 void inline gl_vertex_transform(GLContext * c, GLVertex * v)
{
    float *m;
    V4 *n;

    if (c->lighting_enabled) {
	/* eye coordinates needed for lighting */

	m = &c->TkGLMat[KH_ModelView].get_current_matrix()->m[0][0];
	v->ec.X = (v->coord.X * m[0] + v->coord.Y * m[1] +
		   v->coord.Z * m[2] + m[3]);
	v->ec.Y = (v->coord.X * m[4] + v->coord.Y * m[5] +
		   v->coord.Z * m[6] + m[7]);
	v->ec.Z = (v->coord.X * m[8] + v->coord.Y * m[9] +
		   v->coord.Z * m[10] + m[11]);
	v->ec.W = (v->coord.X * m[12] + v->coord.Y * m[13] +
		   v->coord.Z * m[14] + m[15]);

	/* projection coordinates */
	m = //&c->matrix_buffer_ptr[1];
	 &(c->TkGLMat[KH_PROJECTION].get_current_matrix()->m[0][0]);
	v->pc.X = (v->ec.X * m[0] + v->ec.Y * m[1] +
		   v->ec.Z * m[2] + v->ec.W * m[3]);
	v->pc.Y = (v->ec.X * m[4] + v->ec.Y * m[5] +
		   v->ec.Z * m[6] + v->ec.W * m[7]);
	v->pc.Z = (v->ec.X * m[8] + v->ec.Y * m[9] +
		   v->ec.Z * m[10] + v->ec.W * m[11]);
	v->pc.W = (v->ec.X * m[12] + v->ec.Y * m[13] +
		   v->ec.Z * m[14] + v->ec.W * m[15]);

	m = &c->matrix_model_view_inv.m[0][0];
	n = &c->current_normal;

	v->normal.X = (n->X * m[0] + n->Y * m[1] + n->Z * m[2]);
	v->normal.Y = (n->X * m[4] + n->Y * m[5] + n->Z * m[6]);
	v->normal.Z = (n->X * m[8] + n->Y * m[9] + n->Z * m[10]);

	if (c->normalize_enabled) {
	    gl_V3_Norm(&v->normal);
	}
    } else {
	/* no eye coordinates needed, no normal */
	/* NOTE: W = 1 is assumed */
	m = &c->matrix_model_projection.m[0][0];

	v->pc.X = (v->coord.X * m[0] + v->coord.Y * m[1] +
		   v->coord.Z * m[2] + m[3]);
	v->pc.Y = (v->coord.X * m[4] + v->coord.Y * m[5] +
		   v->coord.Z * m[6] + m[7]);
	v->pc.Z = (v->coord.X * m[8] + v->coord.Y * m[9] +
		   v->coord.Z * m[10] + m[11]);
	if (c->matrix_model_projection_no_w_transform) {
	    v->pc.W = m[15];
	} else {
	    v->pc.W = (v->coord.X * m[12] + v->coord.Y * m[13] +
		       v->coord.Z * m[14] + m[15]);
	}
    }

    v->clip_code = gl_clipcode(v->pc.X, v->pc.Y, v->pc.Z, v->pc.W);
}

 /* triangle */

/*
 * Clipping
 */

/* We clip the segment [a,b] against the 6 planes of the normal volume.
 * We compute the point 'c' of intersection and the value of the parameter 't'
 * of the intersection if x=a+t(b-a). 
 */
	 
 float inline clip_xmin(V4 *c,V4 *a,V4 *b) 
{ float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(- dX) + dW;
 if (den == 0)
	 t=0;
 else 
	 t = ( - a->v[0] - a->v[3]) / den;
 c->v[1] = a->v[1] + t * dY;
 c->v[2] = a->v[2] + t * dZ;
 c->v[3] = a->v[3] + t * dW;
 c->v[0] = - c->v[3];
 return t;
}

inline float clip_xmax(V4 *c,V4 *a,V4 *b) { float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(+ dX) + dW;
 if (den == 0) 
	 t=0;
 else 
	 t = ( + a->v[0] - a->v[3]) / den;
 c->v[1] = a->v[1] + t * dY;
 c->v[2] = a->v[2] + t * dZ;
 c->v[3] = a->v[3] + t * dW;
 c->v[0] = + c->v[3];
 return t;
}

inline float clip_ymin(V4 *c,V4 *a,V4 *b) { float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(- dY) + dW;
 if (den == 0) 
	 t=0;
 else 
	 t = ( - a->v[1] - a->v[3]) / den;
 c->v[0] = a->v[0] + t * dX;
 c->v[2] = a->v[2] + t * dZ;
 c->v[3] = a->v[3] + t * dW;
 c->v[1] = - c->v[3];
 return t;
}

inline float clip_ymax(V4 *c,V4 *a,V4 *b) { float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(+ dY) + dW;
 if (den == 0) t=0;
 else t = ( + a->v[1] - a->v[3]) / den;
 c->v[0] = a->v[0] + t * dX;
 c->v[2] = a->v[2] + t * dZ;
 c->v[3] = a->v[3] + t * dW;
 c->v[1] = + c->v[3];
 return t;
}

inline float clip_zmin(V4 *c,V4 *a,V4 *b) { float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(- dZ) + dW;
 if (den == 0) t=0;
 else t = ( - a->v[2] - a->v[3]) / den;
 c->v[0] = a->v[0] + t * dX;
 c->v[1] = a->v[1] + t * dY;
 c->v[3] = a->v[3] + t * dW;
 c->v[2] = - c->v[3];
 return t;
}
inline float clip_zmax(V4 *c,V4 *a,V4 *b) { float t,dX,dY,dZ,dW,den;
 dX = (b->v[0] - a->v[0]);
 dY = (b->v[1] - a->v[1]);
 dZ = (b->v[2] - a->v[2]);
 dW = (b->v[3] - a->v[3]);
 den = -(+ dZ) + dW;
 if (den == 0) t=0;
 else t = ( + a->v[2] - a->v[3]) / den;
 c->v[0] = a->v[0] + t * dX;
 c->v[1] = a->v[1] + t * dY;
 c->v[3] = a->v[3] + t * dW;
 c->v[2] = + c->v[3];
 return t;
}




static float (*clip_proc[6])(V4 *,V4 *,V4 *)=  {
    clip_xmin,clip_xmax,
    clip_ymin,clip_ymax,
    clip_zmin,clip_zmax
};

  inline void updateTmp(GLContext *c,
			     GLVertex *q,GLVertex *p0,GLVertex *p1,float t)
{
  if (c->current_shade_model == GL_SMOOTH) {
    q->color.v[0]=p0->color.v[0] + (p1->color.v[0]-p0->color.v[0])*t;
    q->color.v[1]=p0->color.v[1] + (p1->color.v[1]-p0->color.v[1])*t;
    q->color.v[2]=p0->color.v[2] + (p1->color.v[2]-p0->color.v[2])*t;
  } else {
    q->color.v[0]=p0->color.v[0];
    q->color.v[1]=p0->color.v[1];
    q->color.v[2]=p0->color.v[2];
  }

  if (c->texture_2d_enabled) {
    q->tex_coord.X=p0->tex_coord.X + (p1->tex_coord.X-p0->tex_coord.X)*t;
    q->tex_coord.Y=p0->tex_coord.Y + (p1->tex_coord.Y-p0->tex_coord.Y)*t;
  }

  q->clip_code=gl_clipcode(q->pc.X,q->pc.Y,q->pc.Z,q->pc.W);
  if (q->clip_code==0)
    gl_transform_to_viewport(c,q);
}

 


inline void GraphDrawLib::gl_draw_triangle_clip(GLContext *c,
                                  GLVertex *p0,GLVertex *p1,GLVertex *p2,int clip_bit)
{
  int co,c_and,co1,cc[3],edge_flag_tmp,clip_mask;
  GLVertex tmp1,tmp2,*q[3];
  float tt;
  
  cc[0]=p0->clip_code;
  cc[1]=p1->clip_code;
  cc[2]=p2->clip_code;
  
  co=cc[0] | cc[1] | cc[2];
  if (co == 0) {
    gl_draw_triangle(c,p0,p1,p2);
  } else {
    c_and=cc[0] & cc[1] & cc[2];
    /* the triangle is completely outside */
    if (c_and!=0) return;

    /* find the next direction to clip */
    while (clip_bit < 6 && (co & (1 << clip_bit)) == 0)  {
      clip_bit++;
    }

    /* this test can be true only in case of rounding errors */
    if (clip_bit == 6) {
#if 0
      printf("Error:\n");
      printf("%f %f %f %f\n",p0->pc.X,p0->pc.Y,p0->pc.Z,p0->pc.W);
      printf("%f %f %f %f\n",p1->pc.X,p1->pc.Y,p1->pc.Z,p1->pc.W);
      printf("%f %f %f %f\n",p2->pc.X,p2->pc.Y,p2->pc.Z,p2->pc.W);
#endif
      return;
    }
  
    clip_mask = 1 << clip_bit;
    co1=(cc[0] ^ cc[1] ^ cc[2]) & clip_mask;
    
    if (co1)  { 
      /* one point outside */

      if (cc[0] & clip_mask) { q[0]=p0; q[1]=p1; q[2]=p2; }
      else if (cc[1] & clip_mask) { q[0]=p1; q[1]=p2; q[2]=p0; }
      else { q[0]=p2; q[1]=p0; q[2]=p1; }
      
      tt=clip_proc[clip_bit](&tmp1.pc,&q[0]->pc,&q[1]->pc);
      updateTmp(c,&tmp1,q[0],q[1],tt);

      tt=clip_proc[clip_bit](&tmp2.pc,&q[0]->pc,&q[2]->pc);
      updateTmp(c,&tmp2,q[0],q[2],tt);

      tmp1.edge_flag=q[0]->edge_flag;
      edge_flag_tmp=q[2]->edge_flag;
      q[2]->edge_flag=0;
      gl_draw_triangle_clip(c,&tmp1,q[1],q[2],clip_bit+1);

      tmp2.edge_flag=1;
      tmp1.edge_flag=0;
      q[2]->edge_flag=edge_flag_tmp;
      gl_draw_triangle_clip(c,&tmp2,&tmp1,q[2],clip_bit+1);
    } else {
      /* two points outside */

      if ((cc[0] & clip_mask)==0) { q[0]=p0; q[1]=p1; q[2]=p2; }
      else if ((cc[1] & clip_mask)==0) { q[0]=p1; q[1]=p2; q[2]=p0; } 
      else { q[0]=p2; q[1]=p0; q[2]=p1; }
      
      tt=clip_proc[clip_bit](&tmp1.pc,&q[0]->pc,&q[1]->pc);
      updateTmp(c,&tmp1,q[0],q[1],tt);

      tt=clip_proc[clip_bit](&tmp2.pc,&q[0]->pc,&q[2]->pc);
      updateTmp(c,&tmp2,q[0],q[2],tt);
      
      tmp1.edge_flag=1;
      tmp2.edge_flag=q[2]->edge_flag;
      gl_draw_triangle_clip(c,q[0],&tmp1,&tmp2,clip_bit+1);
    }
  }
}


 
 
void inline GraphDrawLib::gl_draw_triangle(GLContext *c,
                      GLVertex *p0,GLVertex *p1,GLVertex *p2)
{
  int co,c_and,cc[3],front;
  float norm;
  
  cc[0]=p0->clip_code;
  cc[1]=p1->clip_code;
  cc[2]=p2->clip_code;
  
  co=cc[0] | cc[1] | cc[2];

  /* we handle the non clipped case here to go faster */
  if (co==0) {
    
      norm=(float)(p1->zp.x-p0->zp.x)*(float)(p2->zp.y-p0->zp.y)-
        (float)(p2->zp.x-p0->zp.x)*(float)(p1->zp.y-p0->zp.y);
      
      if (norm == 0) return;

      front = norm < 0.0;
      front = front ^ c->current_front_face;
  
      /* back face culling */
      if (c->cull_face_enabled) {
        /* most used case first */
        if (c->current_cull_face == GL_BACK) {
          if (front == 0) return;
          c->draw_triangle_front(c,p0,p1,p2);
        } else if (c->current_cull_face == GL_FRONT) {
          if (front != 0) return;
          c->draw_triangle_back(c,p0,p1,p2);
        } else {
          return;
        }
      } else {
        /* no culling */
        if (front) {
          c->draw_triangle_front(c,p0,p1,p2);
        } else {
          c->draw_triangle_back(c,p0,p1,p2);
        }
      }
  } else {
    c_and=cc[0] & cc[1] & cc[2];
    if (c_and==0) {
      gl_draw_triangle_clip(c,p0,p1,p2,0);
    }
  }
}


//=======================================================================
//=======================================================================
void inline glopMaterial(GLContext *c,GLParam *p)
{
  int mode=p[1].i;
  int type=p[2].i;
  
  float vv[4];
  vv[0] = p[3].f;
  vv[1] = p[4].f;
  vv[2] = p[5].f;
  vv[3] = p[6].f;
  float *v=vv;//&p[3].f;
 // float *v=&p[3].f;
  int i;
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
    m->shininess   = v[0];
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


static inline float clampf(float a,float min,float max)
{
  if (a<min) return min;
  else if (a>max) return max;
  else return a;
}

void  inline  GraphDrawLib::gl_enable_disable_light(GLContext *c,int light,int v)
{
  GLLight *l=&c->lights[light];
  if (v && !l->enabled) {
    l->enabled=1;
    l->next=c->first_light;
    c->first_light=l;
    l->prev=NULL;
  } else if (!v && l->enabled) {
    l->enabled=0;
    if (l->prev == NULL) c->first_light=l->next;
    else l->prev->next=l->next;
    if (l->next != NULL) l->next->prev=l->prev;
  }
}

/* non optimized lightening model */
void  inline  GraphDrawLib::gl_shade_vertex(GLContext *c,GLVertex *v)
{
  float R,G,B,A;
  GLMaterial *m;
  GLLight *l;
  V3 n,s,d;
  float dist,tmp,att,dot,dot_spot,dot_spec;
  int twoside = c->light_model_two_side;

  m=&c->materials[0];

  n.X=v->normal.X;
  n.Y=v->normal.Y;
  n.Z=v->normal.Z;

  R=m->emission.v[0]+m->ambient.v[0]*c->ambient_light_model.v[0];
  G=m->emission.v[1]+m->ambient.v[1]*c->ambient_light_model.v[1];
  B=m->emission.v[2]+m->ambient.v[2]*c->ambient_light_model.v[2];
  A=clampf(m->diffuse.v[3],0,1);

  for(l=c->first_light;l!=NULL;l=l->next) {
    float lR,lB,lG;
    
    /* ambient */
    lR=l->ambient.v[0] * m->ambient.v[0];
    lG=l->ambient.v[1] * m->ambient.v[1];
    lB=l->ambient.v[2] * m->ambient.v[2];

    if (l->position.v[3] == 0) {
      /* light at infinity */
      d.X=l->position.v[0];
      d.Y=l->position.v[1];
      d.Z=l->position.v[2];
      att=1;
    } else {
      /* distance attenuation */
      d.X=l->position.v[0]-v->ec.v[0];
      d.Y=l->position.v[1]-v->ec.v[1];
      d.Z=l->position.v[2]-v->ec.v[2];
      dist=sqrt(d.X*d.X+d.Y*d.Y+d.Z*d.Z);
      if (dist>1E-3) {
        tmp=1/dist;
        d.X*=tmp;
        d.Y*=tmp;
        d.Z*=tmp;
      }
      att=1.0f/(l->attenuation[0]+dist*(l->attenuation[1]+
				     dist*l->attenuation[2]));
    }
    dot=d.X*n.X+d.Y*n.Y+d.Z*n.Z;
    if (twoside && dot < 0) dot = -dot;
    if (dot>0) {
      /* diffuse light */
      lR+=dot * l->diffuse.v[0] * m->diffuse.v[0];
      lG+=dot * l->diffuse.v[1] * m->diffuse.v[1];
      lB+=dot * l->diffuse.v[2] * m->diffuse.v[2];

      /* spot light */
      if (l->spot_cutoff != 180) {
        dot_spot=-(d.X*l->norm_spot_direction.v[0]+
                   d.Y*l->norm_spot_direction.v[1]+
                   d.Z*l->norm_spot_direction.v[2]);
        if (twoside && dot_spot < 0) dot_spot = -dot_spot;
        if (dot_spot < l->cos_spot_cutoff) {
          /* no contribution */
          continue;
        } else {
          /* TODO: optimize */
          if (l->spot_exponent > 0) {
            att=att*pow(dot_spot,l->spot_exponent);
          }
        }
      }

      /* specular light */
      
      if (c->local_light_model) {
        V3 vcoord;
        vcoord.X=v->ec.X;
        vcoord.Y=v->ec.Y;
        vcoord.Z=v->ec.Z;
        gl_V3_Norm(&vcoord);
        s.X=d.X-vcoord.X;
        s.Y=d.Y-vcoord.X;
        s.Z=d.Z-vcoord.X;
      } else {
        s.X=d.X;
        s.Y=d.Y;
        s.Z=d.Z+1.0;
      }
      dot_spec=n.X*s.X+n.Y*s.Y+n.Z*s.Z;
      if (twoside && dot_spec < 0) dot_spec = -dot_spec;
      if (dot_spec>0) {
        GLSpecBuf *specbuf;
        int idx;
        tmp=sqrt(s.X*s.X+s.Y*s.Y+s.Z*s.Z);
        if (tmp > 1E-3) {
          dot_spec=dot_spec / tmp;
        }
      
        /* TODO: optimize */
        /* testing specular buffer code */
        /* dot_spec= pow(dot_spec,m->shininess);*/
        specbuf = c->specbuf_get_buffer(c, m->shininess_i, m->shininess);
        idx = (int)(dot_spec*SPECULAR_BUFFER_SIZE);
        if (idx > SPECULAR_BUFFER_SIZE) idx = SPECULAR_BUFFER_SIZE;
        dot_spec = specbuf->buf[idx];
        lR+=dot_spec * l->specular.v[0] * m->specular.v[0];
        lG+=dot_spec * l->specular.v[1] * m->specular.v[1];
        lB+=dot_spec * l->specular.v[2] * m->specular.v[2];
      }
    }

    R+=att * lR;
    G+=att * lG;
    B+=att * lB;
  }

  v->color.v[0]=clampf(R,0,1);
  v->color.v[1]=clampf(G,0,1);
  v->color.v[2]=clampf(B,0,1);
  v->color.v[3]=A;
}

inline void GraphDrawLib::gl_resizeImageNoInterpolate(unsigned char *dest,int xsize_dest,int ysize_dest,
                                 unsigned char *src,int xsize_src,int ysize_src)
{
#define FRAC_BITS 16

  unsigned char *pix,*pix_src,*pix1;
  int x1,y1,x1inc,y1inc;
  int xi,yi,x,y;

  pix=dest;
  pix_src=src;
  
  x1inc=(int)((float) ((xsize_src)<<FRAC_BITS) / (float) (xsize_dest));
  y1inc=(int)((float) ((ysize_src)<<FRAC_BITS) / (float) (ysize_dest));

  y1=0;
  for(y=0;y<ysize_dest;y++) {
    x1=0;
    for(x=0;x<xsize_dest;x++) {
      xi=x1 >> FRAC_BITS;
      yi=y1 >> FRAC_BITS;
      pix1=pix_src+(yi*xsize_src+xi)*3;

      pix[0]=pix1[0];
      pix[1]=pix1[1];
      pix[2]=pix1[2];

      pix+=3;
      x1+=x1inc;
    }
    y1+=y1inc;
  }
}

 
static inline void free_texture(GLContext *c,int h)
{
  GLTexture *t,**ht;
  GLImage *im;
  int i;
 
}
 
 
  inline  void GraphDrawLib::glGenTextures(int n, unsigned int *textures)
{
  GLContext *c=gl_get_context();
  int max,i;
  max=0;
  for(i=0;i<n;i++) {
    textures[i]=max+i+1;
  }
}


inline void  GraphDrawLib::glDeleteTextures(int n, const unsigned int *textures)
{
  GLContext *c=gl_get_context();
  int i;
  GLTexture *t;

  for(i=0;i<n;i++) {
    t= c->find_texture(c,textures[i]);
    if (t!=NULL && t!=0) {
      if (t==c->current_texture) {
	glBindTexture(GL_TEXTURE_2D,0);
      }
      free_texture(c,textures[i]);
    }
  }
}


#endif
