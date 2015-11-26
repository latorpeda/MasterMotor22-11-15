#include "MaterialManager.h"

CMaterialManager::CMaterialManager(){

}
CMaterialManager::~CMaterialManager(){
	CMaterialManager.Destroy();
}

void CMaterialManager::Load(const std::string &Filename){
	
	CMaterialManager.AddResource(Filename,new CMaterial(Filename));
}

void CMaterialManager::Reload(){
	//Reload mat, unload y load todos
	std::map<std::string, CMaterial>::iterator it;
	for(it = CMaterialManager::m_Resources.begin(); it!=CMaterialManager::m_Resources.end(); ++it){
		delete(it->second.Destroy());
		it->second = CMaterial(
	}
	m_Resources.clear();
}