//Geometry.h
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Node.h"
#include "Color.h"
#include "Material.h"
#include "Transformation.h"

#include "readstl.h"
#include "c24bitmap.h"

class Geometry: public Node
{
 public:
  Geometry();
  ~Geometry();

  void SetColor(Enum);
  void SetColor(float, float, float);
  void SetColorv(float *);
  void SetColor(Color *);
  void SetMaterial(Enum, float, float, float, float);
  void SetMaterialv(Enum, float *);
  void SetMaterial(Enum, float);
  void SetMaterial(Material *);
  void SetTransform(Enum, float *, int);
  void SetTransform(Enum, float, float, float, int);
  void SetTransform(Enum, float, float, float, float, int);
  void SetTransform(Transformation *);
 
  virtual void Render();

 protected:
  Color *ColorNode;
  Material *MatNode;
  Transformation *TransNode;
 
};



inline Geometry::Geometry()
{
  ColorNode=NULL;
  MatNode=NULL;
  TransNode=NULL;
  LeftChild = RightSibling =NULL;
}

inline Geometry::~Geometry()
{
  if(ColorNode)
    {
      delete ColorNode;
      ColorNode=NULL;
    }
  if(MatNode)
    {
      delete MatNode;
      MatNode=NULL;
    }
  if(TransNode)
    {
      delete TransNode;
      TransNode=NULL;
    }
 
}

inline void Geometry::SetColor(Enum C)
{
  if(ColorNode==NULL)
    ColorNode=new Color(grawLib);

  ColorNode->SetValue(C);
}

inline void 
Geometry::SetColor(float v1, float v2, float v3)
{
  if(ColorNode==NULL)
    ColorNode=new Color(grawLib);

  ColorNode->SetValue(v1, v2, v3);
}

inline  void 
Geometry::SetColorv(float *v)
{
  if(ColorNode==NULL)
    ColorNode=new Color(grawLib);

  ColorNode->SetValuev(v);
}

inline  void 
Geometry::SetColor(Color *C)
{
  if(ColorNode!=NULL)
    delete ColorNode;

  ColorNode=C;
}

inline  void 
Geometry::SetMaterial(Enum PName, float v1, float v2, float v3, float v4)
{
  if(MatNode==NULL)
    MatNode=new Material(grawLib);

  MatNode->SetValue(PName, v1, v2, v3, v4);
}

inline  void 
Geometry::SetMaterialv(Enum PName, float *v)
{
  if(MatNode==NULL)
    MatNode=new Material(grawLib);

  MatNode->SetValuev(PName, v);
}

inline  void 
Geometry::SetMaterial(Enum PName, float v)
{
  if(MatNode==NULL)
    MatNode=new Material(grawLib);

  MatNode->SetValue(PName, v);
}

inline  void 
Geometry::SetMaterial(Material *M)
{
  if(MatNode!=NULL)
    delete MatNode;
  M->ParentNode = (this);
  MatNode=M;
}

inline  void 
Geometry::SetTransform(Enum Pname, float *v, int Order)
{
  if(TransNode==NULL)
    TransNode=new Transformation(grawLib);

  TransNode->SetValuev(Pname, v, Order);
}

inline  void 
Geometry::SetTransform(Enum Pname, float x, float y, float z, int Order)
{
  if(TransNode==NULL)
    TransNode=new Transformation(grawLib);

  TransNode->SetValue(Pname, x, y, z, Order);
}

inline  void 
Geometry::SetTransform(Enum Pname, float a, float x, float y, float z, 
               int Order)
{
  if(TransNode==NULL)
    TransNode=new Transformation(grawLib);

  TransNode->SetValue(Pname, a, x, y, z, Order);
}


inline  void 
Geometry::SetTransform(Transformation *T)
{
  if(TransNode!=NULL)
    delete TransNode;

  T->ParentNode = (this);
  TransNode=T;
}

 

inline  void 
Geometry::Render()
{
    printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
}

class Line: public Geometry
{
 public:
  Line(GraphDrawLib *gLib){grawLib=gLib;LeftChild = RightSibling =NULL;};
  void SetVertices(float *, float *);
  void SetVerticesv(float v[][3]);
  void Render();

 private:
  float Vertices[2][3];
};


inline void
Line::SetVertices(float *v1, float *v2)
{
  int i;
  for(i=0; i<3; i++)
    {
      Vertices[0][i]=v1[i];
      Vertices[1][i]=v2[i];
    }
}

inline void
Line::SetVerticesv(float v[][3])
{
  SetVertices(v[0], v[1]);
}

inline void
Line::Render()
{
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
  {MatNode->nodespace = ParentNode->nodespace +"</-Line-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
  

  grawLib->glBegin(GL_LINES);
    grawLib->glVertex3fv(Vertices[0]);
    grawLib->glVertex3fv(Vertices[1]);
  grawLib->glEnd();  
    
  //glPopAttrib KH();
  
}


class Cube:public Geometry
{
 public:
  Cube(GraphDrawLib *gLib){grawLib=gLib;LeftChild = RightSibling =NULL;};
  Cube(float, float, float);
  void SetValue(Enum PName, float v);
  void Render();

 private:
  //  void Polygon(int a, int b, int c, int d);
  void Polygon(GLubyte *Index);
  float Height;
  float Width;
  float Depth;

};


Cube::Cube(float w, float h, float d)
{
  Width=w; Height=h; Depth=d;
}

inline void
Cube::SetValue(Enum PName, float v)
{
  switch(PName)
    {
    case WIDTH:
      Width=v;
      break;
    case HEIGHT:
      Height=v;
      break;
    case DEPTH:
      Depth=v;
      break;
    default:
      break;
    }
}


inline void
Cube::Polygon(GLubyte *Index)
{
  float x1=(-1)*(Width/2);
  float x2=(Width/2);
  float y1=(-1)*(Height/2);
  float y2=(Height/2);
  float z1=(-1)*(Depth/2);
  float z2=(Depth/2);

  
  GLfloat V[][3]={{x1, y1, z2},{x1, y2, z2},{x2, y2, z2},{x2, y1, z2},
          {x1, y1, z1},{x1, y2, z1},{x2, y2, z1},{x2, y1, z1}};

  grawLib->glBegin(GL_POLYGON);
    grawLib->glVertex3fv(V[Index[0]]);
    grawLib->glVertex3fv(V[Index[1]]);
    grawLib->glVertex3fv(V[Index[2]]);
    grawLib->glVertex3fv(V[Index[3]]);
  grawLib->glEnd();

}

inline void
Cube::Render()
{
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  int i;
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
  

  GLubyte CubeIndex[]={0, 3, 2, 1, 2, 3, 7, 6, 3, 0, 4, 7, 1, 2, 6, 5,
               4, 5, 6, 7, 5, 4, 0, 1};

  GLfloat N[][3]={{0, 0, 1},{1, 0, 0},{0, -1, 0},{0, 1, 0},
          {0, 0, -1},{-1, 0, 0}};

  //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  //glEnable(GL_COLOR_MATERIAL);
  printf("%s name:%s Cube_Draw_Polygon\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glutSolidSphere(1.0, 40, 40);
  for(i=0; i<6; i++)
    {
      grawLib->glNormal3f(N[i][0],N[i][1],N[i][2]);
      Polygon(&CubeIndex[i*4]);      
    }
	
  //glPopAttrib KH();
}



class Cylinder: public Geometry
{
 public:
  Cylinder(GraphDrawLib *gLib){grawLib=gLib;LeftChild = RightSibling =NULL;};
  void SetValue(Enum, float);
  void Render();

 private:
  float Height;
  float Radius;
};


inline void
Cylinder::SetValue(Enum Pname, float v)
{
  switch(Pname)
    {
    case HEIGHT:
      Height=v;
      break;
    case RADIUS:
      Radius=v;
      break;
    default:
      break;
    }
}

inline void
Cylinder::Render()
{
  printf("%s *name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
 
}

 

class Sphere: public Geometry
{
 public:
  Sphere(GraphDrawLib *gLib){grawLib=gLib;LeftChild = RightSibling =NULL;};
  Sphere(float R);
  void SetValue(Enum Pname, float v);
  void Render();

 private:
  float Radius;
};

inline Sphere::Sphere(float R)
{
  Radius=R;
}

inline void
Sphere::SetValue(Enum Pname, float v)
{
  if(Pname==RADIUS)
    Radius=v;
}

inline void
Sphere::Render()
{
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
  
  
  printf("%s<-*-> name:%s glutSolidSphere\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //KHtemp glutSolidSphere(Radius, 40, 40);

  //glPopAttrib KH();
}

class Polygon: public Geometry
{
 public:
  Polygon(GraphDrawLib *gLib){grawLib=gLib;LeftChild = RightSibling =NULL;};
  void SetVerticesv(float v[][3], int);
  void Render();

 private:
  float Vertices[1000][3];
  int Size;
};

inline void
Polygon::SetVerticesv(float v[][3], int S)
{
  int i, j;
  Size=S;

  for(i=0; i<S; i++)
    for(j=0; j<3; j++)
      Vertices[i][j]=v[i][j];
}

inline void
Polygon::Render()
{
  int i;
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-p-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
 

  printf("%s name draw GL_POLYGONs1:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  grawLib->glBegin(GL_POLYGON);
  for(i=0; i<Size; i++)
    grawLib->glVertex3fv(Vertices[i]);
  grawLib->glEnd();  
  
  //glPopAttrib KH();
  
}

//=============================================================
//=============================================================
/*
   Calculate RGB from HSV, reverse of RGB2HSV()
   Hue is in degrees
   Lightness is between 0 and 1
   Saturation is between 0 and 1
*/

Material *GetColorMat(double c1_h, double c1_s, double c1_v,GraphDrawLib *gLib)
{
	double sat_r, sat_g, sat_b;

   while (c1_h < 0)
      c1_h += 360;
   while (c1_h > 360)
      c1_h -= 360;

   if (c1_h < 120) {
      sat_r = (120 - c1_h) / 60.0;
      sat_g = c1_h / 60.0;
      sat_b = 0;
   } else if (c1_h < 240) {
      sat_r = 0;
      sat_g = (240 - c1_h) / 60.0;
      sat_b = (c1_h - 120) / 60.0;
   } else {
      sat_r = (c1_h - 240) / 60.0;
      sat_g = 0;
      sat_b = (360 - c1_h) / 60.0;
   }
   sat_r = std::min(sat_r,1.0);
   sat_g = std::min(sat_g,1.0);
   sat_b = std::min(sat_b,1.0);

   sat_r = (1 - c1_s + c1_s * sat_r) * c1_v;
   sat_g = (1 - c1_s + c1_s * sat_g) * c1_v;
   sat_b = (1 - c1_s + c1_s * sat_b) * c1_v;
   //==================================================
   Material *RobotMat=new Material(gLib);
   //Robot Value:
   RobotMat->SetValue(DIFFUSE, sat_r, sat_g, sat_b, 1.0);
   RobotMat->SetValue(AMBIENT, sat_r, sat_g, sat_b, 1.0);
   RobotMat->SetValue(SPECULAR, 1.0, 1.0, 1.0, 1.0);
   RobotMat->SetValue(SHININESS, 100.0);
   return RobotMat;
}
 
class StlShape: public Geometry
{
 public:
  StlShape(GraphDrawLib *gLib)
  {grawLib=gLib;
  LeftChild = RightSibling =NULL;
  nodename="stlkk";};
  void LoadStl(char*file);
  void SetVerticesv();
  void Render();
  std::vector<triangle>  facet;
 private:
  float Vertices[1000][3];
  int Size;
};

inline void StlShape::LoadStl(char*file)
{
 // getStlGeometryInput
 
  double  x_min,  x_max, y_min,  y_max, z_min, z_max;
  
   getStlGeometryInput(file, facet,
         x_min,x_max,y_min,y_max,z_min,z_max);

  printf("%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n", 
         x_min,  x_max, y_min,  y_max, z_min, z_max);
}

 

inline void
StlShape::Render()
{
  int i;
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);

  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-stl-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
 
  float xxx,yyy,zzz;
  printf("%s name draw GL_POLYGONs2:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());

 
  grawLib->glBegin(GL_TRIANGLES);
  for(int i = 0; i < facet.size(); i++)
  {    // 遍历三角形的所有点
      for(int whichVertex = 0; whichVertex < 3; whichVertex++ )
       {
      // 给出法向量
      
	  //xxx = facet[i].normal.x;
	  //yyy = facet[i].normal.y;
	  //zzz = facet[i].normal.z;
      grawLib->glNormal3f(facet[i].normal.x, facet[i].normal.y, facet[i].normal.z);
        // 如果对象具有纹理
      //int aa(0);
	  //aa++;
	  grawLib->glVertex3f( facet[i].point[whichVertex].x , 
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
  grawLib->glEnd();
  /*glBegin(GL_POLYGON);
  for(i=0; i<Size; i++)
    glVertex3fv(Vertices[i]);
  glEnd();  */
  
  //glPopAttrib KH();
  
}


//============================================================
class TextureSurface: public Geometry
{
 public:
  TextureSurface(){Pic.Load("timg.bmp");};
  void SetVerticesv(float v[][3], int);
  void Render();

 private:
  C24BitMap Pic;
  float Vertices[1000][3];
  int Size;
};

inline void
TextureSurface::SetVerticesv(float v[][3], int S)
{
  int i, j;
  Size=S;

  for(i=0; i<S; i++)
    for(j=0; j<3; j++)
      Vertices[i][j]=v[i][j];
}

#define GL_BGR 123456
#include "c24bitmap.h"
inline void
TextureSurface::Render()
{
  int i;
  printf("%s name:%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  //glPushAttrib KH(GL_ALL_ATTRIB_BITS);
  grawLib->glPushMatrix();
  
  if(ColorNode)
    ColorNode->Render();
  if(MatNode)
    {MatNode->nodespace = ParentNode->nodespace +"</-txt-/>"; MatNode->Render();}
  if(TransNode)
    TransNode->Render();
 
  printf("%s name draw GL_POLYGONs:3%s\n",(char*)nodespace.c_str(),(char*)nodename.c_str());
  
  int texture[1];
  grawLib->glGenTextures(1, (GLuint*)&texture[0]);
  grawLib->glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)

  grawLib->glTexImage2D(GL_TEXTURE_2D, 0, 3, Pic.Width, Pic.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, Pic.Buffer);
  grawLib->glEnable(GL_TEXTURE_2D);
  
  grawLib->glBegin(GL_POLYGON);
  
  grawLib->glTexCoord2f(0.0f, 0.0f); grawLib->glVertex3fv(Vertices[0]);	// Bottom Left Of The Texture and Quad
  grawLib->glTexCoord2f(1.0f, 0.0f); grawLib->glVertex3fv(Vertices[1]);	// Bottom Right Of The Texture and Quad
  grawLib->glTexCoord2f(1.0f, 1.0f); grawLib->glVertex3fv(Vertices[2]);	// Top Right Of The Texture and Quad
  grawLib->glTexCoord2f(0.0f, 1.0f); grawLib->glVertex3fv(Vertices[3]);	// Top Left Of The Texture and Quad
 
  grawLib->glEnd();  
  grawLib->glDisable(GL_TEXTURE_2D);
  grawLib->glPopMatrix();
 
  
}
#endif
