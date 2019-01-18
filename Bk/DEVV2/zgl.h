#ifndef _tgl_zgl_h_
#define _tgl_zgl_h_
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "gl.h"
 
#include <vector>

using namespace std;
#define DEBUG
 //=========================================================
/* textures */
 extern GLContext *gl_ctx;

//void glRunFunc(GLParam *p);

/* clip.c */
void gl_transform_to_viewport(GLContext *c,GLVertex *v);
void gl_draw_triangle(GLContext *c,GLVertex *p0,GLVertex *p1,GLVertex *p2);
void gl_draw_line(GLContext *c,GLVertex *p0,GLVertex *p1);
void gl_draw_point(GLContext *c,GLVertex *p0);

void gl_draw_triangle_point(GLContext *c,
                            GLVertex *p0,GLVertex *p1,GLVertex *p2);
//void gl_draw_triangle_line(GLContext *c,
 //                          GLVertex *p0,GLVertex *p1,GLVertex *p2);
void gl_draw_triangle_fill(GLContext *c,
                           GLVertex *p0,GLVertex *p1,GLVertex *p2);
 

/* light.c */
//void gl_add_select(GLContext *c,unsigned int zmin,unsigned int zmax);
void gl_enable_disable_light(GLContext *c,int light,int v);
void gl_shade_vertex(GLContext *c,GLVertex *v);

void glInitTextures(GLContext *c);
void glEndTextures(GLContext *c);
//GLTexture *alloc_texture(GLContext *c,int h);

/* image_util.c */

void gl_resizeImage(unsigned char *dest,int xsize_dest,int ysize_dest,
                    unsigned char *src,int xsize_src,int ysize_src);
void gl_resizeImageNoInterpolate(unsigned char *dest,int xsize_dest,int ysize_dest,
                                 unsigned char *src,int xsize_src,int ysize_src);

GLContext *gl_get_context(void);

void gl_fatal_error(char *format, ...);


/* specular buffer "api" */
GLSpecBuf *specbuf_get_buffer(GLContext *c, const int shininess_i, 
                              const float shininess);

 

//===================================
//#include "glx.h"
 

 inline GLContext*gl_get_context(void)
{
  return gl_ctx;
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

#endif /* _tgl_zgl_h_ */
