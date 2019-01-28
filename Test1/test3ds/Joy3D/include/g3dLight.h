#pragma once

#include "g3dBasicHeader.h"



/*********************************************
@������g3dLight
@�������Թ�Դ�ķ�װ
@˵����֧���������͵Ĺ�Դ���ͣ��۹�ƣ����Դ�ͷ����Թ�Դ�ṩ�򵥵Ľӿ������ݾ��������
				������Դ��Ҫֱ��ʹ�ù��캯��������ʹ�ó�����������CreateLight������
				g3dLightWrapper������Ⱦϵͳ��ʹ�õ�һ�����ͣ���g3dLightһ һ��Ӧ������μ�g3dLightWrapper��
@�޸���ʷ���߼��2012/8/12������
*********************************************/
class g3dLight
{

public:
	/**Ĭ�Ϲ��캯��	
		@˵����
			�����Ϊstring�Ĺ��캯������������Ĭ�Ϲ��캯��������IDcount��������
						
		@��������
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	g3dLight(void);

	/**���캯��	
		@˵����
			��Ĭ�Ϲ��캯������������,Ĭ�Ϲ��캯������IDcount��������
						
		@��������
	
		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	g3dLight(std::string name);

	/**��������
	*/
	~g3dLight(void);

	///��Դ����ö������
	enum LightTypes
	{
		/// ���Դ�����������ȵķ������
		LT_POINT = 0,
		/// �����Թ�Դ��ĳһ��������ƽ�й���
		LT_DIRECTIONAL = 1,
		/// �۹�ƣ���Ҷ�����
		LT_SPOTLIGHT = 2
	};
	

	/** ���ù�Դ����
		@˵������

		@������type��LightTypes

		@�޸���ʷ��
			�߼��2012/8/12 ,  ����			
	*/
	void setType(LightTypes type);

	/** �õ���Դ����
	*/
	LightTypes getType(void) const;

	 /** ���ù�Դ��ɢ�����ɫ
        @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ����⣬���ʻ���һ���Է������ԡ�
            Diffuse light simulates the typical light emanating from light sources and affects the base colour
            of objects together with ambient light.

		@������red:float , green:float , blue:float 

		@�޸���ʷ��
			�߼��2012/8/12 ,  ����			
    */
    void setDiffuseColour(float red, float green, float blue);

    /** ���ù�Դ��ɢ�����ɫ
        @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ�������ʻ���һ���Է������ԡ�
            Diffuse light simulates the typical light emanating from light sources and affects the base colour
            of objects together with ambient light.

		@������colour��ColorValue&

		@�޸���ʷ��
			�߼��2012/8/12 ,  ����			
    */
    void setDiffuseColour(const ColorValue& colour);

     /** �õ���Դ��ɢ�����ɫ
        @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ�������ʻ���һ���Է������ԡ�
            Diffuse light simulates the typical light emanating from light sources and affects the base colour
            of objects together with ambient light.

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 ,  ����			
    */
    const ColorValue& getDiffuseColour(void) const;

   /** ���ù�Դ�ľ���⣨specular light������ɫ.
       @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ�������ʻ���һ���Է������ԡ�
       @������red:float, green:float, blue:float
        
		@�޸���ʷ��
			�߼��2012/8/12������
    */
    void setSpecularColour(float red, float green, float blue);

    /** ���ù�Դ�ľ���⣨specular light������ɫ.
       @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ�������ʻ���һ���Է������ԡ�
       @������colour��ColorValue&
        
		@�޸���ʷ��
			�߼��2012/8/12������
    */
    void setSpecularColour(const ColorValue& colour);

   /** ȡ�õ�ǰ��Դ�ľ���⣨specular light������ɫ.
       @˵����
			�����л����⣬ɢ���;�����������ԣ��ֱ�����Ŷ������ֹ�ķ�����ʡ�
			���ʵĻ������ɢ���Ӱ����ʡ�����ȥ������ɫ�����ʵľ�������Ծ�������
			����̶ȡ�������ʻ���һ���Է������ԡ�
       @��������
        
		@�޸���ʷ��
			�߼��2012/8/12������
    */
    const ColorValue& getSpecularColour(void) const;

	/** ���ù�Դ��˥������
		@˵����
			��ǿ�����Ŵ�����������Ӷ���С������Ҫ��������˥�����ӣ�����˥�����ӺͶ���˥�����ӣ�
			���庬��ɲο�opengl�Ĺ�Դ���֡�
			
		@param
			constant The constant factor in the attenuation formula: 1.0 means never attenuate, 0.0 is complete attenuation
		@param
			linear The linear factor in the attenuation formula: 1 means attenuate evenly over the distance
		@param
			quadratic The quadratic factor in the attenuation formula: adds a curvature to the attenuation formula.
	*/
	void setAttenuation(float constant, float linear, float quadratic);

	/** �õ���Դ˥�������еĳ���˥������
		@˵������

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	float getAttenuationConstant(void) const;

	/** �õ���Դ˥�������е�����˥������
		@˵������

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	float getAttenuationLinear(void) const;

	/** �õ���Դ˥�������еĶ���˥������
		@˵������

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	float getAttenuationQuadric(void) const;

	/** ���ù�Դλ��
		@˵����
			���Ե��Դ�;۹����Ч

		@������x:float, y:float, z:float

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	void setPosition(float x, float y, float z);

	/** ���ù�Դλ��
		@˵����
			���Ե��Դ�;۹����Ч

		@������vec:Vector3&

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	void setPosition(const Vector3& vec);

	/** �õ���ǰ��Դλ��
		@˵����
			���Ե��Դ�;۹����Ч

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	const Vector3& getPosition(void) const;

	/** ���ù�Դ������ߵķ���
		@˵����
			���Է����Թ�Դ�;۹����Ч

		@������x:float, y:float, z:float

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	void setDirection(float x, float y, float z);

	/** ���ù�Դ������ߵķ���
		@˵����
			���Է����Թ�Դ�;۹����Ч

		@������vec:Vector3&

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	void setDirection(const Vector3& vec);

	/** �õ���Դ������ߵķ���
		@˵����
			���Է����Թ�Դ�;۹����Ч

		@��������

		@�޸���ʷ��
			�߼��2012/8/12 , ����
	*/
	const Vector3& getDirection(void) const;

	/** ���þ۹�Ʋ���.
		@˵����
			����һ���۹�ƣ���openGL����Ҫ�۹���нǣ��۹�ָ���͹��߷���
			������������нǺ;۹�ָ�����н������۹�ƹ�׶�İ�ǣ���Χ��[0,90]��
			�۹�ָ���������ߵľۼ��̶ȣ���Χ��[0,1]

		@������
			cutoff��Radian���н�
		@������falloff��float���۹�ָ��

		@�޸���ʷ��
			�߼��2012/8/12������
	*/
	void setSpotlightRange(const Radian& cutoff, float falloff = 0.0);

	/** �õ��۹�Ƶ��н�.
		@˵����
			����һ���۹�ƣ���openGL����Ҫ�۹���нǣ��۹�ָ���͹��߷���
			�н������۹�ƹ�׶�İ�ǣ���Χ��[0,90]��
			�۹�ָ���������ߵľۼ��̶ȣ���Χ��[0,1]

		@��������

		@�޸���ʷ��
		�߼��2012/8/12������
	*/
	const Radian& getSpotlightCutoff(void) const;

	/** �õ��۹�ָ��
	*/
	float getSpotlightExponent(void) const;

	/** ���þ۹���н�
		@˵����
		����һ���۹�ƣ���openGL����Ҫ�۹���нǣ��۹�ָ���͹��߷���
		�н������۹�ƹ�׶�İ�ǣ���Χ��[0,90]��
		�۹�ָ���������ߵľۼ��̶ȣ���Χ��[0,1]

		@������
		cutoff��Radian���н�

		@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setSpotlightCutoff(const Radian& val);

	/** ���þ۹�ƾ۹�ָ��
		@˵����
		����һ���۹�ƣ���openGL����Ҫ�۹���нǣ��۹�ָ���͹��߷���
		�н������۹�ƹ�׶�İ�ǣ���Χ��[0,90]��
		�۹�ָ���������ߵľۼ��̶ȣ���Χ��[0,1]

		@������
		cutoff��Radian���н�

		@�޸���ʷ��
		�߼��2012/8/12������
	*/
	void setSpotlightExponent(float val);

public:
	///����
	std::string m_Name;
private:
	///������
	static int IDcount;

	///��Դ����
	LightTypes m_LightType;
	///λ��
	Vector3 m_Position;
	///ɢ�����ɫ
	ColorValue m_Diffuse;
	///�������ɫ
	ColorValue m_Specular;
	///���߷���
	Vector3 m_Direction;

	///�۹���н�
	Radian m_SpotCutoff;
	///�۹�ƾ۹�ָ��
	float m_SpotExponent;

	///����˥������
	float m_AttenuationConst;
	///����˥������
	float m_AttenuationLinear;
	///����˥������
	float m_AttenuationQuad;
};

