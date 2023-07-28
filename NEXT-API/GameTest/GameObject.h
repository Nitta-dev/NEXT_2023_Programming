#pragma once
#include "Object.h"
#include "Behaviour.h"
#include "Transform.h"
#include <vector>

/// <summary>
/// Basic class for all entities
/// </summary>
class GameObject : public Object, public Behaviour
{
public:
	GameObject();

	virtual void SetPosition(float x, float y);
	virtual void SetRotation(float x, float y);
	virtual void SetScale(float s);

	void SetTransform(Transform* transform) { components.at(0) = transform; }
	void SetTilePos(int tileX, int tileY) { m_tileX = tileX; m_tileY = tileY; }
	void SetDestroy(bool value = true) { m_destroy = value; }
	Transform* GetTransform() { return dynamic_cast<Transform*>(components.at(0)); }
	int GetTileX() { return m_tileX; }
	int GetTileY() { return m_tileY; }
	void GetTilePos(int& x, int& y) { x = m_tileX; y = m_tileY; }
	bool GetDestroy() { return m_destroy; }

	int layer;
	std::string tag;

	/// <summary>
	/// Gets the component of the specified type, if it exists
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="temp"></param>
	/// <returns></returns>
	template<typename T>
	bool TryGetComponent(T& temp)
	{
		for each (Component * component in components)
		{
			temp = dynamic_cast<T>(component);
			if (temp != NULL)
			{
				return true;
			}
		}

		return false;
	}

protected:
	int m_tileX;
	int m_tileY;
	std::vector<Component*> components;
	bool m_destroy;
};

