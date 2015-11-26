#include <vector>
#include "Importer\Named.h"
#include "RenderableVertexs.h"
#include "Materials\Material.h"

class CStaticMesh : public CNamed
{
protected:
	std::vector<CRenderableVertexs*> m_RVs;
	std::vector<CMaterial *> m_Materials;
	unsigned int m_NumVertexs, m_NumFaces;
public:
	CStaticMesh();
	~CStaticMesh();
	bool Load (const std::string &FileName);
	bool Reload ();
	void Render (CRenderManager *RM) const;
}; 