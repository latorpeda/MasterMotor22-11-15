utility UABUtility "UabUtility" width:168 height:405
(
	button SetPath_Button "Set Path" pos:[13,8] width:140 height:31
	label Path_Label "Path Selected" pos:[16,49] width:126 height:14
	checkbox ExportMesh_Enabled "Export Mesh" pos:[13,87] width:166 height:22
	checkbox CopyTextures_enabled "Copy Textures" pos:[13,116] width:166 height:22
	button ExportLights_Button "Lights" pos:[19,224] width:55 height:29
	button ExportMesh_Button "Mesh" pos:[82,224] width:55 height:29
	button ExportCamera_Button "Camera" pos:[18,260] width:55 height:29
	button ExportStaticMesh_Button "Static Mesh Manager" pos:[19,297] width:122 height:27
	button ExportScene_Button "Scene" pos:[18,327] width:123 height:27
	button Close_Button "Close" pos:[36,373] width:83 height:19
	GroupBox Group1 "Export" pos:[7,206] width:145 height:155
	dropdownList LevelList "Selec. Nivel" pos:[15,153] width:136 height:40
	
	
	on UABUtility open do
	(	
		Path_Label.text = "D:\RepoMasterOK\COSAS\Data\Level" 
		local levels=#("level 1","level 2", "level 3","level 4", "main menu", "select player")
		LevelList.items=levels
	)
	on SetPath_Button pressed do
	(		
		local l_path=getSavePath caption:"Select Game Folder" initialDir:Path_Label.text
		if l_path!=undefined then(
			Path_Label.text = l_path
		)
	)
)

