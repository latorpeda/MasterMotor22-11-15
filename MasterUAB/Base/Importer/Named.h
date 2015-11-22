#include <string>
#include <XML\XMLTreeNode.h>

class CNamed
{
protected:
	std::string m_Name;
public:
	CNamed(const CXMLTreeNode &TreeNode);
	CNamed(const std::string &Name);
	virtual void SetName(const std::string &Name){ m_Name=Name; }
	virtual const std::string &GetName(){return m_Name;}
}; 
