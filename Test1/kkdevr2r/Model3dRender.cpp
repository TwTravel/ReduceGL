#include <stdio.h>
#include <stdlib.h>
#include "read_cfg.h"
#include "Scene.h"

 string trim(const string& str)
{
    string::size_type pos = str.find_first_not_of(' ');
    if (pos == string::npos)
    {
        return str;
    }
    string::size_type pos2 = str.find_last_not_of(' ');
    if (pos2 != string::npos)
    {
        return str.substr(pos, pos2 - pos + 1);
    }
    return str.substr(pos);
}

//int ui_loop(int argc, char **argv, const char *name);

void init( GraphDrawLib *grawLib)
{
   static GLfloat pos[4] = {5.0, 5.0, 10.0, 0.0 };
   static GLfloat red[4] = {0.8, 0.1, 0.0, 1.0 };
   static GLfloat green[4] = {0.0, 0.8, 0.2, 1.0 };
   static GLfloat blue[4] = {0.2, 0.2, 1.0, 1.0 };

   grawLib->glLightfv( GL_LIGHT0, GL_POSITION, pos );
   grawLib->glEnable( GL_CULL_FACE );
   grawLib->glEnable( GL_LIGHTING );
   grawLib->glEnable( GL_LIGHT0 );
   grawLib->glEnable( GL_DEPTH_TEST );


   grawLib->glEnable( GL_NORMALIZE );
}

/* new window size or exposure */
void reshape( GraphDrawLib *grawLib, int width, int height )
{
   GLfloat  h = (GLfloat) height / (GLfloat) width;

   grawLib->glViewport(0, 0, (GLint)width, (GLint)height);
   grawLib->glMatrixMode(GL_PROJECTION);
   grawLib->glLoadIdentity();
   grawLib->glFrustum( -1.0, 1.0, -h, h, 5.0, 60.0 );
   grawLib->glMatrixMode(GL_MODELVIEW);
   grawLib->glLoadIdentity();
   grawLib->glTranslatef( 0.0, 0.0, -40.0 );
   //KH_add grawLib->glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

 

class VWordModel
{
  public:
  VWordModel(GraphDrawLib*gLib);
  ~VWordModel();
  Camera *Camera1 ;
  Transformation *SysTrans  ;
  vector< Light *> Lights; 
  vector< StlShape *      > StlElements;// = new StlShape[ element_num ];
  vector< Transformation *> StlTrans;//    = new Transformation[ element_num ];
  Polygon  *AxisXX  ;                              
  Polygon  *AxisYY  ;                              
  Polygon  *AxisZZ  ;                              
  Node *Root ;
  GLViewer *MyViewer ;
  TextureSurface* groundface  ;
  Transformation* texsurface_trs;
  int LightIdx;
};

VWordModel::VWordModel(GraphDrawLib*gLib)
{
  Camera1  = new Camera(gLib, PERSPECTIVE);
  SysTrans = new Transformation(gLib);
  LightIdx = 0;
  //Light1   = new Light(gLib);
  //StlShape       *StlElements = new StlShape[ element_num ];
  //Transformation *StlTrans    = new Transformation[ element_num ];
  AxisXX = new Polygon(gLib);  AxisXX->nodename ="AxisXX = new Polygon";                             
  AxisYY = new Polygon(gLib);  AxisYY->nodename ="AxisYY = new Polygon";                             
  AxisZZ = new Polygon(gLib);  AxisZZ->nodename ="AxisZZ = new Polygon";                             
  Root   = new Node;     Root  ->nodename ="Root";
  Root->grawLib = gLib;
  MyViewer = new GLViewer;// MyViewer ->nodename = "Viewer";
  groundface = new TextureSurface;
  texsurface_trs = new Transformation(gLib);
  //= Light1->grawLib
  Camera1->grawLib = SysTrans->grawLib  = AxisXX->grawLib =
	AxisYY->grawLib = AxisZZ->grawLib = Root->grawLib = MyViewer->grawLib =
	groundface->grawLib =  texsurface_trs->grawLib = gLib;
}

VWordModel::~VWordModel()
{
	return;
}

GraphDrawLib graphLib;
VWordModel world_model(&graphLib);

void ReadModelFile(int argc, char *argv[])
{
	 printf("hello\n");
  std::vector<std::string> lines;
  readlistfile(argv[1],  lines); 
  /*CAMERA_POS, 2.2, 0.9, 3, 50 , #posx posy posz angle
   SYSROTATION, -90,  1, 0 ,0, 0
   SYSTRANSLTN, -0.5, 0, 0, 2, 0
bunny.stl, 10.0, 1.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 4 , #OBJ(color3)(pos3)(rot4)(scale1)
bunny.stl, 40.0, 1.0, 1.0, -10, 0, 0, 0, 0, 0, 0, 2,#OBJ(color3)(pos3)(rot4)(scale1)  
bunny.stl, 50.0, 1.0, 1.0, 10, 0, 0, 0, 0, 0,  0,  3,#OBJ(color3)(pos3)(rot4)(scale1)   
  */
    float vx[][3]={{0,  -0.003, 0.0},{100, -0.003, 0.0},
		         {100, 0.003, 0.0},{  0,  0.003, 0.0} };

    float vy[][3]={ {-0.003,  0, 0.0 } ,{  0.003,   0, 0.0}, 
	                {0.003 ,100, 0.0},  {-0.003, 100, 0.0}};		
		
    float vz[][3]={{-0.003,  0, 0.0},{ -0.003,  0, 100.0}, 
                 	{0.003 ,0, 100.0},{  0.003,   0, 0.0} };	
  
   int i;
   double  camx, camy, camz, campov;
   double  rot_angle,rot_x,rot_y,rot_z;
   double  trans_x,trans_y,trans_z;
   
   std::vector<std::string> strvec;
 
//##################################################################
//################################################################## 
   strvec.clear(); splitString(lines[0], strvec, ",");
   
   camx   = atof( trim(strvec[1]).c_str());
   camy   = atof( trim(strvec[2]).c_str() );
   camz   = atof( trim(strvec[3]).c_str() );
   campov = atof( trim(strvec[4]).c_str() );  
   
   
   
   world_model.Camera1->SetValue(POSITION, camx, camy, camz);
   world_model.Camera1->SetValue(AIMAT, 0, 0, 0);
   world_model.Camera1->SetValue(UPDIRECTION, 0, 1, 0);
   world_model.Camera1->SetValue(ASPECT, 1);
   world_model.Camera1->SetValue(NEAR, 0.1);
   world_model.Camera1->SetValue(FAR, 200);
   world_model.Camera1->SetValue(YANGLE, campov); 
   world_model.Camera1->nodename="Camera1";
   
//##################################################################
//##################################################################  
   strvec.clear(); splitString(lines[1], strvec, ","); 
   rot_angle   = atof( trim(strvec[1]).c_str() );
   rot_x       = atof( trim(strvec[2]).c_str() );
   rot_y       = atof( trim(strvec[3]).c_str() );
   rot_z       = atof( trim(strvec[4]).c_str() ); 
   strvec.clear(); splitString(lines[2], strvec, ","); 
   trans_x = atof( trim(strvec[1]).c_str() );
   trans_y = atof( trim(strvec[2]).c_str() );
   trans_z = atof( trim(strvec[3]).c_str() );
   
  
   
   world_model.SysTrans->SetValue(ROTATION, rot_angle,rot_x, rot_y, rot_z,0);
   world_model.SysTrans->SetValue(TRANSLATION, trans_x,  trans_y, trans_z, 2);
//##################################################################
//##################################################################  
   int element_num = lines.size() - 3 ;
   world_model.StlElements.resize(element_num); 
   Loopi(element_num) { world_model.StlElements[i] = new StlShape(&graphLib);
                        //world_model.StlElements[i]->grawLib=&graphLib;
                        }
   world_model.StlTrans.resize(element_num);    
   Loopi(element_num) {world_model.StlTrans[i]    = new Transformation(&graphLib);
                       //world_model.StlTrans[i]->grawLib=&graphLib;
                      }
     //StlShape       *StlElements = new StlShape[ element_num ];
  //Transformation *StlTrans    = new Transformation[ element_num ];
   
   
   //world_model.Light1->SetValue(POSITION,  2, -1,  1.8, 1);
   //world_model.Light1->SetValue(SPOT_DIRECTION, -2, 1, -1.8);
   //world_model.Light1->SetValue(CUTOFFANGLE, 180.0);
   //world_model.Light1->TurnOn();     world_model.Light1->nodename="Light1";
  

  
   world_model.AxisXX->SetVerticesv(vx, 4); world_model.AxisXX->SetMaterial(GetColorMat(360*0.0/8.0, 1.0, 1.0,&graphLib));  
   world_model.AxisYY->SetVerticesv(vy, 4); world_model.AxisYY->SetMaterial(GetColorMat( 120.0 , 1.0, 1.0,&graphLib));
   world_model.AxisZZ->SetVerticesv(vz, 4); world_model.AxisZZ->SetMaterial(GetColorMat( 240.0 , 1.0, 1.0,&graphLib));
   
   //===================================================================================
   /*strvec.clear(); splitString(lines[3], strvec, ",");
   
    
	float vground[4][3];//={{0, 0, 0},{ 0.115 ,  0,  0},
                       //{0.115 , 0.115 , 0},{  0,  0.115 , 0} };
	double offsetx(0), offsety(0), offsetz(0);//, offsetx(0), offsety(0), offsetz(0);
	if(strvec.size()>13)
	{ 
      offsetx = atof(trim(strvec[12]).c_str());;;
      offsety = atof(trim(strvec[13]).c_str());;;
	  offsetz = atof(trim(strvec[14]).c_str());;;
	  
	  rot_angle   = atof( trim(strvec[15]).c_str() );
      rot_x       = atof( trim(strvec[16]).c_str() );
      rot_y       = atof( trim(strvec[17]).c_str() );
      rot_z       = atof( trim(strvec[18]).c_str() ); 
	}
    for( i = 0; i <  4; i++ )
	{
		vground[i][0] = atof(trim(strvec[0+3*i]).c_str()) ;//+ offsetx;;
		vground[i][1] = atof(trim(strvec[1+3*i]).c_str()) ;//+ offsety;;
		vground[i][2] = atof(trim(strvec[2+3*i]).c_str()) ;//+ offsetz;;
	}
   
   world_model.groundface->SetVerticesv(vground,4);
   // groundface->SetVerticesv(vx, 4);
   world_model.groundface->SetMaterial(GetColorMat(360*0.0/8.0, 1.0, 1.0 ,&graphLib));
   
   world_model.texsurface_trs->SetValue(TRANSLATION , offsetx, offsety, offsetz , 1);
   world_model.texsurface_trs->SetValue(ROTATION    , rot_angle, rot_x,  rot_y, rot_z, 0);
   world_model.groundface->SetTransform( world_model.texsurface_trs);*/
   //world_model.StlTrans[i]->SetValue(SCALE       , obj_scale, obj_scale, obj_scale,2); 
   //====================================================================================
   int stlIdx =0;
   for( i = 0; i <  element_num; i++ )
   {
	   strvec.clear(); splitString(lines[3+i], strvec, ",");
	   
	   if(trim(strvec[0])=="STL")
	   {
	   double  mat_h, mat_s, mat_v;
	   double  obj_x, obj_y, obj_z;
       double  rot_angle, rot_x, rot_y, rot_z , obj_scale;	   
	   string  fname;
	   fname = strvec[0+1];
	   mat_h = atof(trim(strvec[1+1]).c_str());
	   mat_s = atof(trim(strvec[2+1]).c_str());
	   mat_v = atof(trim(strvec[3+1]).c_str());
	   
	   obj_x = atof(trim(strvec[4+1]).c_str());
	   obj_y = atof(trim(strvec[5+1]).c_str());
	   obj_z = atof(trim(strvec[6+1]).c_str());
	   
	   rot_angle =  atof(trim(strvec[ 7+1]).c_str());
	   rot_x     =  atof(trim(strvec[ 8+1]).c_str());
	   rot_y     =  atof(trim(strvec[ 9+1]).c_str());
	   rot_z     =  atof(trim(strvec[10+1]).c_str());
	   obj_scale =  atof(trim(strvec[11+1]).c_str()); 
	   
	   printf("##########################trans: %.2f,  %.2f,  %.2f\n", obj_x ,    obj_y,  obj_z);
	   if(rot_angle!=0)
	   world_model.StlTrans[stlIdx]->SetValue(ROTATION    , rot_angle, rot_x,  rot_y, rot_z, 0);
	   world_model.StlTrans[stlIdx]->SetValue(TRANSLATION , obj_x ,    obj_y,  obj_z  , 1);
	   world_model.StlTrans[stlIdx]->SetValue(SCALE       , obj_scale, obj_scale, obj_scale,2); 
	   
	   world_model.StlElements[stlIdx]->SetTransform( world_model.StlTrans[stlIdx]);
       world_model.StlElements[stlIdx]->LoadStl((char*)trim(fname).c_str());
       world_model.StlElements[stlIdx]->SetMaterial(GetColorMat(mat_h, mat_s, mat_v ,&graphLib));  //GetColorMat(360*0.0/8.0, 1.0, 1.0 ));//
       
	   stlIdx ++;
	   //world_model.SysTrans->AddChild( world_model.StlElements[i]);
	   world_model.SysTrans->nodename ="XXX";
	   printf( "%s\n", trim(lines[i]).c_str() );
	   }

	   if(trim(strvec[0])=="LIGHT")
	   {
		   double light_x, light_y, light_z;
		   light_x = atof(trim(strvec[ 1 ]).c_str());
		   light_y = atof(trim(strvec[ 2 ]).c_str());
		   light_z = atof(trim(strvec[ 3 ]).c_str());
           Light * Light1   = new Light(&graphLib);
		   Light1->SetValue(POSITION,  light_x, light_y, light_z, 1);
		   Light1->SetValue(SPOT_DIRECTION, -light_x, -light_y, -light_z);
		   Light1->SetValue(CUTOFFANGLE, 180.0);
		   Light1->TurnOn();   char lightname[40];
		   sprintf(lightname,"Light_%i", world_model.LightIdx); Light1->nodename=lightname;
		   world_model.Lights.push_back(Light1);
		   world_model.LightIdx ++;
	   }
   }
  
   

   world_model.SysTrans->AddChild(world_model.StlElements[0]);
    for( i = 0; i <  (element_num-1); i++ )
	  world_model.StlElements[i]->AddChild(world_model.StlElements[i+1]);
  
  world_model.SysTrans->AddChild( world_model.AxisXX);
  world_model.SysTrans->AddChild( world_model.AxisYY);
  world_model.SysTrans->AddChild( world_model.AxisZZ);
  world_model.SysTrans->AddChild( world_model.groundface);
   
  
  
  world_model.Root->AddChild( world_model.SysTrans);


  for(i=0;i< world_model.Lights.size();i++)
  {
	  world_model.SysTrans->AddChild( world_model.Lights[i]);
  }
  
  
  //Root->AddChild(Light1);
  //Light1->AddChild(SysTrans);
  world_model.Root->AddChild( world_model.Camera1);  world_model.Root ->nodename="root node";
  
  //Viewer:
}

void reshape(int width, int height)		
{
	if (height==0)										
	{
		height=1;										
	}

	graphLib.glViewport(0,0,width,height);						

	graphLib.glMatrixMode(GL_PROJECTION);		
	graphLib.glLoadIdentity();						
	graphLib.gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, .5f ,150.0f);

	graphLib.glMatrixMode(GL_MODELVIEW);						
	graphLib.glLoadIdentity();									
}
int main(int argc, char *argv[])
{
 // ui_loop(argc, argv, "models");
  graphLib.InitDrawLib(1600,1600);
  reshape(1600, 1600);
  init( &graphLib);
  ReadModelFile( argc,  argv );
  world_model.MyViewer->Init(argc, argv);
  world_model.MyViewer->SetValue(BACKCOLOR, GREY);
  world_model.MyViewer->SetValue(BUFFER, DOUBLE);
  world_model.MyViewer->CreateWin("Working Hard", 1600, 1600);
   
  world_model.MyViewer->Show( world_model.Root);
  world_model.MyViewer->Display0();
 // tkSwapBuffers();
  graphLib.gl_ctx.glXSaveRenderImg("imgok.bmp");
  graphLib.glClose();
  return 1;
}
