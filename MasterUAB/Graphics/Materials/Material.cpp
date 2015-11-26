#include "Material.h"


void CMaterial::Destroy(){
	delete(&m_Textures);
	//delete(&m_EffectTechnique);
}

CMaterial::CMaterial(const std::string &Filename){ :CNamed("")
	CXMLTreeNode TreeNode; 
	TreeNode.LoadFile(Filename.c_str());
	CXMLTreeNode l_materials = TreeNode["materials"];
	if (l_materials.Exists()){
		for (int i = 0; i < l_materials.GetNumChildren(); ++i){
			CXMLTreeNode l_material = l_materials(i);

			if (l_material.GetName() == std::string("material")){
				//CMaterial.m_Name = l_material.GetPszProperty("name");
				//CMaterial.m_EffectTechnique->SetName(l_material.GetPszProperty("effect_technique"));
				/*if(l_material(0).GetName() == std::string("texture")){
					CXMLTreeNode l_text = l_material(0);
					CTexture* text = new CTexture;
					text->Load(l_text.GetPszProperty("filename"));
					CMaterial.m_Textures.push_back(text);
				}	*/			
			}
		}
	}
}

CMaterial::~CMaterial(){

}

void CMaterial::Apply(){

}
