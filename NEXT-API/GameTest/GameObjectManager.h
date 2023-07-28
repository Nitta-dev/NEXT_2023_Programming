#pragma once
#include "Behaviour.h"
#include "Singleton.h"
#include "GameObject.h"
#include <vector>
#include "PlayerController.h"

/// <summary>
/// Manages all game objects
/// </summary>
class GameObjectManager : public Behaviour, public Singleton<GameObjectManager>
{
public:
	GameObjectManager();
	void Init();
	void Update(float dt);
	void Render();
	void Cleanup();

	PlayerController* GetPlayer() { return m_player; }
	void AddGameObject(GameObject* obj);
	void RemoveGameObject(GameObject* obj);
	void ShiftGameObjectsLeft();
	void ShiftGameObjectsRight();

	GameObject* Find(std::string name);
	GameObject* FindWithTag(std::string tag);
	void ClearGameObjects();

	std::vector<GameObject*> GetGameObjects() { return m_gameObjects; }

	template <class T>
	void GetComponents(std::vector<T>& components)
	{
		for each (GameObject* obj in m_gameObjects)
		{
			T component;
			if (obj->TryGetComponent(component))
			{
				components.push_back(component);
			}
		}
	}

protected:
	PlayerController* m_player;
	std::vector<GameObject*> m_gameObjects;
};