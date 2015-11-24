#include <vector>
#include "Importer\Named.h"
#include "RenderableVertexs.h"
#include "Materials\Material.h"

class CStaticMesh : public CNamed
{
protected:
	std::vector<CRenderableVertexs*> m_RVs;
	std::vector<CMaterial *> m_Materials;
	unsigned int m_NumVertexs, m_NumFaces;
public:
	CStaticMesh();
	~CStaticMesh();
	bool Load (const std::string &FileName);
	bool Reload ();
	void Render (CRenderManager *RM) const;
}; /*getLevelName(){	return Data\level}staticMeshes.xml (pdf)	nombre y ruta	renderableObjects.xml (hecho)	generar a partir d as instancias*/xml dentro	\meshes	mesh x caja (7)	/*GetCores()	return all objects in scene $. (all)	generar staticmeshes.xml	GetInstances()	return $.	renderobjects.xml*/	materials.xml 	info del mat	meshes.xml de cores los dos	geom 	normal 	coord text		meshes.xml	cabecera para identificar archivo correcto: 0xFE55	mat: numMats lenName name,  map#1 (luego sacaremos de mat.xml)	vert vertextType(19) (definir del mat, para saber si tiene normales...etc) numVerts  vert (coord, normal, textCoord) )= x numMats	ind sizeOb(idx)=tamIndice (16) numIndices ind	fin para saber si lecturaOK 0x55FE		codigo en meshobj	- getValues(con geom normals y textCoord)	-createVertext devolver los arrays d floats 	-en getVertextId evitar duplicados	- paths relativos	CreateMesh	exportmesh (recibe nombrefichero)	- create file	-header	-export materials (on, handle)	- export submeshes	MIERCOLES