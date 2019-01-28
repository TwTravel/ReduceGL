#pragma once
#include "windows.h"
#include  "tchar.h"
#include "Windows.h"
#include "g3dBasicHeader.h"
#include "g3dViewport.h"
#include "g3dCamera.h"

class g3dViewport;

/*********************************************
@������g3dRenderWindow
@��������Ⱦ������

@˵����1.  ��Ⱦ������һ����Ⱦ����render target������Ⱦ����һ�������֣�
			   һ���Ǵ��ڣ���һ��������Ŀǰ�����֧����Ⱦ�����ڣ���֧����
			   Ⱦ������
			   2.  ��Ⱦ������һ��Win32���ڣ�Win32������������ͼģʽ:
			   һ��������GDI,������MFC��QT���г��õĻ��ߣ���Բ����ͼ�ȣ�
			   ��һ����ͨ��openGL�����Դ�����Ⱦ�������ַ�ʽ����ͬʱʹ�ã�
			   Ҳ����˵ ,�Ƿ���Ҫ���ø�����ʼ��openGL�Ĵ��ڻ����ĺ�����initGLWindow()��
			   ��Ҫ�����ṩ�Ĵ��ڱ��������������������̿���Ѿ��ṩ
			   ��openGL�Ĵ��ڻ�����QGLWidget������Ҫ�����û�У�CView��
			   ����Ҫ����Ҳ����m_HelpToInitGLWindow���ڵ����壬ϵͳ����
			   ��������������Ƿ��ʼ��opengl������
			   ����HWND,HDC,HGLRC�ĸ�����Ϣ���Բο�msdn�����˵����
			   4.  һ����Ⱦ���ڿ���ӵ�ж���ӿڣ�ÿ���ӿڹҽ�һ�����������Ⱦ����
			   ����ӵ�е��ӿ����ִ���Ⱦ��ʵ�ֶ��ӿ���Ⱦ��Ч����

@�޸���ʷ��
				�߼��2012/8/14������
*********************************************/
class g3dRenderWindow
{

public:

	/**	���캯��
		@˵������
	
		@������width��unsigned int�����ڵĿ�
		@������height��unsigned int�����ڵĸ�
		@������hwnd��HWND�����ھ��
		@������helptoInitGLwindow��bool
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	g3dRenderWindow(unsigned int width,unsigned int height,HWND hwnd,bool helptoInitGLwindow);

	/**	��������
		@˵������
	
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	~g3dRenderWindow(void);

	/**	������ʼ������opengl����
		@˵����
				��Ⱦ������һ��Win32���ڣ�Win32������������ͼģʽ:
			   һ��������GDI,������MFC��QT���г��õĻ��ߣ���Բ����ͼ�ȣ�
			   ��һ����ͨ��openGL�����Դ�����Ⱦ�������ַ�ʽ����ͬʱʹ�ã�
			   Ҳ����˵ ,�Ƿ���Ҫ���ø�����ʼ��openGL�Ĵ��ڻ����ĺ�����initGLWindow()��
			   ��Ҫ�����ṩ�Ĵ��ڱ��������������������̿���Ѿ��ṩ
			   ��openGL�Ĵ��ڻ�����QGLWidget������Ҫ�����û�У�CView��
			   ����Ҫ����Ҳ����m_HelpToInitGLWindow���ڵ����壬ϵͳ����
			   ��������������Ƿ��ó�ʼ��opengl������
			   ����HWND,HDC,HGLRC�ĸ�����Ϣ���Բο�msdn�����˵����

		@��������

		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	bool initGLWindow(void);

	/**	���ٴ���
		@˵����
			���ٴ���ֻ�ǽ����ڵ��豸�����ĺ�openGL����Ⱦ�������ͷţ�������ɾ��
				
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	void destroyWindow(void);

	/**	����������
		@˵������
	
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	void swapBuffer(void);

	/**	�õ����ڵĿ�
		@˵������
	
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	unsigned int getWidth(void);

	/**	�õ����ڵĸ�
		@˵������
	
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	unsigned int getHeight(void);

	/** Adds a viewport to the rendering target.
        @remarks
            A viewport is the rectangle into which rendering output is sent. This method adds
            a viewport to the render target, rendering from the supplied camera. The
            rest of the parameters are only required if you wish to add more than one viewport
            to a single rendering target. Note that size information passed to this method is
            passed as a parametric, i.e. it is relative rather than absolute. This is to allow
            viewports to automatically resize along with the target.

        @param
            cam The camera from which the viewport contents will be rendered (mandatory)
        @param
            ZOrder The relative order of the viewport with others on the target (allows overlapping
            viewports i.e. picture-in-picture). Higher ZOrders are on top of lower ones. The actual number
            is irrelevant, only the relative ZOrder matters (you can leave gaps in the numbering)
        @param
            left The relative position of the left of the viewport on the target, as a value between 0 and 1.
        @param
            top The relative position of the top of the viewport on the target, as a value between 0 and 1.
        @param
            width The relative width of the viewport on the target, as a value between 0 and 1.
        @param
            height The relative height of the viewport on the target, as a value between 0 and 1.

		@ history of previous changes ��
				�߼��2012/8/14, Create
    */
	g3dViewport* addViewport(g3dCamera* cam, int ZOrder = 0, float left = 0.0f, float top = 0.0f ,
		float width = 1.0f, float height = 1.0f);

    /** Returns the number of viewports attached to this target.*/
        unsigned int getNumViewports(void) const;

    /** Retrieves a pointer to the viewport with the given index. */
        g3dViewport* getViewport(int index);

	/** Retrieves a pointer to the viewport with the given Zorder. 
		@remarks throws if not found.
	*/
        g3dViewport* getViewportByZOrder(int ZOrder);

    /** Removes a viewport at a given ZOrder.
    */
    void removeViewport(int ZOrder);

    /** Removes all viewports on this target.
    */
    void removeAllViewports(void);

	/**	���ڴ�С�ı�
		@˵������resizeEvent���¼���������ʹ��
	
		@��������
	
		@�޸���ʷ��
				�߼��� ,  2012/8/14������
	*/
	void windowResized(void);


private:

	/// Private GDI Device Context
	HDC			hDC;	
	/// Permanent Rendering Context
	HGLRC		hRC;		
	/// Holds Our Window Handle
	HWND		hWnd;		

	///���ڵĿ�
	unsigned int m_Width;
	///���ڵĸ�
	unsigned int m_Height;

	/// List of viewports, map on Z-order
	///������bug��Ŀǰ����֧�ֶ��ӿ���Ⱦ������û�и���zOrder��������Ⱦ˳���д��Ľ���
	std::map<int, g3dViewport*> m_ViewportList;

	/// �Ƿ���Ҫ������ʼ��openGL���ڻ���
	bool m_HelpToInitGLWindow;
	
};

