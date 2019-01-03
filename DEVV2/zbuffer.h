#ifndef _tgl_zbuffer_h_
#define _tgl_zbuffer_h_

/*
 * Z buffer
 */

 

#define ZB_Z_BITS 16

#define ZB_POINT_Z_FRAC_BITS 14

#define ZB_POINT_S_MIN ( (1<<13) )
#define ZB_POINT_S_MAX ( (1<<22)-(1<<13) )
#define ZB_POINT_T_MIN ( (1<<21) )
#define ZB_POINT_T_MAX ( (1<<30)-(1<<21) )

 

#define ZB_POINT_RED_MIN ( (1<<9) )
#define ZB_POINT_RED_MAX ( (1<<16)-(1<<9) )
#define ZB_POINT_GREEN_MIN ( (1<<9) )
#define ZB_POINT_GREEN_MAX ( (1<<16)-(1<<9) )
#define ZB_POINT_BLUE_MIN ( (1<<9) )
#define ZB_POINT_BLUE_MAX ( (1<<16)-(1<<9) )

 
 

//#elif TGL_FEATURE_RENDER_BITS == 24

#define RGB_TO_PIXEL(r,g,b) \
  ((((r) << 8) & 0xff0000) | ((g) & 0xff00) | ((b) >> 8))
typedef unsigned char PIXEL;
#define PSZB 3
#define PSZSH 5


class ZBuffer{
public:
    int xsize,ysize;
    int linesize; /* line size, in bytes */
    int mode;
    
    double *zbuf;
    PIXEL *pbuf;
    int frame_buffer_allocated;
    
    int nb_colors;
    unsigned char *dctable;
    int *ctable;
    PIXEL *current_texture;
	ZBuffer inline *ZB_open(int xsize, int ysize, int mode,
		 int nb_colors,
		 unsigned char *color_indexes,
		 int *color_table,
		 void *frame_buffer);
	void inline  ZB_close( );
	void inline  ZB_setTexture( PIXEL *texture);
};// ZBuffer;

void gl_free(void *p);
void *gl_malloc(int size);
void *gl_zalloc(int size);

typedef struct {
  int x,y,z;     /* integer coordinates in the zbuffer */
  int s,t;       /* coordinates for the mapping */
  int r,g,b;     /* color indexes */
  
  float sz,tz;   /* temporary coordinates for mapping */
} ZBufferPoint;

/* zbuffer.c */
inline ZBuffer * ZBuffer::ZB_open(int xsize, int ysize, int mode,
		 int nb_colors,
		 unsigned char *color_indexes,
		 int *color_table,
		 void *frame_buffer)
{
    ZBuffer *zb = this;
    int size;

   // zb = (ZBuffer *)gl_malloc(sizeof(ZBuffer));

    if (zb == NULL)
	return NULL;

    zb->xsize = xsize;
    zb->ysize = ysize;
    zb->mode = mode;
    zb->linesize = (xsize * PSZB + 3) & ~3;

 
    zb->nb_colors = 0;
 

    size = zb->xsize * zb->ysize * sizeof(double);//sizeof(unsigned short);

    zb->zbuf = (double *)gl_malloc(size);
    if (zb->zbuf == NULL)
	goto error;

    if (frame_buffer == NULL) {
	zb->pbuf = (PIXEL *)gl_malloc(zb->ysize * zb->linesize);
	if (zb->pbuf == NULL) {
	    gl_free(zb->zbuf);
	    goto error;
	}
	zb->frame_buffer_allocated = 1;
    } else {
	zb->frame_buffer_allocated = 0;
	zb->pbuf = (PIXEL *)frame_buffer;
    }

    zb->current_texture = NULL;

    return zb;
  error:
    gl_free(zb);
    return NULL;
}

void inline ZBuffer::ZB_close()
{
	ZBuffer * zb = this;
    if (zb->frame_buffer_allocated)
	gl_free(zb->pbuf);

    gl_free(zb->zbuf);
    gl_free(zb);
}

 void inline ZBuffer::ZB_setTexture( PIXEL *texture)
{
     current_texture=texture;
}

#endif /* _tgl_zbuffer_h_ */
