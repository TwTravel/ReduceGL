#pragma once
#include "g3dBasicHeader.h"
#include "g3dSceneNode.h"

/************************************************************************
����FOV��Aspect��

	Aspect ratio (y:x) = y / x = (tan (vertical FOV / 2) ) / (tan (horizontal FOV / 2) )

	horizontal FOV = 2 * arc tan ( tan (vertical FOV / 2) * (x / y) )

	vertical FOV = 2 * arc tan ( tan (horizontal FOV / 2) * (y / x) )
************************************************************************/

///ͶӰģʽö������
enum ProjectionType
{
	PT_ORTHOGRAPHIC,
	PT_PERSPECTIVE
};

/*********************************************
@������g3dCamera
@�����������
@˵�������������Ҫ�������������Ϣ
			   1.  ��ͶӰ��صģ�ƽ��ͷ�壬�������ͶӰģʽ
			   2. ����ͼ�任��صģ�up������position��λ�ã��۲�㣩��lookat
@�޸���ʷ���߼��2012/8/14������
*********************************************/
class g3dCamera
{
public:
	/**Ĭ�Ϲ��캯��
	@˵������������Ĺ��캯�����������ڣ�Ĭ�Ϲ��캯������IDcount���ɣ�
				   Ĭ�����ƣ����������𣬾����ʼ����Ϣ�μ�����ʵ��
	
	@��������

	@�޸���ʷ���߼��2012/8/14������
	*/
	g3dCamera(void);

	/**���캯��
	@˵������Ĭ�Ϲ��캯�����������ڣ�Ĭ�Ϲ��캯������IDcount���ɣ�
	Ĭ�����ƣ����������𣬾����ʼ����Ϣ�μ�����ʵ��
	
	@������name��string���ͣ���������

	@�޸���ʷ���߼��2012/8/14������
	*/
	g3dCamera(std::string name);

	/**��������
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	~g3dCamera(void);

	/**����Projection��ͶӰ��ģʽ
	@˵������Ⱦ������ͶӰģʽѡ������ͶӰ��͸��ͶӰ
	
	@������type��ProjectionType
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setProjectionType(ProjectionType type);

	/**�õ���ǰͶӰģʽ
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	ProjectionType getProjectionType(void) const;

	/**���ô�ֱFOV��field of view��
	@˵��������FOV�������μ����˵����m_FOV��˵��
	
	@������fovy��Radian
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setFOVy(Radian fovy);

	/**���ô�ֱFOV��field of view��
	@˵��������FOV�������μ����˵����m_FOV��˵��
	
	@������fovy��Degree
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setFOVy(Degree fovy);

	/**�õ���ֱFOV��field of view������ֱ�ӽ�
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@��������
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	Radian getFOVy(void)const;

	/**����ƽ��ͷ���н�Զ����۲��ľ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@������far��float
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setFarDist(float far);

	/**����ƽ��ͷ���нϽ�����۲��ľ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@������far��near
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setNearDist(float near);

	/**�õ�ƽ��ͷ���н�Զ����۲��ľ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@��������
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	float getFarDist(void)const;

	/**�õ�ƽ��ͷ���нϽ�����۲��ľ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@��������
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	float getNearDist(void)const;

	/**����ƽ��ͷ���еĿ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@������aspect��float
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setAspect(float aspect);

	/**�õ�ƽ��ͷ���еĿ���
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵��
	
	@������aspect��float
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	float getAspect(void)const;

	/**����ƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���е�������
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵����
				   ���������꣬���Կ�glOrtho()�Ĳ���˵����glFrustum()�Ĳ���˵��
	
	@������left��float
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	
	void setLeft(float left);

	/**����ƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���е�������
	@˵��������ƽ��ͷ��������μ����˵���͸�����Ա�����˵����
				   ���������꣬���Կ�glOrtho()�Ĳ���˵����glFrustum()�Ĳ���˵��
	
	@������right��float
	
	@�޸���ʷ���߼��� ��2012/8/14������
	*/
	void setRight(float right);

	/**����ƽ��ͷ��ĵ�
	
	@˵������
	
	@������bottom��float
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setBottom(float bottom);
	
	/**����ƽ��ͷ��Ķ�
	
	@˵������
	
	@������top��float
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setTop(float top);
	
	/**�õ���ǰƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���е�������
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	float getLeft(void)const;
	
	/**�õ���ǰƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���е�������
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	float getRight(void)const;
	
	/**�õ���ǰƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���еĶ�����
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	float getTop(void)const;
	
	/**�õ���ǰƽ��ͷ�壨����͸��ͶӰ���򳤷��壨��������ͶӰ���еĵ�����
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	float getBottom(void) const;
	
	/**���������λ��
	
	@˵������
	
	@������pos��Vector3
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setPosition(Vector3 pos);

	/**���������λ��
	
	@˵������
	
	@������x:float, y:float ,z:float 
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setPosition(float x,float y,float z);
	
	/**��������������Ϸ��������
	
	@˵������
	
	@������up��Vector3
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setUp(Vector3 up);
	
	/**��������������Ϸ��������
	
	@˵������
	
	@������x:float, y:float ,z:float 
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setUp(float x,float y,float z);
	
	/**��������������߷���
	
	@˵������
	
	@������lookat:Vector3
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void lookat(Vector3 lookat);
	
	/**��������������߷���
	
	@˵������
	
	@������x:float, y:float ,z:float 
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void lookat(float x,float y,float z);
	
	/**ȡ�õ�ǰ�����λ��
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	Vector3 getPosition(void) const;
	
	/**ȡ�õ�ǰ��������Ϸ�������
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	Vector3 getUp(void) const;
	
	/**ȡ�õ�ǰ��������߷���
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	Vector3 getLookat(void) const;
	
	/**ȡ�ñ�־ͶӰ�仯�Ĳ���ֵ
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	bool getProjectChanged(void);
	
	/**ȡ�ñ�־��ͼ�仯�Ĳ���ֵ
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	bool getLookatChanged(void);
	
	/**���ñ�־ͶӰ�仯�Ĳ���ֵ
	
	@˵������
	
	@������b:bool
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setProjectChanged(bool b);
	
	/**���ñ�־��ͼ�仯�Ĳ���ֵ
	
	@˵������
	
	@������b��bool
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setLookatChanged(bool b);
	
	/**ȡ�ñ�־�Զ����¿��ȵĲ���ֵ
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	bool getAutoAspect(void);
	
	/**���ñ�־�Զ����¿��ȵĲ���ֵ
	
	@˵������
	
	@������b��bool
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void setAutoAspect(bool b);

	/**���ݸ���model���ܵ��趨�����������ʹ��������Ļ�д�С����

	@˵����ÿ��model����һ���������������BoundingBox���˺�����
					������Щ�����������Լ���position��up��lookat�������㷨
					�μ�����ʵ��
	
	@������model��g3dModel*
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	void IntelLookat(g3dModel* model);

public:
	///���������
	std::string m_Name;

private:

	///ID������
	static int IDconst;
	
	bool m_ProjectChanged;
	bool m_LookatChanged;
	bool m_AutoAspect;
	
	///default PT_PERSPECTIVE
	ProjectionType m_ProjectionType;
	//default PI/4
	Radian m_FOVy;
	/// Far clip distance - default 10000f
	float m_FarDist;
	/// Near clip distance - default 0.5f
	float m_NearDist;
	/// x/y viewport ratio - default 1.3333
	float m_Aspect; 
	/// Frustum extents(especially for PT_ORTHOGRAPHIC)
	float m_Left, m_Right, m_Top, m_Bottom;

	///λ�ã��۲�㣩
	Vector3 m_Position;
	///lookat
	Vector3 m_LookAt;
	///���������ʸ���ķ���
	Vector3 m_Up;
};

