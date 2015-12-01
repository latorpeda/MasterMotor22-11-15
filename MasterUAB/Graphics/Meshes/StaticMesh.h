#ifndef STATIC_MESH_H
#define STATIC_MESH_H

#include <vector>
#include "string"
#include "Utils.h"
#include "Renderable Vertex\VertexTypes.h"
#include "Textures\Texture.h"
#include "Materials\Material.h"
#include "Renderable Vertex\RenderableVertexs.h"

class CStaticMesh : public CNamed
{
protected:
	Vect3f m_BsCenter, m_AabbMin, m_AabbMax;
	float m_BsRadius;
	std::vector<CRenderableVertexs*> m_RVs;
	std::vector<CMaterial *> m_Materials;
	unsigned int m_NumVertexs, m_NumFaces;
	std::string m_FileName;

public:
	CStaticMesh();
	virtual ~CStaticMesh();

	bool Load (const std::string &FileName);
	bool Reload ();
	void Render(CContextManager *ContextManager) const;
	void Destroy();

};     

#endif