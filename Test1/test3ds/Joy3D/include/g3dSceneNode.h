#pragma once

#include "g3dBasicHeader.h"
#include "g3dModel.h"
#include <string>
#include <map>

/*********************************************
@������g3dSceneNode
@�����������ڵ�
@˵����һ�������ڵ���һ�����ڵ��һ���ӽڵ��Լ�һ��ҽ�ģ��
				�ڵ���ģ�������Ķ����ǲ����ռ�任�Ļ�����λ��
@�޸���ʷ���߼��2012/8/12������
*********************************************/
class g3dSceneNode
{
public:

	///�任�ռ�ö��
	enum TransformSpace
        {
            /// Transform is relative to the local space
            TS_LOCAL,
            /// Transform is relative to the space of the parent node
            TS_PARENT,
            /// Transform is relative to world space
            TS_WORLD
        };

	/**Ĭ�Ϲ��캯��
	@˵����
		��������Ĺ��캯����ȣ���������Ĭ�Ϲ��캯��������������IDcount����Ĭ�ϸ�ʽ���ɵ�
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	g3dSceneNode(void);

	/**���캯��
	@˵����
		��Ĭ�Ϲ��캯����ȣ���������Ĭ�Ϲ��캯��������������IDcount����Ĭ�ϸ�ʽ���ɵ�
	
	@������name��std::string 
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	g3dSceneNode(std::string name);

	/**��������
	@˵������
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	~g3dSceneNode(void);

private:
	///������
	static int IDcount;
	///ģ��ӳ��
	std::map<string,g3dModel*> m_ModelMap;
	///�ӽڵ�ӳ��
	std::map<string,g3dSceneNode*> m_ChildNodeMap;
	///���ڵ�ָ��
	g3dSceneNode* m_ParentNode;//if its value is NULL, it means it has no parent and it is the root node(only one). 
	///���ռ��еķ���
	Quaternion m_Orientation;
	///����ռ䷽��
	Quaternion m_DerivedOrientation;
	///���ռ��е�λ��
	Vector3 m_Position;
	///����ռ��е�λ��
	Vector3 m_DerivedPosition;
	///���ռ��е���������
	Vector3 m_Scale;
	///����ռ���������
	Vector3 m_DerivedScale;

	///��Ҫ����λ�ã�
	bool m_SelfNeedUpdate;

public:
	string m_Name;
	
public:
	/**���ýڵ㷽��
	@˵����
		����ڸ��ռ�		

	@������
		w:float, x:flaot, y:float, z:float

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setOrientation( float w, float x, float y, float z);

	/**���ýڵ㷽��
	@˵����
		����ڸ��ռ�		

	@������
		q:Quaternion,  ��һ����Ԫ����ʾ����

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setOrientation(Quaternion q);

	/**ȡ�ýڵ㷽��
	@˵����
		����ڸ��ռ�		
	@������
		x:flaot, y:float, z:float	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	const Quaternion &getOrientation(void) const;

	/**���ýڵ�λ��
	@˵����
		����ڸ��ռ�	

	@������
		x:flaot, y:float, z:float	

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setPosition( float x, float y, float z);

	/**���ýڵ�λ��
	@˵����
		����ڸ��ռ�	

	@������q:Vector3

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setPosition(Vector3 q);

	/**�õ��ڵ�ĵ�ǰ����
	@˵����
		����ڸ��ռ�

	@��������

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	const Vector3 &getPosition(void) const;

	/**���ýڵ����������
	@˵����
		����ڸ��ռ�	

	@������
		x:flaot, y:float, z:float

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setScale( float x, float y, float z);

	/**���ýڵ����������
		@˵����
			����ڸ��ռ�	

		@������
			q��Vector3

		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	void setScale(Vector3 q);

	/**ȡ�õ�ǰ��������
	@˵����
		����ڸ��ռ�

	@��������

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	const Vector3 &getScale(void) const;

	/**�õ���ǰ�ڵ�������ռ��еķ���
	@˵����
		ͨ���������еĸ��ڵ�õ�

	@��������	

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
    const Quaternion & _getDerivedOrientation(void) ;

	/**�õ���ǰ�ڵ�������ռ��е�λ��
	@˵����
		ͨ���������еĸ��ڵ�õ�

	@��������

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
    const Vector3 & _getDerivedPosition(void) ;

	/**�õ���ǰ�ڵ�������ռ��е���������
	@˵����
		ͨ���������еĸ��ڵ�õ�
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	 const Vector3 & _getDerivedScale(void) ;

	 /**ƽ�ƽڵ㺯��
	@˵����
		ƽ�Ʊ任���ڱ任�ռ䣬Ĭ���Ǹ��ռ�
		
	@������
		d:Vector3&, ƽ������
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣨Ĭ�ϣ������ؿռ������ռ�
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void translate(const Vector3& d, TransformSpace relativeTo=TS_PARENT);

	/**ƽ�ƽڵ�
	@˵����
		ƽ�Ʊ任���ڱ任�ռ䣬Ĭ���Ǹ��ռ�
		
	@������
		x:flaot, y:float, z:float��ƽ������
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣨Ĭ�ϣ������ؿռ������ռ�
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void translate(float x, float y, float z, TransformSpace relativeTo=TS_PARENT);

	/**��ת�ڵ�
	@˵����
		�ڸ�������ռ�������һ��������ת�ᣬ��ת�����Ƕ�
		
	@������
		axis��Vector3&����ת��
	@������
		angle��Radian&����ת�Ƕ�
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣬���ؿռ䣨Ĭ�ϣ�������ռ�

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void rotate(const Vector3& axis, const Radian& angle, TransformSpace relativeTo=TS_LOCAL);

	/**��ת�ڵ�
	@˵����
		�ڸ�������ռ�������һ��������ת�ᣬ��ת�����Ƕ�
		
	@������
		q��Quaternion&����ת�õ���Ԫ��
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣬���ؿռ䣨Ĭ�ϣ�������ռ�

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void rotate(const Quaternion& q, TransformSpace relativeTo=TS_LOCAL);

	/**��z����ת�������
	@˵������
		
	@������
		angle��Radian&����ת�Ƕ�
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣬���ؿռ䣨Ĭ�ϣ�������ռ�

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void roll(const Radian& angle, TransformSpace relativeTo=TS_LOCAL);

	/**��x����ת��������
	@˵������
		
	@������
		angle��Radian&����ת�Ƕ�
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣬���ؿռ䣨Ĭ�ϣ�������ռ�

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void pitch(const Radian& angle, TransformSpace relativeTo=TS_LOCAL);

	/**��y����ת����ƫ��
	@˵������
		
	@������
		angle��Radian&����ת�Ƕ�
	@������
		relativeTo��TransformSpace��ѡ��任�ռ䣬��ѡ���ռ䣬���ؿռ䣨Ĭ�ϣ�������ռ�

	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void yaw(const Radian& angle, TransformSpace relativeTo=TS_LOCAL);


	/**�Ӹ��ڵ����λ�ã��������������
	@˵����
		�ײ㺯����������ֱ�ӵ���
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void _updateFromParent(void) ;

	/**��־�Լ���Ҫ����λ�ã�������������ӵĸ���
	@˵������
		
	@������b��bool
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setSelfNeedUpdate(bool b);

	/**֪ͨ�ӽڵ����λ�ø���
	@˵����������֪ͨ
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void NotifyChildrenUpdate(void);

	/**���ģ��
	@˵������
		
	@������model��g3dModel*
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool addModel(g3dModel* model);

	/**�Ƴ�ģ��
	@˵����
		����ģ��ָ��
		
	@������model��g3dModel*
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool removeModel(g3dModel* model);

	/**�Ƴ�ģ��
	@˵����
		����ģ������
		
	@������name��string
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool removeModel(string name);

	/**ȡ��ģ��ָ��
	@˵������
		
	@������
		index��unsigned short
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	g3dModel* getModel(unsigned short index);

	/**ȡ�ùҽ�ģ������
	@˵������
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	unsigned short getModelsNum(void);

	/**����ӽڵ�
	@˵������
		
	@������child��g3dSceneNode*
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool addChild( g3dSceneNode* child);

	/**�Ƴ��ӽڵ�
	@˵������
		
	@������name��string
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool removeChild(string name);

	/**�Ƴ��ӽڵ�
	@˵������
		
	@������child��g3dSceneNode*
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	bool removeChild(g3dSceneNode* child);

	/**ȡ���ӽڵ�ָ��
	@˵��������index
		
	@������index��unsigned short
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	g3dSceneNode* getChild(unsigned short index);

	/**�õ��ӽڵ�����
	@˵������
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	unsigned short getChildrenNum(void);

	/**���ø��ڵ�
	@˵������
		
	@������
		parent��g3dSceneNode *
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setParent(g3dSceneNode *parent);

	/**�õ����ڵ�ָ��
	@˵������
		
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/12������
	*/
	 g3dSceneNode* getParent(void) const;
//private:
	
};

