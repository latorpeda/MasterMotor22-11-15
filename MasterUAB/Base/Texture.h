#include "Importer\Named.h"
#include <string>
#include <d3d11.h>

class CTexture : CNamed
{
private:
	ID3D11ShaderResourceView *m_Texture;
	ID3D11SamplerState *m_SamplerState;

	virtual bool LoadFile();
	void Unload();
public:
	CTexture(){
		CTexture.m_Texture = NULL;
		m_SamplerState = NULL;
	}
	virtual ~CTexture(){
		Unload();
		delete(m_SamplerState);
	}
	bool Load(const std::string &Filename);
	void Activate(unsigned int StageId);
	bool Reload();
};