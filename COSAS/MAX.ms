fn Init =  (
	format "____Init____\n"
)		

fn GetLevelName = (
	return maxFilePath + "Data\\Level\\"
)

fn GetCores = (
	return $*
	)
fn GetInstances = (
	return $*
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
		--<mesh_instance name="box01" core_name="box01" pos="0.0 0.0 0.0" yaw="0.0" pitch="0.0" roll="0.0" visible="true"/>
		format "\t<mesh_instance name=\"%\" core_name=\"%\" pos=\"0.0 0.0 0.0\" yaw=\"0.0\" pitch=\"0.0\" roll=\"0.0\" visible=\"true\">\n" instances[i].name instances[i].name to:file
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
	for i=1 to cores.count do(
if cores[i].material 		
		format "\t<material name=\"%\" filename=\"%\">\n" cores[i].name cores[i].name to:file		
	)
	
	format "</materials>\n" to:file 
	format "____CreatedMaterials____\n"
	close file
)

fn createMeshes = (
	local cores = GetCores()
	for i=1 to cores.count do(
			createMesh(cores[i])
	)

)
global file

fn createMesh obj= (
	file = openFile  (GetLevelName()+obj.name+"2.mesh" ) mode:"wb"
	
	writeshort file 0xFE55
	
	
	
	writeshort file 0xFE55
	
	close file
	
)
	
	
Init()
createStaticMeshes()
createRenderableObjects()
createMaterials()
createMeshes()

