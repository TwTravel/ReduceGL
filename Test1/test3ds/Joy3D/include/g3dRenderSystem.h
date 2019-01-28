#pragma once
#include "g3dBasicHeader.h"
#include "g3dSceneManager.h"
#include"g3dLightWrapper.h"
#include"g3dRenderWindow.h"
#include "gl/GL.h"
#include "gl/GLU.h"

/*********************************************
@������g3dRenderSystem
@����������opengl����Ⱦϵͳ
@˵������Ⱦϵͳ�Ļ������˼���ǣ���Ⱦϵͳ�볡���������໥������
			  ����Ⱦ��������һ�ֿɲ�ӵ�ģʽ�������պ��ά������չ��
			  ����һ�¡���չ����Ŀǰ�ǿ�opengl�����о������Ⱦ��������ô
			  ����Ҫ��ֲ��ֻ��Ҫ���ⲿ�ֻ����Ϳ����ˣ�����opengl es��Dx
			  �ȡ�
@�޸���ʷ���߼��2012/8/14������
*********************************************/

class g3dRenderSystem
{
public:

	/**Ĭ�Ϲ��캯��

	@˵����һ�㲻ʹ��
	
	@��������
	
	@�޸���ʷ���߼��2012/8/14������
	*/
	g3dRenderSystem(void);

	/**��������
	
	@˵�����԰���������LightWrapper��renderWindow��������
								
	@��������
	
	@�޸���ʷ���߼�� 2012/8/14������
	*/
	~g3dRenderSystem(void);

	/**����m_pSceneManager
	
	@˵����Ŀ��������Ⱦ
	
	@������scenemanager:g3dSceneManager*
	
	@�޸���ʷ���߼��� 2012/8/14������
	*/
	void setSceneManager(g3dSceneManager* scenemanager);

	/**�õ���ǰm_pSceneManager
	
	@˵������
	
	@��������
	
	@�޸���ʷ���߼��� 2012/8/14������
	*/
	g3dSceneManager* getSceneManager(void);

	/**��ʼ����Ⱦϵͳ
	
	@˵������������������1.��ʼ��LightWrapper
				   2.��ʼ��openGL����
	
	@��������
	
	@�޸���ʷ���߼��� 2012/8/14������
	*/
	void initRenderSystem(void);

	/**�Ե�ǰ������Ⱦһ֡
	
	@˵������Ⱦϵͳ�ĺ��ĺ�����Ҳ�ǹ��û���paintEvent�����¼�
					�������еĵ��õĺ�����
	
	@��������
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void renderOneFrame(void);

	/**����RenderWindow
	
	@˵������Ҫʹ��g3dRenderWindow�Ĺ��캯�����д�����
					��Ϊ���漰��window�ĳ�ʼ������
	
	@������name��std::string ��������

	@������width��unsigned int, ��Ⱦ���ڵĿ�

	@������height��unsigned int, ��Ⱦ���ڵĳ�

	@������hwnd��HWND ����Ⱦ���ڵĴ��ھ��

	@������helptoinitGLwindow��bool, �������ֵ�������û��Ƿ�ϣ����Ⱦϵͳ������ʼ��
					��Ⱦ���ڵ�openGL���������Ƿ����initGLWindow()����Ϊһ��������Ĭ�����
					�²�֧��openGL������������ֵ��true����falseҪȡ�������GUI��̿���Ƿ�
					�Ѿ�Ϊ��������������������QT��ʹ��QGLWidget���Ƽ�������false�������MFC
					�е�view��true��
					�ǳ��ؼ���
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	g3dRenderWindow* CreateRenderWindow(std::string name,unsigned int width,unsigned int height,HWND hwnd, bool helptoinitGLwindow);


private:

	/**���������ͶӰ���ֽ�����Ⱦ
	
	@˵������
	
	@������cam��g3dCamera*��ָ��������Ⱦ�������
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void renderCameraProj(g3dCamera* cam);

	/**�����������ͼ-ģ�Ͳ��ֽ�����Ⱦ
	
	@˵������
	
	@������cam��g3dCamera*��ָ��������Ⱦ�������
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void renderCameraView(g3dCamera* cam);

	/**��Ⱦ�����е�����ʵ��
	
	@˵������Ⱦ�����н�Ϊ�ؼ���һ������Գ����е�����model��Ⱦ
					���Ժ���𽥼�����պУ����棬񷶥��
	
	@��������
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void renderScene(void);

	/**����Viewport
	
	@˵������
	
	@������viewport��g3dViewport* ָ���ӿ�
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void loadViewport(g3dViewport* viewport);
	
	/**����ʹ��
	
	@˵������
	
	@������light��g3dLightWrapper*
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void enableLight(g3dLightWrapper* light);

	/**��ʼ��openGL����
	
	@˵����Ҫ��g3dRenderWindow::initGLWindow()����
					initGLWindow()��ʹ��Ⱦ�����ܹ�ִ��openGL����
					initGL�ǳ�ʼ��openGL����
	
	@��������
	
	@�޸���ʷ���߼���, 2012/8/14������
	*/
	void initGL();

private:

	///��Դ������������LightCount
	unsigned int LC;

	///����������ָ��
	g3dSceneManager* m_pSceneManager;
	///��Դ��������
	std::map<std::string, g3dLightWrapper*> m_LightWrpMap;
	///��Ⱦ����ָ��
	g3dRenderWindow* m_RenderWindow;
	
};

