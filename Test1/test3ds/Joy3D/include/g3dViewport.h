#pragma once

#include "g3dCamera.h"
#include "g3dRenderWindow.h"
#include "g3dBasicHeader.h"

class g3dRenderWindow;

/*********************************************
@������g3dViewport
@�������ӿ�
@˵�����ӿ�������������ʹ��ڵ�����������˵���Ǽ�����е����������
				������ͼ��֮���������ÿ�������ֻ������һ���ӿڣ�ÿ���ӿ�Ҳ
				ֻ������һ�����������һ����Ⱦ���ڿ���ӵ�ж���ӿڣ�����ʵ��
				�˶��ӿ���Ⱦ��
@�޸���ʷ���߼��� 2012/8/15������
*********************************************/
class g3dViewport
{
public:

	/** ���캯�������ã�
		@˵������

        @����:
            camera :g3dCamera* , ����������ָ�����Ϊ�ӿڵ�ͼ����Դ
        @������
			target��g3dRenderWindow* ��ȾĿ�꣨������һ����Ⱦ���ڣ�
         @������
			left��float
        @������
            top��float
        @����
            width��float
        @����
            height��float
            �ӿڵĳߴ����ĸ����������������Ƕ����ڡ�0,1��֮��ġ���������
			�ô������ñ��������Ǿ����С�������ڴ�С�����仯ʱ���ɸ�����Щ
			�����Զ�������
        @����
            ZOrder �������Ϊ�ӿڵ����ڵľ��룬����ԽС���ﴰ��ԽԶ��
			�ᱻ���и����ZOrder�Ĵ��ڸ��ǡ�

		@�޸���ʷ��
			�߼��2012/8/15������
    */
    g3dViewport(
        g3dCamera* camera,
       g3dRenderWindow* target,
        float left, float top,
        float width, float height,
        int ZOrder);

	/**Ĭ�Ϲ��캯��
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/15������
	*/
	g3dViewport(void);

	/**��������
	@˵������
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/15������
	*/
	~g3dViewport(void);

	/** Get the camera to use for rendering to this viewport. */
	g3dCamera* getCamera(void) const;

	/**Get the render Window*/
	g3dRenderWindow* getWindow(void) const;

    /** Sets the camera to use for rendering to this viewport. */
    void setCamera(g3dCamera* cam);

    /** Gets the Z-Order of this viewport. */
	int getZOrder(void) const;
	/** Gets one of the relative dimensions of the viewport,
        a value between 0.0 and 1.0.
    */
    float getLeft(void) const;

    /** Gets one of the relative dimensions of the viewport, a value
        between 0.0 and 1.0.
    */
    float getTop(void) const;

    /** Gets one of the relative dimensions of the viewport, a value
        between 0.0 and 1.0.
    */

    float getWidth(void) const;
    /** Gets one of the relative dimensions of the viewport, a value
        between 0.0 and 1.0.
    */

    float getHeight(void) const;
    /** Gets one of the actual dimensions of the viewport, a value in
        pixels.
    */

    int getActualLeft(void) const;
    /** Gets one of the actual dimensions of the viewport, a value in
        pixels.
    */

    int getActualTop(void) const;
    /** Gets one of the actual dimensions of the viewport, a value in
        pixels.
    */
    int getActualWidth(void) const;
    /** Gets one of the actual dimensions of the viewport, a value in
        pixels.
    */

    int getActualHeight(void) const;

    /** ���óߴ磨������
		@˵����
			�ӿڵĳߴ����ĸ����������������Ƕ����ڡ�0,1��֮��ġ���������
			�ô������ñ��������Ǿ����С�������ڴ�С�����仯ʱ���ɸ�����Щ
			�����Զ�������

		@������
			left��float
		@������
			top��float
		@����
			width��float
		@����
			height��float
		
		@�޸���ʷ��
			�߼��2012/8/15������
    */
    void setDimensions(float left, float top, float width, float height);

	/**Get the m_Backcolor(background color)
	*/
	ColorValue getBackColor(void) const;

	/**Set the m_Backcolor(background color)
	*/
	void setBackColor(ColorValue color);

	/**�����ӿڵ�ʵ�ʳߴ�
	@˵����
		�ײ㺯����������ֱ�ӵ��ã�����ʹ��updateDimensions��);
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/10������
	*/
	void _updateDimensions();

	/**���ñ�־��Ҫ���µĲ���ֵ*/
	void setNeedUpdate(bool b);

	/**�����ӿڵ�ʵ�ʳߴ�
	@˵����
		����ʹ��;
	
	@��������
	
	@�޸���ʷ��
		�߼��2012/8/10������
	*/
	void updateDimensions();
	

private:
	///��Ⱦ����
	g3dRenderWindow* m_Window;
	///�����
	g3dCamera* m_LinkedCamera;
	// ��Գߴ磬����Ⱦ����ʵ�ʴ�С�޹� (0..1)
	float m_RelLeft, m_RelTop, m_RelWidth, m_RelHeight;
	// ʵ�ʳߴ磬������Ⱦ����
	int m_ActLeft, m_ActTop, m_ActWidth, m_ActHeight;
	/// ZOrder
	int m_ZOrder;
	/// Background options
	ColorValue m_BackColor;
	///��־�Ƿ���Ҫ���ӿڵ�ʵ�ʴ�С���и���
	bool m_NeedUpdate;

};

