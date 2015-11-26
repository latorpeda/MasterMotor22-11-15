#include <Utils\SingletonPattern.h>
#include "StaticMeshManager.h"
#include "RenderableObjectsManager.h"
#include "Materials\MaterialManager.h"
#include "Effects\EffectManager.h"
#include "Textures\TextureManager.h"

class CEngine : public CSingleton<CEngine>{
public:
	CStaticMeshManager * staticMeshManager;
	CRenderableObjectsManager * renderableObjectManager;
	CMaterialManager * materialManager;
	CEffectManager * effectsManager;
	CTextureManager * textureManager;

public:
	CEngine(); //Construimos vars y hacemos gets
	virtual ~CEngine(); //Destruimos vars

	void Init();

	//GETS
	CStaticMeshManager * getStaticMeshManager(){ return staticMeshManager;}
	CRenderableObjectsManager * getRenderableObjectManager(){ return renderableObjectManager;}
	CMaterialManager * getMaterialManager(){ return materialManager;}
	CEffectManager * getEffectsManager(){ return effectsManager;}
	CTextureManager * getTextureManager(){ return textureManager;}	
};