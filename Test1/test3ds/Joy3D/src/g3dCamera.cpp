#include "g3dCamera.h"


int g3dCamera::IDconst=0;

g3dCamera::g3dCamera(void)
	:
	m_ProjectionType(PT_PERSPECTIVE),
	m_FOVy(Radian(Radian::PI/4)),
	m_Aspect(1.3333f),
	m_NearDist(0.5f),
	m_FarDist(10000.0f),
	m_Bottom(0),
	m_Left(0),
	m_Right(0),
	m_Top(0),
	m_Position(0,1.5f,8),
	m_Up(Vector3::UNIT_Y),
	m_LookAt(0,0.5f,0)	,
	m_LookatChanged(true),
	m_ProjectChanged(true),
	m_AutoAspect(true)
{
	m_Name="Camera"+IDconst;
}

//------------------------------------------------------------------------------------------------
g3dCamera::g3dCamera(std::string name)
	:
	m_ProjectionType(PT_PERSPECTIVE),
	m_FOVy(Radian(Radian::PI/4)),
	m_Aspect(1.3333f),
	m_NearDist(0.5f),
	m_FarDist(10000.0f),
	m_Bottom(0),
	m_Left(0),
	m_Right(0),
	m_Top(0),
	m_Position(0,0,10),
	m_Up(Vector3::UNIT_Y),
	m_LookAt(0,0,0),
	m_LookatChanged(true),
	m_ProjectChanged(true),
	m_AutoAspect(true)
{
	m_Name=name;
}

//------------------------------------------------------------------------------------------------
g3dCamera::~g3dCamera(void)
{
}

//------------------------------------------------------------------------------------------------
bool g3dCamera::getProjectChanged(void)
{
	return m_ProjectChanged;
}

//------------------------------------------------------------------------------------------------
bool g3dCamera::getLookatChanged(void)
{
	return m_LookatChanged;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setLookatChanged(bool b)
{
	m_LookatChanged=b;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setProjectChanged(bool b)
{
	m_ProjectChanged=b;
}

//------------------------------------------------------------------------------------------------
bool g3dCamera::getAutoAspect(void)
{
	return m_AutoAspect;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setAutoAspect(bool b)
{
	m_AutoAspect=b;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setProjectionType(ProjectionType type)
{
	m_ProjectionType=type;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
ProjectionType g3dCamera::getProjectionType(void) const
{
	return m_ProjectionType;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setFOVy(Radian fovy)
{
	m_FOVy=fovy;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setFOVy(Degree fovy)
{
	m_FOVy=fovy.valueRadians();
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
Radian g3dCamera::getFOVy(void) const
{
	return m_FOVy;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setFarDist(float fardis)
{
	m_FarDist=fardis;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setNearDist(float neardis)
{
	m_NearDist=neardis;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getFarDist(void) const
{
	return m_FarDist;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getNearDist(void) const
{
	return m_NearDist;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setAspect(float aspect)
{
	m_Aspect=aspect;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getAspect(void) const
{
	return m_Aspect;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setLeft(float left)
{
	m_Left=left;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setRight(float right)
{
	m_Right=right;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setBottom(float bottom)
{
	m_Bottom=bottom;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setTop(float top)
{
	m_Top=top;
	m_ProjectChanged=true;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getLeft(void) const
{
	return m_Left;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getRight(void) const
{
	return m_Right;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getTop(void) const
{
	return m_Top;
}

//------------------------------------------------------------------------------------------------
float g3dCamera::getBottom(void) const
{ 
	return m_Bottom;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setPosition(Vector3 pos)
{
	m_Position=pos;
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setPosition(float x,float y,float z)
{
	setPosition(Vector3(x,y,z));
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setUp(Vector3 up)
{
	m_Up=up;
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::setUp(float x,float y,float z)
{
	setUp(Vector3(x,y,z));
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::lookat(Vector3 lookat)
{
	m_LookAt=lookat;
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::lookat(float x,float y,float z)
{
	lookat(Vector3(x,y,z));
	m_LookatChanged=true;
}

//------------------------------------------------------------------------------------------------
Vector3 g3dCamera::getPosition(void) const
{
	return m_Position;
}

//------------------------------------------------------------------------------------------------
Vector3 g3dCamera::getUp(void) const
{
	return m_Up;
}

//------------------------------------------------------------------------------------------------
Vector3 g3dCamera::getLookat(void) const
{
	return m_LookAt;
}

//------------------------------------------------------------------------------------------------
void g3dCamera::IntelLookat(g3dModel* model)
{

	//�õ�ģ��bounding box�Ľ������������Ͱ뾶
	Vector3 center=model->getSphereCenter();
	Vector3 max=model->getBoundingBoxMax();
	Vector3 min=model->getBoundingBoxMin();
	float radius=model->getSphereRadius();

	//��center
	lookat(center);

	//���ô�ֱ�ӽ�Ϊ60��
	setFOVy(Degree(60.0));

	//�ڴ�ֱ�ӽ���60�ȵ�ǰ���£��۲�㣨position����������Ӧ�����������뾶
	//�۲����Ϊcenter��z�ᣨ��ֱ����Ļ��ƽ�������뾶��ĵ㡣
	setPosition(center.x,center.y,center.z+2.0f*radius);

	//��ƽ��ͷ��Ľ�Զ����ľ��������������֤ģ�͵�ȫ�����ݽ���ƽ��ͷ��
	//��Ϊ�Ͻ����汻��ʼ��Ϊ0.5f���ʲ��õ�����
	setFarDist(3*radius);

}