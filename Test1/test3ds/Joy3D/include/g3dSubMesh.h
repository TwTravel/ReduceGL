#pragma once
#include"g3dBasicHeader.h"
#include "3DS.H"

/*********************************************
@������g3dObject
@�����������������ṹ
@˵�����洢���㼯�ϣ��漯�ϣ������������ϣ����㷨�߼��ϣ�UV�������꼯��
@�޸���ʷ���߼��2012/8/10������
*********************************************/
class g3dObject
{
public:

	/**���캯��	
	@˵����
		����һ��t3DObject��ָ�뽫��������ת����g3dObject
	
	@������
		pobject��t3DObject*
	
	@�޸���ʷ��
		�߼��2012/8/10
	*/
	g3dObject(t3DObject *pobject);

	/**��������
	*/
	~g3dObject(void);


	/// �Ƿ��������ӳ��
	bool HasTexture;		

	/// ���������
	string m_Name;		

	/// ����Ķ��㼯��
	vector<CVector3>  m_VertexSet;	
	/// ����ĸ�������ķ�����
	vector<CVector3>  m_NormalSet;		
	/// ����������UV����
	vector<CVector2>  m_TexVertSet;		
	/// ������漯��
	vector<tFace> m_FaceSet;	

	//�������ݷֱ��¼�����ж����еĸ���������������Сֵ��
	float m_MinX;
	float m_MinY;
	float m_MinZ;
	float m_MaxX;
	float m_MaxY;
	float m_MaxZ;
};


/*********************************************
@������g3dMaterial
@����������
@˵������ʹ����submesh�У���Ϊ����
@�޸���ʷ���߼���, 2012/8/10������
*********************************************/
class g3dMaterial
{

public:
	/**���캯��
	@˵������
	
	@������
		pmaterial��tMaterialInfo*��������Ų��ʵ�����Դ
	@������
		texture��unsigned int �����ʱ��������ID
	
	@�޸���ʷ���߼���
	*/
	g3dMaterial(tMaterialInfo* pmaterial,unsigned int texture);

	/**��������
	*/
	~g3dMaterial(void);

public:
	///����
	string m_Name;

	//������ɫ
	unsigned char m_RGB[3];
	//���������id����opengl״̬���еģ�
	GLuint m_Texture;
};


/*********************************************
@������g3dSubMesh
@��������������С������Ԫ��
@˵����g3dSubMesh������һ��material��һ��object��object��¼�������ݣ�
			  material��¼�������ݡ�g3dSubMesh�����g3dMesh�Ļ�����Ԫ
@�޸���ʷ���߼��2012/8/10
*********************************************/
class g3dSubMesh
{
public:
	/**Ĭ�Ϲ��캯��
	*/
	g3dSubMesh(void);
	/**��������
	*/
	~g3dSubMesh(void);

	/**���캯��
	@˵����
		���������������ֱ�����㣬���ʺ�����
	@������
		object��t3DObject*��material��tMaterialInfo*��texture��GLuint
	@�޸���ʷ��
		�߼��� ��2012/8/10������
	*/
	g3dSubMesh(t3DObject* object,tMaterialInfo* material,GLuint texture);

	/**��Ⱦ������
	@˵������
		
	@��������
	
	@�޸���ʷ��
		�߼�� 2012/8/10, ����
	*/
	void RenderSubMesh();

	/**���������־λ
	@˵����
		ͨ�����ô˺��������Կ������߹ر�������������������Դ�����
		��������Ҳ��Ч�������������󣩡�
	@������
		b��bool
	@�޸���ʷ��
		�߼��� ��2012/8/10������
	*/
	void setHasTextrue(bool b);

private:
	/**������ʾ�б�
	@˵����
		Ϊ���ж������ݺͲ�������һ����ʾ�б�Ŀ���Ǽ�����Ⱦ
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/10������
	*/
	bool GenDisplayList();

private:

	///����
	g3dMaterial *m_pMaterial;
	///��������
	g3dObject *m_pObject;
	///��ʾ�б�������Ⱦ������
	GLuint m_DisplayList;

public:
	///����
	string m_Name;


public:
	//��Ԫ��
	friend class g3dMesh;

};

