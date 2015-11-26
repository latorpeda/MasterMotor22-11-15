#include "Material.h"

void CMaterial::Destroy(){
	delete(&m_Textures);
	delete(&m_EffectTechnique);
}

CMaterial::CMaterial(CXMLTreeNode &l_XML){
	CXMLTreeNode l_materials = l_XML["materials"];
	if (l_materials.Exists())
	{
		for (int i = 0; i < l_materials.GetNumChildren(); ++i){
			CXMLTreeNode l_mat = l_materials(i);

			if (l_mat.GetName() == std::string("material")){
				CXMLTreeNode &l_material = l_mat;

				CMaterial.m_Name = l_material.GetPszProperty("name");
				CMaterial.m_EffectTechnique->m_Name = l_material.GetPszProperty("effect_technique");
				if(l_mat(0).GetName() == std::string("texture")){
					CXMLTreeNode l_text = l_mat(0);
					//Asignamos textura
					// = l_text.GetPszProperty("filename");
				}				
			}
		}
	}
}

CMaterial::~CMaterial(){
}

void CMaterial::Apply(){
}