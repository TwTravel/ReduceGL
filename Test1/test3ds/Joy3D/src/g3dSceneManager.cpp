#include "g3dSceneManager.h"


///������������־λ����ʱ��
#define G3D_ERROR_TEXTURE 9999  


//------------------------------------------------------------------------------------------------
g3dSceneManager::g3dSceneManager(void)
	:m_Ambient(0.2,0.2,0.2,1.0)
{
	m_pRootNode=new g3dSceneNode("RootNode");	
	m_SceneNodeMap[(m_pRootNode->m_Name)]=m_pRootNode;
}
//------------------------------------------------------------------------------------------------
g3dSceneManager::~g3dSceneManager(void)
{

	//����m_SceneNodeMap�����еĽڵ㣬����m_pRootNode
	for(map<string,g3dSceneNode*>::iterator it=m_SceneNodeMap.begin();it!=m_SceneNodeMap.end();it++)
	{
		//�жϷǿ�
		if(it->second!=NULL)
			delete it->second;
	}

	//����m_LightMap�����еƹ�
	for(map<string,g3dLight*>::iterator it=m_LightMap.begin();it!=m_LightMap.end();it++)
	{
		if(it->second!=NULL)
			delete it->second;
	}

	//����MeshMap�����е�Mesh
	for(map<string,g3dMesh*>::iterator it=m_MeshMap.begin();it!=m_MeshMap.end();it++)
	{
		if(it->second!=NULL)
			delete it->second;
	}

	//����m_CameraMap������Camera
	for(std::map<std::string,g3dCamera*>::iterator it=m_CameraMap.begin();it!=m_CameraMap.end();it++)
	{
		if(it->second!=NULL)
		{
			delete it->second;
		}
	}
}
//------------------------------------------------------------------------------------------------
g3dModel* g3dSceneManager::CreateModel(std::string filename)
{
	g3dMesh* Mesh=CreateMesh(filename);
	g3dModel* Model=new g3dModel(Mesh);
	return Model;
}
//------------------------------------------------------------------------------------------------
void g3dSceneManager::setAmbientColor(float r,float g,float b)
{
	m_Ambient.r=r;
	m_Ambient.g=g;
	m_Ambient.b=b;
	m_Ambient.a=1.0f;
}
//------------------------------------------------------------------------------------------------
ColorValue g3dSceneManager::getAmbientColor(void) const
{
	return m_Ambient;
}
//------------------------------------------------------------------------------------------------
g3dSceneNode* g3dSceneManager::getRootNode(void)
{
	return m_pRootNode;
}
//------------------------------------------------------------------------------------------------
g3dSceneNode* g3dSceneManager::CreateSceneNode(std::string name)
{
	g3dSceneNode* newNode=new g3dSceneNode(name);
	if(newNode!=NULL)
		m_SceneNodeMap[newNode->m_Name]=newNode;
	return newNode;
}
//------------------------------------------------------------------------------------------------
g3dLight* g3dSceneManager::CreateLight(std::string name)
{
	if(m_LightMap.size()<8)
	{
		g3dLight* newLight=new g3dLight(name);
		if(newLight!=NULL)
			m_LightMap[newLight->m_Name]=newLight;
		return newLight;
	}
	else
		return NULL;
	
}

//------------------------------------------------------------------------------------------------
g3dMesh* g3dSceneManager::CreateMesh(std::string filename)
{
	//����һ��t3DModel����ʱ����
	//���ڶ�ȡ3DS��ʽ�ļ���
	t3DModel temp;
	m_Load3ds.Import3DS(&temp, filename.c_str());	
	// �������еĲ���,��������
	for(int i = 0; i < temp.numOfMaterials; i++)
	{
		// �ж��Ƿ���һ���ļ���
		if(strlen(temp.pMaterials[i].strFile) > 0)
		{
			//  ʹ�������ļ�������װ��λͼ
			unsigned int textureID=CreateTexture( temp.pMaterials[i].strFile);
			if(textureID!=G3D_ERROR_TEXTURE)
			{
				// ���ò��ʵ�����ID
				temp.pMaterials[i].texureId = textureID;
			}
			else
			{
				temp.pMaterials[i].texureId =-1;
			}

		}	
		else
		{
			temp.pMaterials[i].texureId =-1;
		}
		
	}
	//�½�Mesh
	g3dMesh *mesh=new g3dMesh();
	mesh->m_Name=filename;
	for(int i=0;i<temp.numOfObjects;i++)
	{
		int materialID=temp.pObject[i].materialID;
		//�½�SubMesh
		g3dSubMesh* newSubMesh=
			new g3dSubMesh(&temp.pObject[i],&temp.pMaterials[materialID],(GLuint)temp.pMaterials[materialID].texureId);
		//�ж�textureID�Ƿ�Ϸ�����Ч
		if (temp.pMaterials[materialID].texureId==-1)
		{
			//��SubMesh����Ϊ������
			newSubMesh->setHasTextrue(false);
		} 
		else
		{
			//��SubMesh����Ϊ������
			newSubMesh->setHasTextrue(true);
		}

		//��SubMesh���뵽Mesh��
		mesh->addSubMesh(newSubMesh);
	}
	//��ʼ��Bounding Box��Ϣ
	mesh->initBoundingBox();
	m_MeshMap[mesh->m_Name]=mesh;
	
	return mesh;
	
}

//------------------------------------------------------------------------------------------------
g3dCamera* g3dSceneManager::CreateCamera(std::string name)
{
	g3dCamera* cam=new g3dCamera(name);
	if(cam!=NULL)
		m_CameraMap[cam->m_Name]=cam;
	return cam;
}

//------------------------------------------------------------------------------------------------
unsigned int  g3dSceneManager::CreateTexture(LPSTR strFileName)
{
	AUX_RGBImageRec *pBitmap = NULL;

	unsigned int textureID;

	if(!strFileName)
	{
		// ����޴��ļ����򷵻�G3D_ERROR_TEXTURE(G3D_ERROR_TEXTURE��ʾ����
		return G3D_ERROR_TEXTURE;
	}
	// װ��λͼ������������
	pBitmap = auxDIBImageLoadA(strFileName);				
	// ���װ��λͼʧ�ܣ����˳�
	if(pBitmap == NULL)									
		exit(0);

	// ��������
	glGenTextures(1, &textureID);
	// �������ض����ʽ
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	glBindTexture(GL_TEXTURE_2D, textureID);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap->sizeX, pBitmap->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pBitmap->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);

	// �ͷ�λͼռ�õ���Դ
	if (pBitmap)										
	{
		if (pBitmap->data)						
		{
			free(pBitmap->data);				
		}

		free(pBitmap);					
	}
	return textureID;
}
//------------------------------------------------------------------------------------------------

