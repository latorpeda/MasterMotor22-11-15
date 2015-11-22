#include <Importer\Named.h>


CNamed::CNamed(const CXMLTreeNode &TreeNode){
	m_Name = TreeNode.GetPszProperty("name");
}
CNamed::CNamed(const std::string &Name){
	m_Name = Name;
}