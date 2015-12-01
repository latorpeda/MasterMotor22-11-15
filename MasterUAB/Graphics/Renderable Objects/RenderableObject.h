#include "C3DElement.h"
#include "Importer\Named.h"
#include "ContextManager.h"

class CRenderableObject : public C3DElement, public CNamed {
public:
	CRenderableObject();
	virtual ~CRenderableObject() {}
	virtual void Update(float ElapsedTime) {}
	virtual void Render(CContextManager *RM) = 0;
};