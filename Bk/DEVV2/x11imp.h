#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 
#include "gl.h"
//#include "ui.h"
#include "zgl.h"

//void glInit(void *zbuffer1);
void glInit(int xsize,int ysize);

#ifndef M_PI
#  define M_PI 3.14159265
#endif

 
 

 bool glXMakeDrawOk(  int width, int height)
{
  GLContext * gl_context=gl_get_context();   
   
  if ( gl_context == NULL) {
      
    glInit( width,  height);

	gl_context=gl_get_context();
    gl_context->image_w = width;
	gl_context->image_h = height;
    gl_context->gl_resize_viewport= NULL;  
    gl_context->viewport.xsize=-1;
    gl_context->viewport.ysize=-1;

    glViewport(0, 0, width,height);
  }

  return true;
}

 
void reshape( int width, int height );
void init( void );

int ui_loop(int argc, char **argv, const char *name)
{
   int k, width, height;
   char buf[80];
   width  = 1600;  height = 1600;
    
   glXMakeDrawOk(   width,  height);

   init();
   reshape(width, height);
  
  return 1;
}


