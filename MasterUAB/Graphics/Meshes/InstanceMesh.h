#include "Renderable Objects\RenderableObject.h"
#include "Meshes\StaticMesh.h"
#include "ContextManager.h"

class CInstanceMesh : public CRenderableObject
{
private:
	CStaticMesh *m_StaticMesh;
public:
	CInstanceMesh(const std::string &Name, const std::string &CoreName);
	~CInstanceMesh();
	void Render(CContextManager *RM);
};