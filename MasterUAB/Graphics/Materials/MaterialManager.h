#include "Importer\TemplatedMapManager.h"

class CMaterialManager : public CTemplatedMapManager<CMaterial>
{
private:
	std::string m_Filename;
public:
	CMaterialManager();
	virtual ~CMaterialManager();
	void Load(const std::string &Filename);
	void Reload();
};