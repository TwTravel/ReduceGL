//GLViewer.h
#ifndef GLVIEWER_H
#define GLVIEWER_H

#include "Node.h"

class GLViewer
{
 public:
  GraphDrawLib *grawLib;
  GLViewer();
  ~GLViewer();

  void CreateWin(char *Name, int Width, int Height);

  //set buffer, backcolor
  void SetValue(Enum PName, Enum Type);
  void Init(int argc, char **argv);
  void Show(Node *N);

 //private:
  void GLInit();
  int ViewerIndex;
  char *WinName;
  float BackColor[3];

  static Node *Root[3];
  static int ViewerNum;
  static int BufType[3];
  static int WinWidth[3];
  static int WinHeight[3];
  static void Reshape0(int w, int h);
  static void Display0();
  static void Reshape1(int w, int h);
  static void Display1();
  static void Reshape2(int w, int h);
  static void Display2();
  
};

GLViewer::GLViewer()
{
  int i;

  ViewerIndex=ViewerNum;
  ViewerNum++;

  WinName="";
  BufType[ViewerIndex]=GLUT_SINGLE;
  Root[ViewerIndex]=NULL;
  for(i=0; i<3; i++)
    BackColor[i]=0.0;
}

GLViewer::~GLViewer()
{
  if(Root[ViewerIndex])
    {
      delete Root[ViewerIndex];
      Root[ViewerIndex]=NULL;
    }
}

void
GLViewer::Init(int argc, char **argv)
{
   
}

void 
GLViewer::CreateWin(char *Name, int Width, int Height)
{
  WinName=Name;
  WinWidth[ViewerIndex]=Width;
  WinHeight[ViewerIndex]=Height;
}

void
GLViewer::SetValue(Enum PName, Enum Type)
{
  switch(PName)
    {
    case BUFFER:
      if(Type==DOUBLE)
	BufType[ViewerIndex]=GLUT_DOUBLE;
      else if(Type==SINGLE)
	BufType[ViewerIndex]=GLUT_SINGLE;
      break;
    case BACKCOLOR:
      Root[ViewerIndex]->GetColor(Type, BackColor);
      break;
    default:
      break;
    }
}

void
GLViewer::Show(Node *N)
{
  GLInit();
  Root[ViewerIndex]=N;
 
}

//private
void 
GLViewer::GLInit()
{
  grawLib->glEnable(GL_DEPTH_TEST);
  grawLib->glClearColor(BackColor[0], BackColor[1], BackColor[2], 1.0);
}

void
GLViewer::Display0()
{printf("=============================================\n");
  grawLib->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Root[0]->Traverse();
  
  //grawLib->glFlush();
}


void
GLViewer::Reshape0(int w, int h)
{
  grawLib->glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  WinWidth[0]=w;
  WinHeight[0]=h;
}

void
GLViewer::Display1()
{printf("--------------------------------------------\n");
  grawLib->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Root[1]->Traverse();
  //grawLib->glFlush();
}

void
GLViewer::Reshape1(int w, int h)
{
  grawLib->glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  WinWidth[1]=w;
  WinHeight[1]=h;
}

void
GLViewer::Display2()
{ printf("++++++++++++++++++++++++++++++++++++++++++++");
  grawLib->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Root[2]->Traverse();
 
}

void
GLViewer::Reshape2(int w, int h)
{
  grawLib->glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  WinWidth[2]=w;
  WinHeight[2]=h;
}


#endif
