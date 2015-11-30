#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <vector>
#include <Importer\Named.h>
#include "..\Textures\Texture.h"
#include "..\Effects\EffectTechnique.h"
#include "Utils.h"


class CMaterial : public CNamed
{
private:
	std::vector<CTexture *> m_Textures;
	CEffectTechnique *m_EffectTechnique;
	
public:
	void Destroy();
	CMaterial(const std::string &Filename);
	virtual ~CMaterial();
	virtual void Apply();
	UAB_GET_PROPERTY(CEffectTechnique, EffectTechnique);
};

#endif
