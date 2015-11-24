#include "EffectManager.h"


CEffectManager::CEffectManager(){

}

CEffectManager::~CEffectManager(){

}
void CEffectManager::Reload(){

}
void CEffectManager::Load(const std::string &Filename){

}

CEffectVertexShader * CEffectManager::GetVertexShader(const std::string &VertexShader){
	//TODO: SEARCH NAME
	return CEffectManager.m_VertexShaders;
}
CEffectPixelShader * CEffectManager::GetPixelShader(const std::string &PixelShader){
	//TODO: SEARCH NAME
	return CEffectManager.m_PixelShaders;
}