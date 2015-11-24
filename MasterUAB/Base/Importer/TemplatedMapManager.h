#include <string>
#include <map>

template<class T>
class CTemplatedMapManager
{
protected:
	typedef std::map<std::string, T*> TMapResource;
	TMapResource m_Resources;
public:
	CTemplatedMapManager(){
	
	}
	virtual ~CTemplatedMapManager(){
		Destroy();
	}
	virtual T * GetResource(const std::string &Name){
		return m_Resources.at(Name);
	}
	virtual bool AddResource(const std::string &Name, T *Resource){		
		std::map<std::string, T*>::iterator it;
		it = m_Resources.find(Name);
		if (it == m_Resources.end())
			return false;
		//m_Resources.insert(std::pair<std::string,T*>(Name,Resource));
		m_Resources[Name]=Resource;
		return true;
	}
	void Destroy(){
		std::map<std::string, T*>::iterator it;
		for(it = m_Resources.begin();it!=m_Resources.end(); ++it){
			delete(it->second);
		}
		m_Resources.clear();
	}
};
