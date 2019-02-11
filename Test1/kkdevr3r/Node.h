//Node.h 
//#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <string>
#ifndef NODE_H
#define NODE_H
#include "gl.h"

using namespace std;

enum Enum
{
  PERSPECTIVE, ORTHO, POSITION, AIMAT, UPDIRECTION, ASPECT,
  NEAR, FAR, YANGLE,
  BLACK, WHITE, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GREY,
  WIDTH, HEIGHT,DEPTH,
  AMBIENT, DIFFUSE, SPECULAR, SPOT_DIRECTION, DROPOFFRATE,
  CUTOFFANGLE, EMISSION, SHININESS,
  TRANSLATION, ROTATION, SCALE,
  BUFFER, SINGLE, DOUBLE,
  RADIUS,
  STYLE, POINTSIZE, LINEWIDTH, FILLED, LINE, POINT,
  BACKCOLOR
};

class Node
{
 public:
  GraphDrawLib *grawLib;
  Node(){LeftChild = RightSibling = NULL;};
  Node(GraphDrawLib *gLib);
  virtual ~Node();
  virtual void Render();
  void AddChild(Node *);
  Node *ParentNode;
  string nodename;
  string nodespace;
  
 protected:
  void GetColor(Enum, float *);
  bool KeepMatrix; 

// private:
  void Traverse();
  
  Node *LeftChild;
  Node *RightSibling;
 
  friend class GLViewer;
};

inline void 
Node::Traverse()
{
  if(!KeepMatrix)
    grawLib->glPushMatrix();
 
 if(ParentNode!=NULL)
   nodespace = ParentNode->nodespace +"<--->";
   Render();
  
  if(LeftChild!=NULL)
  {  
	  
	  try{
        printf("try left %s\n",this->nodename.c_str());
	    LeftChild->Traverse();
	  }
	  catch(...)
	  {
		  int aa;aa=5;
	  }
  }
  if(!KeepMatrix)
    grawLib->glPopMatrix();
  if(RightSibling!=NULL)
  {   
	  try
	  {
		printf("try right %s\n",this->nodename.c_str());
		RightSibling->Traverse();
	  }
     catch(...)
	  {int aa;aa=5;
	  }
  }
  printf("finish %s\n",this->nodename.c_str());
}

inline void
Node::AddChild(Node *node)
{
  if(LeftChild==NULL)
    LeftChild=node;
  else
    {
      node->RightSibling=LeftChild;
      LeftChild=node;
    }
  node->ParentNode = this;
  //node->nodespace = nodespace + " --- " + node->nodespace;
}

inline Node::Node(GraphDrawLib *gLib)
{
  KeepMatrix=false;
  LeftChild=NULL;
  RightSibling=NULL;
  nodename="";
  nodespace="";
  ParentNode=NULL;
  this->grawLib = gLib;
  LeftChild = RightSibling =NULL;
}

inline Node::~Node()
{
  printf("===%s\n", (char*)nodename.c_str());
  if(LeftChild)
    delete LeftChild;
  LeftChild=NULL;
  if(RightSibling)
    delete RightSibling;
  RightSibling=NULL;
}

inline void
Node::GetColor(Enum Color, float *C)
{
  int i;

  switch(Color)
    {
    case BLACK:
      C[0] = C[1] = C[2] = 0.0;
      break;
    case WHITE:
      C[0] = C[1] = C[2] = 1.0;
      break;
    case RED:
      C[0]=1.0; C[1]=0.0; C[2]=0.0;
      break;
    case GREEN:
      C[0]=0.0; C[1]=1.0; C[2]=0.0;
      break;
    case YELLOW:
      C[0]=1.0; C[1]=1.0; C[2]=0.0;
      break;
    case BLUE:
      C[0]=0.0; C[1]=0.0; C[2]=1.0;
      break;
    case MAGENTA:
      C[0]=1.0; C[1]=0.0; C[2]=1.0;
      break;
    case CYAN:
      C[0]=0.0; C[1]=1.0; C[2]=1.0;
      break;
    case GREY:
      C[0]=0.2; C[1]=0.2; C[2]=0.2;
      break;

    default:
      break;
    }
}


inline void
Node::Render()
{ }


#endif  
