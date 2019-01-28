#pragma once
#include"g3dBasicHeader.h"
#include "g3dLight.h"

/*********************************************
@������g3dLightWrapper
@��������Ⱦϵͳֱ��ʹ�õĹ�Դ���ͣ����������û��ġ�
@˵������������з�װ���ʺ�openGL����ֱ��ʹ�õĲ������������ڳ����������е�g3dLight��
				�����openGL��һ�ֶԹ�Դ�����ľ���ʵ�֡�
@�޸���ʷ���߼��� ,2012/8/12,����
*********************************************/
class g3dLightWrapper
{

public:

	/**	���캯��
		@˵������
	
		@������light��g3dLight*�����ڳ�ʼ��m_pLight
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	g3dLightWrapper(g3dLight* light);

	/**��������
	*/
	~g3dLightWrapper(void);

	/**	����m_pLight
		@˵������
	
		@������light��g3dLight*�����ڶ�m_pLight��ֵ
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	void setLight(g3dLight* light);

	/**	�õ���ǰm_pLight
		@˵������
	
		@��������
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	g3dLight* getLight(void);

private:
	/**	��ʼ����Ա����
		@˵������m_pLight���ڵ�����£�����m_pLight�ľ������Ͷ�5��������и�ֵ
	
		@��������
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	void InitWrapper(void);

private:

	///g3dLight��ָ�룬���еĶ���
	g3dLight* m_pLight;

public:
	//���µĳ�Ա����ȫ����Ϊ���У���Ϊ����������Ⱦϵͳ��

	///����
	std::string m_Name; 

	///��opengl�з���Ĺ�ԴID
	unsigned int LightID;//GLenum=unsigned int
	///�Ƿ��ڻ״̬
	bool isActive;

	///��Դ����
	g3dLight::LightTypes m_LightType;

	///������
	float m_LightAmbient[4];
	///ɢ���
	float m_LightDiffuse[4];
	///�����
	float m_LightSpecular[4];
	///λ��
	float m_LightPosition[4];
	///����
	float m_LightDirection[4];
};

