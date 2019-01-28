#pragma once
#include "g3dBasicHeader.h"
#include "g3dSceneNode.h"
#include "g3dCamera.h"
#include "g3dLight.h"
#include "g3dMesh.h"
#include "3DS.H"

/*********************************************
@������g3dSceneManager
@����������������
@˵����1. ����������������������������ĵĲ��֡�������������е����пɶ��Ͳ��ɶ���
				���壬����ģ�͡�����������Ρ���պеȡ�
				2.  ģ����Ҫ�ҽ��ڳ����ڵ��£������ڵ���ϳ�һ�����νṹ������ǳ�������
				���еĽڵ������ڵ�����ͨ��һ�������ڳ����������еĸ��ڵ���������
				3. ע�⣺һ���ڴ����ڳ�����scene���е����壬����Ҫͨ�������������е�
				CreateXXX������������
@�޸���ʷ��
			�߼��2012/8/11������
*********************************************/
class g3dSceneManager
{
public:

	/**	Ĭ�Ϲ��캯��
	@˵�����û�ͨ�����������������������
	
	@��������
	
	@�޸���ʷ���߼��2012/8/11������
	*/
	g3dSceneManager(void);
	/**	��������
	@˵����
		�������������ɳ�������������������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	~g3dSceneManager(void);

	/**	�õ����ڵ�
	@˵����
		���ڵ�ȫ��ֻ��һ�����û��޷��������޷�ɾ�����û�ͨ�����ڵ�����ӽڵ�ҽӡ�
	
	@��������
	
	@�޸���ʷ���߼��2012/8/11������
	*/
	g3dSceneNode* getRootNode(void);

	/**	�½������ڵ�
		@˵����
			��Ҫͨ��g3dSceneNode�Ĺ��캯���������ڵ㣬��Ϊ�ڵ���Ҫ�ڳ���������
			�еǼǣ���������Ψһ�Ϸ�������
	
		@������
			name��std::string
	
		@�޸���ʷ��
			�߼��2012/8/11������
	*/
	g3dSceneNode* CreateSceneNode(std::string name);

	/**	�½���Դ
	@˵����
	��Ҫͨ��g3dLight�Ĺ��캯����������Դ����Ϊ��Դ��Ҫ�ڳ���������
	�еǼǣ���������Ψһ�Ϸ�������
	
	@������
		name��std::string
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	g3dLight* CreateLight(std::string name);

	/**	�½������
	@˵����
	��Ҫͨ��g3dCamera�Ĺ��캯�����������������Ϊ�������Ҫ�ڳ���������
	�еǼǣ���������Ψһ�Ϸ�������
	
	@������
		name��std::string
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	g3dCamera* CreateCamera(std::string name);

	/**	�½�����
	@˵����
		��Ҫͨ��g3dMesh�Ĺ��캯��������������Ϊ������Ҫ�ڳ���������
		�еǼǣ���������Ψһ�Ϸ�������
	
	@������
		name��std::string
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	g3dMesh* CreateMesh(std::string filename);

	/**	�½�ģ��
	@˵����
		��Ҫͨ��g3dModel�Ĺ��캯��������ģ�ͣ���Ϊģ����Ҫ�ڳ���������
		�еǼǣ���������Ψһ�Ϸ�������
	
	@������
		name��std::string
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	g3dModel* CreateModel(std::string filename);

	/**	����ȫ�ֻ��������ɫ
	@˵����
		ȫ�ֻ���������ֻ��һ����
	
	@������
		r��float��g��float��b��flaot
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	void setAmbientColor(float r,float g,float b);

	/**	�õ�ȫ�ֻ��������ɫ
	@˵����
		ȫ�ֻ���������ֻ��һ����
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	ColorValue getAmbientColor(void) const;


private:

	/**	��������
	@˵����
		�������Ӧ������Դ�������У�����Ŀǰ�����в���������ʱ�������
	
	@������
		strFileName��LPSTR
	
	@�޸���ʷ��
		�߼��2012/8/11������
	*/
	unsigned int CreateTexture(LPSTR strFileName);


public:
	friend class g3dRenderSystem;
	
private:
	///3ds loader
	CLoad3DS m_Load3ds;

	///the map of SceneNode
	///when a SceneNode is created, it stores in this map
	std::map<std::string,g3dSceneNode*> m_SceneNodeMap;
	///��Դӳ��
	std::map<std::string,g3dLight*> m_LightMap;
	///�����ӳ��
	std::map<std::string,g3dCamera*> m_CameraMap;
	///the root node is a part of SceneManager and users cannot delete it. 
	g3dSceneNode* m_pRootNode;

	///the color of the ambient light,
	///ambient light cannot be created by the function CreateLight(),
	ColorValue m_Ambient;

	///resource manager
	std::map<std::string,g3dMesh*> m_MeshMap;
};

