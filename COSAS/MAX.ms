fn Init =  (
	format "____Init____\n"
)		

fn GetLevelName = (
	return maxFilePath /*+ "Data\\Level\\"*/
)

fn GetCores = (
	return $*
	)
fn GetInstances = (
	return $*
)


fn GetYaw transform =
(
	return -(transform as eulerangles).z
)
fn GetPitch transform =
(
	return -(transform as eulerangles).y
)
fn GetRoll transform =
(
	return (transform as eulerangles).x
) 


fn TranslationToRH translation =
(
	return point3 -translation.x translation.z translation.y
) 

fn createStaticMeshes = (
	local file=createfile (GetLevelName()+"static_meshes.xml" )
	local cores = GetCores()
	format "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n" to:file
	format "<static_meshes>\n" to:file
	for i=1 to cores.count do(
		format "\t<static_mesh name=\"%\" filename=\"%.mesh\">\n" cores[i].name (GetLevelName()+cores[i].name) to:file
		)
	
	format "</static_meshes>\n" to:file 
	format "____CreatedStatic____\n"
	close file
	)
	
fn createRenderableObjects = (
	local file=createfile (GetLevelName()+"renderable_objects.xml" )
	local instances = GetInstances()
	format "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n" to:file
	format "<renderable_objects>\n" to:file
	for i=1 to instances.count do(
		format "\t<mesh_instance name=\"%\" core_name=\"%\" pos=\"%\" yaw=\"%\" pitch=\"0.0\" roll=\"0.0\" visible=\"%\">\n" instances[i].name instances[i].name TranslationToRH(instances[i].transform.translation) GetYaw(instances[i].transform) instances[i].visibility to:file
		)

	format "</renderable_objects>\n" to:file 
	format "____CreatedRenderableObjects____\n"
	close file
)	

fn createMaterials = (
	local file=createfile (GetLevelName()+"materials.xml" )
	
	local cores = GetCores()
	format "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n" to:file
	format "<materials>\n" to:file
	for i=1 to cores.count do( --undefined
		if classof cores[i].material == Standardmaterial then (				
			format "\t<material name=\"%\" effect_technique=\"diffuse_technique\" >\n" cores[i].material.name (GetLevelName()+cores[i].material.name) to:file		
			if cores[i].material.diffuseMap != undefined and cores[i].material.diffuseMap.bitmap != undefined then ( --TODO: comprobar difuso no bitmap??
				format "\t\t <texture filename=\"%\"/>\n" cores[i].material.diffuseMap.filename to:file
			)else(
				messageBox ("¡¡¡El material "+cores[i].material.name+" de la malla "+cores[i].name+" tiene las texturas mal!!!") title:"MENSAJE PARA ARTISTAS" 
			)
			format "\t</material>\n" to:file 
		) else (
			for j = 1 to cores[i].material.numsubs do (
				--Si ya existe no exportamos
				format "\t<material name=\"%\" effect_technique=\"diffuse_technique\" >\n" cores[i].material[j].name (GetLevelName()+cores[i].material[j].name) to:file	
				if cores[i].material[j].diffuseMap != undefined and cores[i].material[j].diffuseMap.bitmap != undefined then ( --TODO: comprobar difuso no bitmap??
					format "\t\t <texture filename=\"%\"/>\n" cores[i].material[j].diffuseMap.filename to:file
				)else(
					messageBox ("¡¡¡El material "+cores[i].material.name+" de la malla "+cores[i].name+" tiene las texturas mal!!!") title:"MENSAJE PARA ARTISTAS" 
				)
				format "\t</material>\n" to:file 
			)
		)
	)
	
	format "</materials>\n" to:file 
	format "____CreatedMaterials____\n"
	close file
)

fn createMeshes = (
	local cores = GetCores()
	for i=1 to cores.count do (
			createMesh(cores[i])
	)

)

global file

fn createMesh obj = (
	file = fopen  (GetLevelName()+obj.name+".mesh" ) "wb"
	
	--Header
	writeshort file 0xFE55
	local numMats
	
	--Materials
	if classof obj.material == Standardmaterial then (
		numMats=1
		writeshort file 1
		writeshort file obj.material.name.count
		writestring file obj.material.name
	) else if classof obj.material  == Multimaterial then (
		numMats = obj.material.numsubs
		writeshort file obj.material.numsubs
		for mats=1 to obj.material.numsubs do (			
			writeshort file obj.material[mats].name.count
			writestring file obj.material[mats].name
		)
	)else (
			--No Material????
	)
	
	--SubMesh
	local numSubMeshes = obj.numsubs
	/*for j = 1 to numSubMeshes do (
	
	)
	*/
	/*
	Cada submalla:
	-verts
	-indexes
	*/
	--Vertex
	--TODO: Evitar duplicados
	for i=1 to numMats do (
		writeshort file 19 --vertexType
		writeshort file obj.mesh.numverts --TODO: coger vertices afectados por ese mat...
		for numFace = 1 to getNumFaces obj.mesh do (
			local IdxsFace=getFace obj.mesh numFace 
			local MaterialID=getFaceMatID obj.mesh IdxsFace[1] --TODO iterar por cada materialID 
			local vertexInfo = createVertex obj.mesh IdxsFace numFace
			writeshort file vertexInfo
		)	
	)
	
	--Index
	writeshort file 16 --Tamaño indice
	for i=1 to numMats do (
		
		for numFace = 1 to getNumFaces obj do (
			writeshort file getFace obj numFace --TA MAL?
		)
	)
	
	--Footer
	writeshort file 0xFE55
		
	fflush file
	fclose file
	format "____CreatedMeshes____\n"
)

--Solo le pasamos un indice!!!! no es idxs --> idx Face
fn createVertex obj IdxsFace IdFace = (
	-- Para coger los vértices de la primera cara
	local Vtx1=getVert obj IdxsFace.x
	local Vtx2=getVert obj IdxsFace.y
	local Vtx3=getVert obj IdxsFace.z
	-- Para coger las normales de los vértices de la primera cara
	local Normal1=getNormal obj IdxsFace.x
	local Normal2=getNormal obj IdxsFace.y
	local Normal3=getNormal obj IdxsFace.z
	/* Para coger los índices de las coordenadas de textura de la primera cara, el 1 señala al primer
	conjunto de coordenadas aplicadas sobre la cara */
	local IdxsMap=meshop.getMapFace obj 1 IdFace
	-- Para coger las coordenadas de los vértices de la primera cara
	local TUVMap1= meshop.getMapVert obj 1 IdxsMap.x
	local TUVMap2= meshop.getMapVert obj 1 IdxsMap.y
	local TUVMap3= meshop.getMapVert obj 1 IdxsMap.z 
	
	return #(Vtx1,Vtx2,Vtx3,Normal1,Normal2,Normal3,TUVMap1,TUVMap2,TUVMap3)

)

	
	
Init()
createStaticMeshes()
createRenderableObjects()
createMaterials()
createMeshes()

/*
Crear implementaciones text, mat, effects q lean los xml
en Data\ 
- effects.xml
- uabposition.fx (copiar codigo hecho)
*/