#include "g3dRenderSystem.h"


//------------------------------------------------------------------------------------------------
g3dRenderSystem::g3dRenderSystem(void)
{
	LC=0x0000;
}

//------------------------------------------------------------------------------------------------
g3dRenderSystem::~g3dRenderSystem(void)
{

	//������Ⱦ����
	delete m_RenderWindow;

	//�������е�g3dLightWrapper
	for(map<std::string,g3dLightWrapper*> ::iterator it=m_LightWrpMap.begin();
		it!=m_LightWrpMap.end();it++)
	{
		delete it->second;
	}
	//���
	m_LightWrpMap.clear();

}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::initGL()
{
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0 );
	glShadeModel(GL_SMOOTH);
	
	//��ʼ����������
	ColorValue ambient=m_pSceneManager->getAmbientColor();
	GLfloat arrayambient[4];
	arrayambient[0]=ambient.r;
	arrayambient[1]=ambient.g;
	arrayambient[2]=ambient.b;
	arrayambient[3]=ambient.a;//always 1.0f
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,arrayambient);
	
	//ʹ�ܶ�����Դ
	for (std::map<std::string,g3dLightWrapper*>::iterator it=m_LightWrpMap.begin();
		it!=m_LightWrpMap.end();it++)
	{
		enableLight(it->second);
		if(LC==8)
			break;
	}

	//Enable some properties of openGL
	glEnable(GL_COLOR_MATERIAL);		
	glEnable(GL_LIGHTING);	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);	
}

//------------------------------------------------------------------------------------------------
g3dRenderWindow* g3dRenderSystem::CreateRenderWindow(std::string name,unsigned int width,unsigned int height,HWND hwnd,bool helptoinitGLwindow)
{
	m_RenderWindow=new g3dRenderWindow(width,height,hwnd,helptoinitGLwindow);

	//�ж��Ƿ���Ҫ����opengl�Ĵ�������
	if(helptoinitGLwindow)
		m_RenderWindow->initGLWindow();

	return m_RenderWindow;
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::initRenderSystem()
{
	//��ʼ��LightWrapper
	for(std::map<std::string,g3dLight*>::iterator it=m_pSceneManager->m_LightMap.begin();it!=m_pSceneManager->m_LightMap.end();it++)
	{
		g3dLightWrapper* lightwrp=new g3dLightWrapper(it->second);
		m_LightWrpMap[lightwrp->m_Name]=lightwrp;
	}

	//��ʼ��opengl����
	initGL();

}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::setSceneManager(g3dSceneManager* scene)
{
	m_pSceneManager=scene;
}

//------------------------------------------------------------------------------------------------
g3dSceneManager* g3dRenderSystem::getSceneManager(void)
{
	return m_pSceneManager;
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::renderCameraProj(g3dCamera* cam)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();		
	if(cam->getProjectionType()==PT_PERSPECTIVE)
		gluPerspective(cam->getFOVy().valueDegrees(),cam->getAspect(),cam->getNearDist(),cam->getFarDist());
	else
	{
		//ortho ��Ҫ���
	}

}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::renderCameraView(g3dCamera* cam)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam->getPosition().x,cam->getPosition().y,cam->getPosition().z,
		cam->getLookat().x,cam->getLookat().y,cam->getLookat().z,
		cam->getUp().x,cam->getUp().y,cam->getUp().z  );
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::renderOneFrame(void)
{
	//openGL, clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	unsigned int viewportnum=m_RenderWindow->getNumViewports();
	//Render for each viewport in the render window
	//it is designed for picture-in-picture and multi-picture in one render window
	for(int i=0;i<viewportnum;i++)
	{
		g3dViewport* viewport=m_RenderWindow->getViewport(i);
		g3dCamera* cam=viewport->getCamera();
		loadViewport(viewport);
		renderCameraProj(cam);
		renderCameraView(cam);
		renderScene();
	}	
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::enableLight(g3dLightWrapper* light)
{
	assert(light!=NULL);

	//Ŀǰ�Թ���û���Ż���ȫ��ֻ��ʹ�ò�����8����Դ��openGL��������ƣ�
	if(LC<0x0008)
	{
		light->isActive=true;
		light->LightID=LC;

		//��������������Ӧ����
		switch (light->m_LightType)
		{
				//���Դ
		case g3dLight::LT_POINT:

			glLightfv(GL_LIGHT0+LC,GL_AMBIENT,light->m_LightAmbient);
			glLightfv(GL_LIGHT0+LC,GL_DIFFUSE,light->m_LightDiffuse);
			glLightfv(GL_LIGHT0+LC,GL_SPECULAR,light->m_LightSpecular);
			glLightfv(GL_LIGHT0+LC,GL_POSITION,light->m_LightPosition);
			//����˥�������趨
			glLightf(GL_LIGHT0+LC,GL_CONSTANT_ATTENUATION,light->getLight()->getAttenuationConstant());
			glLightf(GL_LIGHT0+LC,GL_LINEAR_ATTENUATION,light->getLight()->getAttenuationLinear());
			glLightf(GL_LIGHT0+LC,GL_QUADRATIC_ATTENUATION,light->getLight()->getAttenuationQuadric());

			break;

			//�����Թ�Դ
		case g3dLight::LT_DIRECTIONAL:

			glLightfv(GL_LIGHT0+LC,GL_AMBIENT,light->m_LightAmbient);
			glLightfv(GL_LIGHT0+LC,GL_DIFFUSE,light->m_LightDiffuse);
			glLightfv(GL_LIGHT0+LC,GL_SPECULAR,light->m_LightSpecular);
			glLightfv(GL_LIGHT0+LC,GL_POSITION,light->m_LightDirection);

			glLightf(GL_LIGHT0+LC,GL_CONSTANT_ATTENUATION,light->getLight()->getAttenuationConstant());
			glLightf(GL_LIGHT0+LC,GL_LINEAR_ATTENUATION,light->getLight()->getAttenuationLinear());
			glLightf(GL_LIGHT0+LC,GL_QUADRATIC_ATTENUATION,light->getLight()->getAttenuationQuadric());
			
			break;

			//�۹��
		case g3dLight::LT_SPOTLIGHT:

			glLightfv(GL_LIGHT0+LC,GL_AMBIENT,light->m_LightAmbient);
			glLightfv(GL_LIGHT0+LC,GL_DIFFUSE,light->m_LightDiffuse);
			glLightfv(GL_LIGHT0+LC,GL_SPECULAR,light->m_LightSpecular);
			glLightfv(GL_LIGHT0+LC,GL_POSITION,light->m_LightPosition);
			//���ھ۹�Ƶ��趨
			glLightf(GL_LIGHT0+LC,GL_CONSTANT_ATTENUATION,light->getLight()->getAttenuationConstant());
			glLightf(GL_LIGHT0+LC,GL_LINEAR_ATTENUATION,light->getLight()->getAttenuationLinear());
			glLightf(GL_LIGHT0+LC,GL_QUADRATIC_ATTENUATION,light->getLight()->getAttenuationQuadric());

			glLightf(GL_LIGHT0+LC,GL_SPOT_CUTOFF,light->getLight()->getSpotlightCutoff().valueDegrees());
			glLightf(GL_LIGHT0+LC,GL_SPOT_EXPONENT,light->getLight()->getSpotlightExponent());
			glLightfv(GL_LIGHT0+LC,GL_SPOT_DIRECTION,light->m_LightDirection);

			break;

		}
		//ʹ��
		glEnable(GL_LIGHT0+LC);
		LC++;
	}
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::renderScene( void )
{

	//Ŀǰ�Գ�������Ⱦ������������
	//һ����Ⱦ�����ݱȽ��٣�ȱ���������о�̬�������Ⱦ
	//����񷶥�������
	//����ȱ�������ݵ�ѡ�񣬺ܶ�û������Ұ��Χ�ڵ�ģ��Ҳ����Ⱦ

	if(m_pSceneManager!=NULL)
	{
		for (std::map<std::string,g3dSceneNode*>::iterator node=m_pSceneManager->m_SceneNodeMap.begin();
			node!=m_pSceneManager->m_SceneNodeMap.end();node++)
		{
			glPushMatrix();

			//ƽ��, ����� "TS_WORLD"
			//�õ�����������ϵͳ�µ�ԭ������
			Vector3 nullpos=node->second->_getDerivedPosition();
			glTranslatef(nullpos.x,nullpos.y,nullpos.z);

			//��ת, ����� "TS_WORLD"
			//�õ�����������ϵͳ�µ�node������ϵ��������Ԫ����ʾ
			Quaternion orientation=node->second->_getDerivedOrientation();
			Radian rad;
			Vector3 anxis;
			//ת��Ϊ��ת�����ת�Ƕ�
			orientation.ToAngleAxis(rad,anxis);
			glRotatef(rad.valueDegrees(),anxis.x,anxis.y,anxis.z);

			//����, ����� "TS_WORLD"
			//�õ�����������ϵͳ�µ���������
			Vector3 scale=node->second->_getDerivedScale();
			glScalef(scale.x,scale.y,scale.z);

			//��Ⱦ�ڽڵ��¹ҽӵ�����ģ��
			for (int i=0;i<node->second->getModelsNum();i++)
			{
				g3dModel* model=node->second->getModel(i);
				model->RenderModel();
			}

			glPopMatrix();
		}

	}
}

//------------------------------------------------------------------------------------------------
void g3dRenderSystem::loadViewport(g3dViewport* viewport)
{
	//���ӿڲ������и���
	viewport->updateDimensions();
	//����
	glViewport(viewport->getActualLeft(),viewport->getActualTop(),
						viewport->getActualWidth(),viewport->getActualHeight());
}
//------------------------------------------------------------------------------------------------