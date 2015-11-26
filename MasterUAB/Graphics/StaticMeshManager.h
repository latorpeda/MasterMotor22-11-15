#include "Importer\TemplatedMapManager.h"
#include "Meshes\StaticMesh.h"

class CStaticMeshManager : public CTemplatedMapManager<CStaticMesh>
{
protected:
	std::string m_FileName;
public:
	CStaticMeshManager();
	~ CStaticMeshManager ();
	bool Load(const std::string &FileName);
	bool Reload();
};