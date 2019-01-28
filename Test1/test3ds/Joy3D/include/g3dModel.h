#pragma once
#include "g3dMesh.h"


/*
class g3dObject
{
public:

	g3dObject(t3DObject *pobject);
	~g3dObject(void);
	bool HasTexture;			// �Ƿ��������ӳ��
	string m_Name;			// ���������
	vector<CVector3>  m_VertexSet;			// ����Ķ��㼯��
	vector<CVector3>  m_NormalSet;		// ����ĸ�������ķ�����
	vector<CVector2>  m_TexVertSet;		// ����������UV����
	vector<tFace> m_FaceSet;				// ������漯��
};

class g3dMaterial
{
public:
	g3dMaterial(tMaterialInfo* pmaterial,unsigned int texture);
	~g3dMaterial(void);
public:
	string m_Name;//����
	unsigned char m_RGB[3];//������ɫ
	GLuint m_Texture;//���������id����opengl״̬���еģ�
};
*/

/*********************************************
@������g3dModel
@������ģ����
@˵����Ŀǰ�Ƚϼ򵥣�δ������Ϲ�����������
@�޸���ʷ���߼��� 2012/8/16������
*********************************************/
class g3dModel
{
public:
	g3dModel(g3dMesh* mesh);
	~g3dModel(void);

	/**��Ⱦģ��
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/16
	*/
	void RenderModel();

	/**�õ�bounding box�����������
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/16
	*/
	Vector3 getSphereCenter(void) const;

	/**�õ�bounding box�������뾶
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/16
	*/
	float getSphereRadius(void) const;

	/**�õ�bounding box���������ֵ����
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/16
	*/
	Vector3 getBoundingBoxMax(void) const;

	/**�õ�bounding box��������Сֵ����
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/16
	*/
	Vector3 getBoundingBoxMin(void) const;

public:
	///����
	std::string m_Name;
	///�Ƿ��и��ڵ�
	bool HasParent;

private:
	///����ṹ��ָ��
	g3dMesh* m_Mesh;

};


