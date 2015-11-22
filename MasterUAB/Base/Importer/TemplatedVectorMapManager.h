#include <string>
#include <map>
#include <vector>
#include <assert.h>

//CTexture(); pone a null lo de dx11
//reload unload y load

//textManager
//gettexture, si no la encuentras con getResources la cargamos, metemos en el array y devolvemos

//c3delement meter en Utils

template<class T>
class CTemplatedVectorMapManager
{
public:
	class CMapResourceValue
	{
		public:
			T* m_Value;
			size_t m_Id;

			CMapResourceValue(){
				assert(!"MAL");
			}

			CMapResourceValue(T *Value, size_t Id)
					: m_Value(Value)
					, m_Id(Id) 
			{}

	};
	typedef std::vector<T *> TVectorResources;
	typedef std::map<std::string, CMapResourceValue> TMapResources;

protected:
	TVectorResources m_ResourcesVector;
	TMapResources m_ResourcesMap;

public:
	CTemplatedVectorMapManager(){

	}
	virtual ~CTemplatedVectorMapManager() {
		Destroy();
	}

	bool RemoveResource(const std::string &Name){
		std::map<std::string, CMapResourceValue>::iterator it;
		it = m_ResourcesMap.find(Name);
		if (it == m_ResourcesMap.end())
			return false;
		//Decrementar ID de los siguientes...antes de destruirlo
		delete(it->second.m_Value);
		m_ResourcesVector.erase(it->second.m_Id);
		m_ResourcesMap.erase(it);
		return true;
	}

	virtual T * GetResourceById(size_t Id){
		return m_ResourcesVector[Id];
	}

	virtual T* GetResource(const std::string &Name){
		return m_ResourcesMap[Name].m_Value;
	}

	bool AddResource(const std::string &Name, T *Resource){
		std::map<std::string, CMapResourceValue>::iterator it;
		it = m_ResourcesMap.find(Name);
		if (it != m_ResourcesMap.end())
			return false;

		m_ResourcesMap[Name] = CMapResourceValue(Resource,m_ResourcesVector.size());
		m_ResourcesVector.push_back(Resource);
		return true;
	}
	
	void Destroy(){
		//erase del vector, del mpapa y delete del puntero
		std::map<std::string, CTemplatedVectorMapManager<T>::CMapResourceValue>::iterator it;
		for(it = m_ResourcesMap.begin();it!=m_ResourcesMap.end(); ++it)
		{
			delete(it->second.m_Value);
		}
		m_ResourcesVector.clear();
		m_ResourcesMap.clear();
	}

	TMapResources & GetResourcesMap(){
		return *TMapResources;
	}

	TVectorResources & GetResourcesVector(){
		return *TVectorResources;
	}
}; 
