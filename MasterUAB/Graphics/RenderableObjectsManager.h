#include "Importer\TemplatedVectorMapManager.h"
#include "XML\XMLTreeNode.h"

class CRenderableObjectsManager : public CTemplatedVectorMapManager<CRenderableObject>
{
private:

public:
	CRenderableObjectsManager();
	virtual ~CRenderableObjectsManager();
	void Update(float ElapsedTime);
	void Render(CRenderManager *RM);
	CRenderableObject * AddMeshInstance(const std::string &CoreMeshName, const std::string &InstanceName, const Vect3f &Position);
	CRenderableObject * AddMeshInstance(CXMLTreeNode &TreeNode);
	CRenderableObject * AddAnimatedInstanceModel(const std::string &CoreModelName, const std::string &InstanceModelName, const Vect3f &Position);
	//Que haga return null
	void Load(const std::string &FileName);
};