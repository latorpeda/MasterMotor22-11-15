#include <vector>
#include "Utils.h"
#include "StaticMesh.h"
#include "Renderable Vertex\VertexTypes.h"
#include "Textures\Texture.h"
#include "Materials\Material.h"
#include "Renderable Vertex\RenderableVertexs.h"
#include "Engine.h"


CStaticMesh::CStaticMesh():CNamed("")
	, m_BsCenter(0.0f,0.0f,0.0f)
	, m_AabbMin(0.0f,0.0f,0.0f)
	, m_AabbMax(0.0f,0.0f,0.0f)
	, m_BsRadius(0.0f)
	, m_RVs(NULL)
	, m_Materials(NULL)
	, m_NumVertexs(0), m_NumFaces(0)
{
}

CStaticMesh::~CStaticMesh()
{
	Destroy();
}

bool CStaticMesh::Load(const std::string &FileName){
    m_FileName=FileName;
    FILE *l_meshFile = NULL;
    fopen_s(&l_meshFile, FileName.c_str(), "rb");

    if(l_meshFile==NULL)
        return false;
    else{
		//Header---------------------
        unsigned short l_header, l_VertexType, l_numMaterials,l_NumBytes;
        fread(&l_header, sizeof(unsigned short), 1, l_meshFile);   //lectura del header
        if(l_header!=0x55FF){
			return false;
        }
				
		//Materials---------------------	
                
        fread(&l_numMaterials, sizeof(unsigned short), 1, l_meshFile); //lectura del numero de materiales
        if(l_numMaterials==0){
                return false;
        }
        m_Materials.resize(l_numMaterials);
				
        for(int i=0; i<l_numMaterials;++i){  //lectura de los materiales
            unsigned short l_materialType;
            unsigned short l_NumChars;
            unsigned short l_NumTextures=0;
			fread(&l_NumChars, sizeof(unsigned short), 1, l_meshFile);
			
			char *l_MaterialName = new char[l_NumChars+1];
            fread(&l_MaterialName[0], sizeof(char), l_NumChars+1, l_meshFile);

			m_Materials[i]=CEngine::GetSingletonPtr()->getMaterialManager()->GetResource(l_MaterialName);
                    
			//Texturas¿¿¿¿¿se cargan¿?¿
        } 
			
		//Vertex & Index---------------------

		//TODO: en fichero max, leer solo UVMap de x e y
		for(int i=0; i<l_numMaterials;++i){
			//Vertices---------------------
			unsigned short l_VertexType;
			fread(&l_VertexType, sizeof(unsigned short), 1, l_meshFile);

			unsigned short l_NumVertexs;
			fread(&l_NumVertexs, sizeof(unsigned short), 1, l_meshFile);

			unsigned short l_NumBytes;
			if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType())
				l_NumBytes=sizeof(MV_POSITION_NORMAL_TEXTURE_VERTEX)*l_NumVertexs;
			else if(l_VertexType==MV_POSITION_COLOR_VERTEX::GetVertexType())
				l_NumBytes=sizeof(MV_POSITION_COLOR_VERTEX)*l_NumVertexs;
			else if(l_VertexType==MV_POSITION_TEXTURE_VERTEX::GetVertexType())
				l_NumBytes=sizeof(MV_POSITION_TEXTURE_VERTEX)*l_NumVertexs;
			else if(l_VertexType==MV_POSITION_COLOR_TEXTURE_VERTEX::GetVertexType())
				l_NumBytes=sizeof(MV_POSITION_COLOR_TEXTURE_VERTEX)*l_NumVertexs;

			void *l_VtxsData=malloc(l_NumBytes);
			fread(&l_VtxsData, 1, l_NumBytes, l_meshFile);

			//Indices---------------------
			unsigned short l_IndexType;
			fread(&l_IndexType, sizeof(unsigned short), 1, l_meshFile);
				
			unsigned short l_NumIndexsFile;
				
			if(l_IndexType==16)	{					
				fread(&l_NumIndexsFile, sizeof(unsigned short), 1, l_meshFile);
				l_NumBytes=sizeof(unsigned short)*l_NumIndexsFile;
				m_NumVertexs=(unsigned int)l_NumIndexsFile;//Antes m_NumIndexs
			}else if(l_IndexType==32) {					
				fread(&l_NumIndexsFile, sizeof(unsigned int), 1, l_meshFile);
				l_NumBytes=sizeof(unsigned int)*l_NumIndexsFile;
				m_NumVertexs=l_NumIndexsFile;
			} else{
				assert(!"Num Index Error");
			}

			void *l_IdxData=malloc(l_NumBytes);
			fread(&l_IdxData, 1, l_NumBytes, l_meshFile);

			CRenderableVertexs *l_RV=NULL;
	
			if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType()){
				if(l_IndexType==16)
					l_RV=new CKGTriangleListRenderableIndexed16Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
				else
					l_RV=new CKGTriangleListRenderableIndexed32Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
			} else if(l_VertexType==MV_POSITION_NORMAL_TEXTURE_VERTEX::GetVertexType()) {
				if(l_IndexType==16)
					l_RV=new CKGTriangleListRenderableIndexed16Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
				else
					l_RV=new CKGTriangleListRenderableIndexed32Vertexs<MV_POSITION_NORMAL_TEXTURE_VERTEX>(l_VtxsData, l_NumVertexs, l_IdxData, l_NumIndexsFile);
			}
	
			m_RVs.push_back(l_RV);	
	
			free(l_VtxsData);
			free(l_IdxData);
		}
			
		//Footer---------------------
        unsigned short l_footer;
        fread(&l_footer, sizeof(unsigned short), 1, l_meshFile);   
        if(l_footer!=0xFF55){                     
                return false;
        }
    }
    return true;
}

void CStaticMesh::Render(CContextManager *ContextManager) const{
    for(size_t i=0; i<m_RVs.size(); ++i){
		for(size_t j=0; j< CStaticMesh.m_Materials.size(); ++j){
			CEngine::GetSingletonPtr()->getTextureManager()->GetTexture(m_Materials[i]->GetName())->Activate(j);
		}		
		m_RVs[i]->Render(ContextManager, NULL,NULL);
    }
}


bool CStaticMesh::Reload(){
    Destroy();
    if(Load(m_FileName))
        return true;
    else
        return false;
};

void CStaticMesh::Destroy(){
       for(int i=0;i<m_RVs.size();i++){
		delete m_RVs[i];
	}
	for(int i=0;i<m_Materials.size();i++){
		delete m_Materials[i];
	}
	m_RVs.clear();
	m_Materials.clear();
	m_BsCenter(0.0f,0.0f,0.0f);
	m_AabbMin(0.0f,0.0f,0.0f);
	m_AabbMax(0.0f,0.0f,0.0f);
	m_BsRadius=(0.0f);
}