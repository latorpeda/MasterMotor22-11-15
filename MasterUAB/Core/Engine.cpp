#include "Engine.h"


CEngine::CEngine(){
	CEngine.effectsManager = NULL;
	CEngine.materialManager = NULL;
	CEngine.renderableObjectManager = NULL;
	CEngine.staticMeshManager = NULL,
	CEngine.textureManager = NULL;
} 
CEngine::~CEngine(){
	delete(CEngine.effectsManager);
	delete(CEngine.materialManager);
	delete(CEngine.renderableObjectManager);
	delete(CEngine.staticMeshManager);
	delete(CEngine.textureManager);
	CEngine.effectsManager = NULL;
	CEngine.materialManager = NULL;
	CEngine.renderableObjectManager = NULL;
	CEngine.staticMeshManager = NULL,
	CEngine.textureManager = NULL;
} //Destruimos vars

void CEngine::Init(){
	effectsManager = new CEffectManager;
	textureManager = new CTextureManager;
	materialManager = new CMaterialManager;
	renderableObjectManager = new CRenderableObjectsManager;
	staticMeshManager = new CStaticMeshManager;
}