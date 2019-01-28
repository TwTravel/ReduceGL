#pragma once
#include "g3dBasicHeader.h"
#include "g3dSubMesh.h"

/*********************************************
������g3dMesh

������ģ�ͣ�g3dModel���� ������ ���� ���ݽṹ

˵����һ��������ģ�Ϳ����ɶ����������ģ����ɣ�ÿ��
			��ģ�Ͷ�Ӧ����Ӧһ������ṹ��
			����һ������������ṹӦ������һ��g3dSubMesh
			��ָ�룬�Ա��ڹ������չ��
*********************************************/

class g3dMesh
{
public:

	/**Ĭ�Ϲ��캯��
	@˵������
	
	@��������

	@�޸���ʷ��
		�߼��2012/8/16,����
	*/
	g3dMesh(void);


	/**��������
	@˵���������������У����m_SubMeshList�д�ŵ�����
			       g3dSubMesh ������������ֹ�ڴ�й¶��
	
	@��������

	@�޸���ʷ��
		�߼��2012/8/16,����
	*/
	~g3dMesh(void);


	/**	��Mesh�к��е�����SubMesh������Ⱦ 
	@˵����һ��Mesh��������SubMesh���洢��һ��vector�С�
					�����Mesh����Ⱦ�ͱ���˶�������SubMesh��Ⱦ�ı�����

	@��������

	@�޸���ʷ��
			�߼��2012/8/16,����
	*/
	void RenderMesh(void);


	/**�Ե�ǰg3dMesh���һ��g3dSubMesh
	@˵������
	
	@������submesh��һ��g3dSubMesh��ָ�룬
					ָ��Ҫ��ӵ�g3dSubMesh	
	*/
	void addSubMesh(g3dSubMesh* submesh);

	/**��ʼ�������bounding box���ĸ�����
	@˵������
	
	@��������

	@�޸���ʷ��
		�߼��2012/8/16,����
	*/
	void initBoundingBox();

	Vector3 getSphereCenter(void) const;

	float getSphereRadius(void) const;

	Vector3 getBoundingBoxMax(void) const;

	Vector3 getBoundingBoxMin(void) const;

private:

	///�洢���е�g3dSubMeshָ�롣
	vector<g3dSubMesh*> m_SubMeshList;

	///�����bounding box��8�����е�x,y,z������С�ĵ�
	Vector3 m_MinPoint;
	///�����bounding box��8�����е�x,y,z�������ĵ�
	Vector3 m_MaxPoint;
	///bounding box�����������
	Vector3 m_Center;
	///�����뾶
	float m_Radius;


public:
	///mesh������
	std::string m_Name;

};

