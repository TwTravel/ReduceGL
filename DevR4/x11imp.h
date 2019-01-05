#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include "gl.h"
 
//void glInit(void *zbuffer1);
void glInit(int xsize,int ysize);

 
 bool glXMakeDrawOk(  int width, int height)
{
 
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


