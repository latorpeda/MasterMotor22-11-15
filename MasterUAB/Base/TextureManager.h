#include "Importer\MapManager.h"
#include "Importer\Texture.h"

/*CTextureManager: el constructor inicializar� los atributos de la clase
CTextureManager.
- ~CTextureManager: el destructor eliminar� la textura llamando al m�todo
Destroy.
- Reload: recorrer� todos los resources del MapManager y har� el reload de
cada una de las texturas*/

class CTextureManager : public CTemplatedMapManager<CTexture>
{
public:
	CTextureManager();
	virtual ~CTextureManager();
	CTexture * GetTexture(const std::string &Filename);
	void Reload();
};