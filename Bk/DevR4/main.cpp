#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gl.h"										
//#include "glut.h"
#include <math.h>
#include "3DS.h"
#include "c24bitmap.h"

#define FILE_NAME  "FACE.3DS"
#include "readstl.h"

typedef unsigned int UINT;
unsigned int g_Texture[MAX_TEXTURES] = {0};

CLoad3DS g_Load3ds;									
t3DModel g_3DModel;									
								

int   g_ViewMode	  = GL_TRIANGLES;			
bool  g_bLighting     = true;				
float g_RotateX		  = 0.0f;				
float g_RotationSpeed = 0.5f;
C24BitMap pBitmap;

 
GraphDrawLib TkGDrawLib;
//  从文件中创建纹理
void CreateTexture(UINT textureArray[], char* strFileName, int textureID)
{
	
	if(!strFileName)									// 如果无此文件，则直接返回
		return;

	pBitmap.Load(strFileName);				// 装入位图，并保存数据
	
	// 生成纹理
	TkGDrawLib.glGenTextures(1, &textureArray[textureID]);
 
	TkGDrawLib.glBindTexture(GL_TEXTURE_2D, textureArray[textureID]);


	TkGDrawLib.glTexImage2D(GL_TEXTURE_2D,0,3,
		pBitmap.Width, pBitmap.Height,0,
		GL_RGB, GL_UNSIGNED_BYTE, pBitmap.Buffer);
		 
}

void RenderScene() 
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//glLoadIdentity();									

	//gluLookAt(		0, 1.5f, 8,		0, 0.5f, 0,			0, 1, 0);
	//g_RotationSpeed = 35.0;
	//g_RotateX += g_RotationSpeed;	
	//glRotatef(g_RotateX, 0, 1.0f, 0);
	

	// 遍历模型中所有的对象
	for(int i = 0; i < g_3DModel.numOfObjects; i++)
	{
		// 如果对象的大小小于0，则退出
		if(g_3DModel.pObject.size() <= 0) break;

		// 获得当前显示的对象
		t3DObject *pObject = &g_3DModel.pObject[i];
			
		// 判断该对象是否有纹理映射
		if(pObject->bHasTexture) {

			// 打开纹理映射
			TkGDrawLib.glEnable(GL_TEXTURE_2D);
			TkGDrawLib.glColor3f(1.0, 1.0, 1.0);
			printf("matid:%i\n",pObject->materialID);
			TkGDrawLib.glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		} else {

			// 关闭纹理映射
			TkGDrawLib.glDisable(GL_TEXTURE_2D);
			TkGDrawLib.glColor3f(1.0, 1.0, 1.0);
		}
		// 开始以g_ViewMode模式绘制
		TkGDrawLib.glBegin(g_ViewMode);					
			// 遍历所有的面
			for(int j = 0; j < pObject->numOfFaces; j++)
			{
				// 遍历三角形的所有点
				for(int whichVertex = 0; whichVertex < 3; whichVertex++)
				{
					// 获得面对每个点的索引
					int index = pObject->pFaces[j].vertIndex[whichVertex];
			
					// 给出法向量
					TkGDrawLib.glNormal3f(pObject->pNormals[ index ].x, pObject->pNormals[ index ].y, pObject->pNormals[ index ].z);
				
					// 如果对象具有纹理
					if(pObject->bHasTexture) {

						// 确定是否有UVW纹理坐标
						if(pObject->pTexVerts) {
							TkGDrawLib.glTexCoord2f(pObject->pTexVerts[ index ].x, pObject->pTexVerts[ index ].y);
						}
					} else {

						if(g_3DModel.pMaterials.size() && pObject->materialID >= 0) 
						{
							BYTE *pColor = g_3DModel.pMaterials[pObject->materialID].color;
							TkGDrawLib.glColor3f(float(pColor[0])/255.0, float(pColor[1])/255.0, float(pColor[2])/255.0);
						}
					}
					TkGDrawLib.glVertex3f(pObject->pVerts[ index ].x/4+1.2, pObject->pVerts[ index ].y/4, pObject->pVerts[ index ].z/4);
				}
			}

		TkGDrawLib.glEnd();								// 绘制结束
	}

 
}
 

void reshape(int width, int height)		
{
	if (height==0)										
	{
		height=1;										
	}

	TkGDrawLib.glViewport(0,0,width,height);						

	TkGDrawLib.glMatrixMode(GL_PROJECTION);		
	TkGDrawLib.glLoadIdentity();						
	TkGDrawLib.gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, .5f ,150.0f);

	TkGDrawLib.glMatrixMode(GL_MODELVIEW);						
	TkGDrawLib.glLoadIdentity();									
}

#define WindowWidth  1600
#define WindowHeight 1600
#define WindowTitle  "OpenGL纹理测试"

//void model_init()
void CreateTexture(UINT textureArray[], char* strFileName, int textureID);
void init()
{

	g_Load3ds.Import3DS(&g_3DModel, FILE_NAME);			// 将3ds文件装入到模型结构体中

	// 遍历所有的材质
	for(int i = 0; i < g_3DModel.numOfMaterials; i++)
	{
		// 判断是否是一个文件名
		if(strlen(g_3DModel.pMaterials[i].strFile) > 0)
		{
			//  使用纹理文件名称来装入位图
			CreateTexture(g_Texture, g_3DModel.pMaterials[i].strFile, i);			
		}

		// 设置材质的纹理ID
		g_3DModel.pMaterials[i].texureId = i;
	}

	TkGDrawLib.glEnable(GL_LIGHT0);								
	TkGDrawLib.glEnable(GL_LIGHTING);								
	TkGDrawLib.glEnable(GL_COLOR_MATERIAL);					

}
 

float vx[][3]={{0,  -0.02, 0.0},{100, -0.02, 0.0},
               {100, 0.02, 0.0},{  0,  0.02, 0.0} };

float vy[][3]={ {-0.02,  0, 0.0 } ,{  0.02,   0, 0.0}, 
	                {0.02 ,100, 0.0},  {-0.02, 100, 0.0}};		
		
float vz[][3]={{-0.02,  0, 0.0},{ -0.02,  0, 100.0}, 
                 	{0.02 ,0, 100.0},{  0.02,   0, 0.0} };	
	
	
void drawPolygon(float Vertices[][3])
{
  int i;
  int Size =4;
  TkGDrawLib.glBegin(GL_POLYGON);
  
  for(i=0; i<Size; i++)
    TkGDrawLib.glVertex3fv(Vertices[i]);
  TkGDrawLib.glEnd();

}				

  


void SurfSetColor(float rr,float gg, float bb)
{
    /*RobotMat->SetValue(DIFFUSE, sat_r, sat_g, sat_b, 1.0);
    RobotMat->SetValue(AMBIENT, sat_r, sat_g, sat_b, 1.0);
    RobotMat->SetValue(SPECULAR, 1.0, 1.0, 1.0, 1.0);
    RobotMat->SetValue(SHININESS, 100.0);*/
   
    float  Ambient[4];
	float  Diffuse[4];
    float Specular[4] ={1.0, 1.0, 1.0, 1.0};
    float Emission[4];
    float Shininess =100;
  
    Ambient[0] = rr; Ambient[1] = gg; Ambient[2] = bb; Ambient[3] = 1;  
	Diffuse[0] = rr; Diffuse[1] = gg; Diffuse[2] = bb; Diffuse[3] = 1;  
    TkGDrawLib.glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ambient);
    TkGDrawLib.glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Diffuse);
    TkGDrawLib.glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Specular);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Emission);
    TkGDrawLib.glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Shininess);

}

void StlShape_Render(std::vector<triangle>&facet)
{
  int i;
   
  //glPushAttrib(GL_ALL_ATTRIB_BITS);

  
  TkGDrawLib.glBegin(GL_TRIANGLES);
  for(int i = 0; i < facet.size(); i++)
  {
        // 遍历三角形的所有点
      for(int whichVertex = 0; whichVertex < 3; whichVertex++ )
       {
        // 给出法向量
        TkGDrawLib.glNormal3f(facet[i].normal.x, facet[i].normal.y, facet[i].normal.z);
        // 如果对象具有纹理
        TkGDrawLib.glVertex3f( facet[i].point[whichVertex].x , 
		            facet[i].point[whichVertex].y , 
				    facet[i].point[whichVertex].z ); /* */
		/*glNormal3f(facet[i].normal.z,facet[i].normal.x, facet[i].normal.y);
        // 如果对象具有纹理
        glVertex3f( facet[i].point[whichVertex].z ,
		            facet[i].point[whichVertex].x , 
		            facet[i].point[whichVertex].y 
				     );*/
       }
   }
  TkGDrawLib.glEnd();
  
 //glPopAttrib(); 
}

void Test_TRIANGLES( )
{
  int i;
   TkGDrawLib.glBegin(GL_TRIANGLES);
   TkGDrawLib.glVertex3f(-1.5,0,0); /* */
   TkGDrawLib.glVertex3f(-1,0,1);
   TkGDrawLib.glVertex3f(0,0.3,0);
   TkGDrawLib.glEnd();
 
}
void SetCamera()
{
	TkGDrawLib.gluPerspective(90.0, 1, 0.01, 50);
    TkGDrawLib.glMatrixMode(GL_MODELVIEW);
    
    TkGDrawLib.glLoadIdentity();
    TkGDrawLib.gluLookAt( 0, 1.5f, 4, 0, -1.5f, -4,
	             0, 1, 0);
	TkGDrawLib.glEnable(GL_LIGHT0);								
	TkGDrawLib.glEnable(GL_LIGHTING);								
	TkGDrawLib.glEnable(GL_COLOR_MATERIAL);				 
     
}

void glXSwapBuffers();
int main(int argc,char* argv[])
{
	TkGDrawLib.InitDrawLib(1600,1600);
	//ui_loop(argc, argv, "models");
    init();
	
	TkGDrawLib.glEnable(GL_DEPTH_TEST);    
	TkGDrawLib.glEnable(GL_TEXTURE_2D);    // 启用纹理
 
	reshape(WindowWidth, WindowHeight);
	 
	//glutMainLoop(); //循环调用
	float Position[4], SpotDirection[4];

	//RenderScene();
	SetCamera();
	SurfSetColor(0.0, 1, 0);
	
	RenderScene();
	
    Position[0]=-1; Position[1]=1; Position[2]=1; Position[3]=1;
	SpotDirection[0] =  1; SpotDirection[1] = -1; SpotDirection[2] = -1; SpotDirection[3] =  1;

	TkGDrawLib.glLightfv(GL_LIGHT1, GL_POSITION, Position);
	TkGDrawLib.glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, SpotDirection);
	
	TkGDrawLib.glEnable(GL_LIGHT1);
	
    Position[0] = -2;  Position[1] =  3 ; Position[2] =1.5;  Position[3] =1;

	SpotDirection[0] =   2; SpotDirection[1] =  -3; SpotDirection[2] =  -1.5;
	
    TkGDrawLib.glLightfv(GL_LIGHT2, GL_POSITION, Position);
	TkGDrawLib.glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, SpotDirection);
	
	
	TkGDrawLib.glEnable(GL_LIGHT2);
	
	
	Position[0] =0;  Position[1] =5 ;  Position[2] =3;  Position[3] =1;
	SpotDirection[0] =  0; SpotDirection[1] =  -5; SpotDirection[2] =  -3;
	
    TkGDrawLib.glLightfv(GL_LIGHT3, GL_POSITION, Position);
	TkGDrawLib.glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, SpotDirection);
	
	TkGDrawLib.glEnable(GL_LIGHT3);
	
	
	int i,j;
	
	std::vector<triangle> bunny_facet;
	double x_min,   x_max,  y_min,   y_max,  z_min,   z_max;
    read_binary_STL_file("bunny.stl",bunny_facet,
    x_min,   x_max,  y_min,   y_max,  z_min,   z_max);
	
   printf("%.2lf,%.2lf\n",x_min,   x_max);	
   TkGDrawLib.glDisable(GL_TEXTURE_2D);
   SurfSetColor(1.0, 0, 0);
   drawPolygon(vx);
   for(i=0;i<10;i++)
   {
	   for(j=0;j<4;j++) vx[j][1] +=0.2;
	   
	   drawPolygon(vx);
   }
  SurfSetColor(0.0, 1, 0);
  drawPolygon(vy);
     for(i=0;i<10;i++)
   {
	   for(j=0;j<4;j++) vy[j][0] +=0.2;
	  
	   drawPolygon(vy);
   }
  SurfSetColor(0.0, 0, 1);
  drawPolygon(vz);
  
       for(i=0;i<10;i++)
   {
	   for(j=0;j<4;j++) vz[j][0] +=0.2;
	   
	   drawPolygon(vz);
   }/**/
    
	Test_TRIANGLES( );
    TkGDrawLib.glScalef(7, 7, 7);
    
	TkGDrawLib.glRotatef(40.0, 0, 1.0f, 0);
	
    StlShape_Render(bunny_facet);
   // glXSwapBuffers();

	TkGDrawLib.gl_ctx.glXSaveRenderImg("imgok.bmp");
	TkGDrawLib.glClose();
    return 1;
}
