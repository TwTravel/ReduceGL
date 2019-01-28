#include "g3dSubMesh.h"


g3dSubMesh::g3dSubMesh(t3DObject* object,tMaterialInfo* material,GLuint texture)
{
	m_pMaterial=new g3dMaterial(material,texture);
	m_pObject=new g3dObject(object);
	//Ĭ�ϲ���object��name
	m_Name=m_pObject->m_Name;
	GenDisplayList();
}

void g3dSubMesh::setHasTextrue(bool b)
{
	m_pObject->HasTexture=b;
}

bool g3dSubMesh::GenDisplayList()
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

		return true;
	}
	else
		return false;
}

void g3dSubMesh::RenderSubMesh()
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
		//Ϊm_Minϵ�и�һ����ֵ���Ա�ѭ��ʱ�Ƚ�
		m_MinZ=pobject->pVerts[0].z;
		m_MinX=pobject->pVerts[0].x;
		m_MinY=pobject->pVerts[0].y;
		//��m_Maxϵ�г�ʼ��Ϊm_Minϵ��
		m_MaxX=m_MinX;
		m_MaxY=m_MinY;
		m_MaxZ=m_MinZ;
		//��ʼ��������Ϣ
		for(int i=0;i<pobject->numOfVerts;i++)
		{
			//�Ƚ����ֵ
			if (pobject->pVerts[i].x>m_MaxX)
				m_MaxX=pobject->pVerts[i].x;
			if (pobject->pVerts[i].y>m_MaxY)
				m_MaxY=pobject->pVerts[i].y;
			if(pobject->pVerts[i].z>m_MaxZ)
				m_MaxZ=pobject->pVerts[i].z;
			//�Ƚ���Сֵ
			if (pobject->pVerts[i].x<m_MinX)
				m_MinX=pobject->pVerts[i].x;
			if (pobject->pVerts[i].y<m_MinY)
				m_MinY=pobject->pVerts[i].y;
			if(pobject->pVerts[i].z<m_MinZ)
				m_MinZ=pobject->pVerts[i].z;
			//��ֵ
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

g3dSubMesh::~g3dSubMesh(void)
{
}
