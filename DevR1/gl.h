/*
 * The following constants come from Mesa
 */
#ifndef GL_H
#define GL_H

#include <math.h>
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
	GL_MODELVIEW		 = 0x1700,
	GL_PROJECTION		 = 0x1701,
	GL_TEXTURE			 = 0x1702,

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
  void *pixmap;
  int xsize,ysize;
} GLImage;


#define TEXTURE_HASH_TABLE_SIZE 256

typedef struct GLTexture {
  GLImage images[MAX_TEXTURE_LEVELS];
  int handle;
  struct GLTexture *next,*prev;
} GLTexture;

typedef struct GLSharedState {
  GLList **lists;
  GLTexture **texture_hash_table;
} GLSharedState;


//====================================================
//struct GLContext;

typedef void (*gl_draw_triangle_func)( GLContext *c,
                                      GLVertex *p0,GLVertex *p1,GLVertex *p2);

/* display context */
///###################################################################
///###################################################################
enum GDMatrixTye{KH_ModelView,KH_PROJECTION,KH_TEXTURE};
 
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

  /* shared state */
  GLSharedState shared_state;

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
};// GLContext;

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
/* functions */
void glBegin(int mode);
void glBindTexture(int target,int texture);
void glColor3f(float x,float y,float z); 
void glColor4f(float r,float g,float b,float a);
void glColorMaterial(int mode,int type);
void glDisable(int cap);
void glEnable(int cap);
void glEnd();
void gl_eval_viewport(GLContext * c);
void glFrustum(double left,double right,double bottom,double top,
               double near,double farp);
void glLightfv(int light,int type,float *val);
void glLoadIdentity(void);
void glMaterialf(int mode,int type,float val);
void glMaterialfv(int mode,int type,float *v);
void glMatrixMode(int mode);
void gl_matrix_update(GLContext *c);
 //void gl_matrix_update(GLContext *c);
void glMultMatrixf(const float *mm);
void glNormal3f(float x,float y,float z);
void glopMaterial(GLContext *c,GLParam *p);
void glPopMatrix( );
void glPushMatrix( );
void glRotatef(float angle,float x,float y,float z);
void glScalef(float x,float y,float z);
void glTexCoord2f(float s,float t);
void glTexCoord4f(float s,float t,float r,float q);
void glTexImage2D( int target, int level, int components,
                   int width, int height, int border,
                   int format, int type, void *pixels);
void glTranslatef(float x,float y,float z);
void gluPerspective( GLdouble fovy, GLdouble aspect,
		     GLdouble zNear, GLdouble zFar );
void glVertex3f(float x,float y,float z); 
void glVertex3fv(float *v); 
void glVertex4f(float x,float y,float z,float w);
void gl_vertex_transform(GLContext * c, GLVertex * v);
void glViewport(int x,int y,int width,int height); 

void glClose(void);

 

  

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

#endif
