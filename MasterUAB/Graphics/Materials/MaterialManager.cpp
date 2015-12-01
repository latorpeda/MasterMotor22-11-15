#include "MaterialManager.h"

CMaterialManager::CMaterialManager(){
//	CMaterialManager.CTemplatedMapManager();
}

CMaterialManager::~CMaterialManager(){
	Destroy();
}

void CMaterialManager::Load(const std::string &Filename){	
	AddResource(Filename,new CMaterial(Filename));
}

void CMaterialManager::Reload(){
	/*std::map<std::string, CMaterial>::iterator it;
	for(it = m_Resources.begin(); it != m_Resources.end(); ++it){
		std::string filename = it->second.GetName();
		it->second.Destroy();
		it->second = CMaterial(filename);
	}*/
}