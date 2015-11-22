#include "Importer\MapManager.h"
#include "Importer\TemplatedVectorMapManager.h"

class Cls
{
};

void Dummy()
{
	CTemplatedMapManager<Cls> l_X;
	l_X.AddResource("hola", new Cls);
	Cls *l_A=l_X.GetResource("hola");
	l_X.Destroy();

	CTemplatedVectorMapManager<Cls> vecMap;
	vecMap.AddResource("hola", new Cls);
	Cls *l_A2=vecMap.GetResource("hola");
	Cls *l_B = vecMap.GetResourceById(0);
	vecMap.Destroy();
}
