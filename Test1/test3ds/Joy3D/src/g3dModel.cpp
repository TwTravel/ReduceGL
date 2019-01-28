#include "g3dModel.h"



//------------------------------------------------------------------------------------------------
g3dModel::g3dModel(g3dMesh* mesh)
	:HasParent(false)
{
	m_Mesh=mesh;
	m_Name=mesh->m_Name;
}

//------------------------------------------------------------------------------------------------
g3dModel::~g3dModel()
{

}

//------------------------------------------------------------------------------------------------
void g3dModel::RenderModel()
{
	if(m_Mesh!=NULL)
		m_Mesh->RenderMesh();
}

//------------------------------------------------------------------------------------------------
Vector3 g3dModel::getSphereCenter(void) const
{
	if(m_Mesh!=NULL)
		return m_Mesh->getSphereCenter();
	else
		return Vector3(0,0,0);
}
//------------------------------------------------------------------------------------------------
float g3dModel::getSphereRadius(void) const
{
	if(m_Mesh!=NULL)
		return m_Mesh->getSphereRadius();
	else
		return 0;
}

//------------------------------------------------------------------------------------------------
Vector3 g3dModel::getBoundingBoxMax(void) const
{
	if(m_Mesh!=NULL)
		return m_Mesh->getBoundingBoxMax();
	else
		return Vector3(0,0,0);
}

//------------------------------------------------------------------------------------------------
Vector3 g3dModel::getBoundingBoxMin(void) const
{
	if(m_Mesh!=NULL)
		return m_Mesh->getBoundingBoxMin();
	else
		return Vector3(0,0,0);
}
//------------------------------------------------------------------------------------------------
/*
g3dModel::g3dModel(void)
	:
	HasParent(false)
{
}


g3dModel::~g3dModel(void)
{
	if(m_pMaterial!=NULL)
		delete m_pMaterial;
	if(m_pObject!=NULL)
		delete m_pObject;
}

g3dModel::g3dModel(t3DObject* object,tMaterialInfo* material,GLuint texture)
	:
HasParent(false)
{
	m_pMaterial=new g3dMaterial(material,texture);
	m_pObject=new g3dObject(object);
	m_Name=m_pObject->m_Name;//Ĭ�ϲ���object��name
	GenDisplayList();
}

bool g3dModel::GenDisplayList()
{
	//������ʾ�б�
	m_DisplayList=glGenLists(1);
	if(m_DisplayList!=0)
	{
		glNewList(m_DisplayList,GL_COMPILE);

		glBegin(GL_TRIANGLES);	
		for(int j=0;j<this->m_pObject->m_FaceSet.size();j++)
		{
			for(int whichVertex=0;whichVertex<3;whichVertex++)
			{
				// ������ÿ���������
				int index=m_pObject->m_FaceSet[j].vertIndex[whichVertex];
					// ����������
				glNormal3f(m_pObject->m_NormalSet[ index ].x, m_pObject->m_NormalSet[ index ].y,m_pObject->m_NormalSet[ index ].z);
				// ��������������
				if(m_pObject->HasTexture)
				{
					// ȷ���Ƿ���UVW��������
					if(m_pObject->m_TexVertSet.size()>0)
					{
						glTexCoord2f(m_pObject->m_TexVertSet[index].x, m_pObject->m_TexVertSet[index].y);
					}
				}
				else
				{
					glColor3ub(m_pMaterial->m_RGB[0], m_pMaterial->m_RGB[1], m_pMaterial->m_RGB[2]);
				}
				glVertex3f(m_pObject->m_VertexSet[ index ].x, m_pObject->m_VertexSet[ index ].y,m_pObject->m_VertexSet[ index ].z);
			}
		}
		glEnd();

		glEndList();
	}
	else
		return false;
}

void g3dModel::DrawModel()
{
	if(this->m_pObject->HasTexture)
	{
		// ������ӳ��
		glEnable(GL_TEXTURE_2D);
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D,this->m_pMaterial->m_Texture);
	}
	else
	{
		// �ر�����ӳ��
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255, 255, 255);
	}
	//������ʾ�б�
	glCallList(m_DisplayList);

}





g3dObject::g3dObject(t3DObject* pobject)
{
	if(pobject!=NULL)
	{
		HasTexture=pobject->bHasTexture;
		m_Name=string(pobject->strName);
		//��ʼ��������Ϣ
		for(int i=0;i<pobject->numOfVerts;i++)
		{
			m_VertexSet.push_back(pobject->pVerts[i]);
			m_NormalSet.push_back(pobject->pNormals[i]);
		}		
		//��ʼ������������Ϣ
		for(int i=0;i<pobject->numTexVertex;i++)
			m_TexVertSet.push_back(pobject->pTexVerts[i]);
		//��ʼ������Ϣ
		for(int i=0;i<pobject->numOfFaces;i++)
		{
			m_FaceSet.push_back(pobject->pFaces[i]);
		}		
	}
	else
	{
		HasTexture=false;
	}
}
g3dObject::~g3dObject(void)
{

}


g3dMaterial::g3dMaterial(tMaterialInfo* pmaterial,GLuint texture)
{
	if(pmaterial!=NULL)
	{
		m_RGB[0]=pmaterial->color[0];
		m_RGB[1]=pmaterial->color[1];
		m_RGB[2]=pmaterial->color[2];
		m_Name=string(pmaterial->strName);
		m_Texture=texture;
	}
}


g3dMaterial::~g3dMaterial(void)
{
}
*/