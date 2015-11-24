#include "XML\XMLTreeNode.h"

#ifndef FILE_C3DElement
#define FILE_C3DElement 

class C3DElement
{
protected:
	Vect3f m_Position, m_PrevPos;
	float m_Yaw, m_Pitch, m_Roll;
	bool m_TranslationUpdate, m_RotationUpdate, m_ScaleUpdate;
	Mat44f m_TransformMatrix;
	Mat44f m_RotationMatrix;
	Mat44f m_TranslationMatrix;
	Mat44f m_ScaleMatrix;
	Vect3f m_Scale;
public:
	C3DElement();
	C3DElement(const Vect3f &Position){
		m_Position = Position;
	}
	C3DElement(const Vect3f &Position, float Yaw, float Pitch, float Roll){
		m_Position = Position;
		m_Yaw = Yaw;
		m_Pitch = Pitch;
		m_Roll = Roll;
	}
	C3DElement(float Yaw, float Pitch, float Roll){
		m_Yaw = Yaw;
		m_Pitch = Pitch;
		m_Roll = Roll;
	}
	C3DElement(const CXMLTreeNode &XMLTreeNode){
		
	}
	virtual void SetPosition(const Vect3f &Position);
	inline const Vect3f & GetPosition() const{
		return m_Position;
	}
	inline const Vect3f & GetPrevPosition() const{
		return m_PrevPos;
	}
	float GetYaw() const{
		return m_Yaw;
	}
	float GetPitch() const{
		return m_Pitch;
	}
	float GetRoll() const{
		return m_Roll;
	}
	virtual void SetYaw(float Yaw);
	virtual void SetPitch(float Pitch);
	virtual void SetRoll(float Roll);
	virtual void SetYawPitchRoll(float Yaw, float Pitch, float Roll);
	virtual void SetScale(const Vect3f &Scale);
	inline const Vect3f & GetScale() const{
		return m_Scale;
	}
	virtual void Render(CKGRenderManager *RenderManager);

	const Mat44f & GetTransform(){

		return m_TransformMatrix;
	}
};

#endif