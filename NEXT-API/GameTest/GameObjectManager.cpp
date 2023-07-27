///////////////////////////////////////////////////////////////////////////////
// Filename: GameObjectManager.cpp
// Manages all game objects
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "GameObjectManager.h"
#include "Collider2D.h"
#include "CollisionSystem2D.h"
#include "Renderer.h"
#include "Tile.h"
#include "Level.h"

GameObjectManager::GameObjectManager()
{

}

void GameObjectManager::Init()
{
	m_player = new PlayerController();
	m_player->Init();
	m_player->Disable();
}

void GameObjectManager::Update(float dt)
{
	if (m_player->Enabled())
	{
		m_player->Update(dt);
	}

	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects.at(i)->Enabled())
		{
			m_gameObjects.at(i)->Update(dt);
		}

		if (i == m_gameObjects.size() - 1)
		{
			if (m_gameObjects.at(i)->GetDestroy())
			{
				GameObject* obj = m_gameObjects.at(i);
				m_gameObjects.pop_back();
				obj->Cleanup();
				delete obj;
			}
		}
	}
}

void GameObjectManager::Render()
{
	if (m_player->Enabled() && m_player->GetRenderer()->Enabled())
	{
		m_player->GetRenderer()->Render();
	}

	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		Renderer* renderer;
		if (m_gameObjects.at(i)->TryGetComponent(renderer))
		{
			if (m_gameObjects.at(i)->Enabled() && renderer->Enabled())
			{
				renderer->Render();
			}
		}
	}
}

void GameObjectManager::Cleanup()
{

}

void GameObjectManager::AddGameObject(GameObject* obj)
{
	m_gameObjects.push_back(obj);
}

void GameObjectManager::RemoveGameObject(GameObject* obj)
{
	int index = -1;
	auto iterate = std::find(m_gameObjects.begin(), m_gameObjects.end(), obj);

	if (iterate != m_gameObjects.end())
	{
		// Calculate the index of obj
		index = iterate - m_gameObjects.end();
	}

	if (index > -1)
	{
		m_gameObjects.erase(m_gameObjects.begin() + index);
	}
	else
	{
		// Element not found in vector
	}
}

void GameObjectManager::ShiftGameObjectsLeft()
{
	for each (GameObject* obj in m_gameObjects)
	{
		Transform* transform = obj->GetTransform();
		float x = transform->position.x;
		float y = transform->position.y;
		x -= Tile::TILE_LENGTH;
		obj->SetPosition(x, y);

		int tileX, tileY;
		obj->GetTilePos(tileX, tileY);
		obj->SetTilePos(tileX - 1, tileY);

		if (tileX - 1 < 0)
		{
			obj->Disable();
			obj->SetDestroy();
		}
	}
}

void GameObjectManager::ShiftGameObjectsRight()
{
	for each (GameObject * obj in m_gameObjects)
	{
		Transform* transform = obj->GetTransform();
		float x = transform->position.x;
		float y = transform->position.y;
		x += Tile::TILE_LENGTH;
		obj->SetPosition(x, y);

		int tileX, tileY;
		obj->GetTilePos(tileX, tileY);
		obj->SetTilePos(tileX + 1, tileY);

		if (tileX + 1 >= Level::GRID_WIDTH)
		{
			obj->Disable();
			obj->SetDestroy();
		}
	}
}

GameObject* GameObjectManager::Find(std::string name)
{
	for each (GameObject* obj in m_gameObjects)
	{
		if (obj->name == name)
		{
			return obj;
		}
	}
}

GameObject* GameObjectManager::FindWithTag(std::string tag)
{
	for each (GameObject* obj in m_gameObjects)
	{
		if (obj->tag == tag)
		{
			return obj;
		}
	}
}

void GameObjectManager::ClearGameObjects()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.at(i)->Cleanup();
	}
	m_gameObjects.clear();
}