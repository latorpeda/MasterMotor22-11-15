#include "Importer\MapManager.h"
#include "Importer\Texture.h"

/*CTextureManager: el constructor inicializará los atributos de la clase
CTextureManager.
- ~CTextureManager: el destructor eliminará la textura llamando al método
Destroy.
- Reload: recorrerá todos los resources del MapManager y hará el reload de
cada una de las texturas*/

class CTextureManager : public CTemplatedMapManager<CTexture>
{
public:
	CTextureManager();
	virtual ~CTextureManager();
	CTexture * GetTexture(const std::string &Filename);
	void Reload();
};