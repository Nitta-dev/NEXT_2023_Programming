#include "stdafx.h"
#include "Tile.h"
#include "Settings.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"
#include "RenderSystem.h"
#include "GameManager.h"
#include "Exit.h"
#include "FireUp.h"
#include "BombUp.h"

Tile::Tile()
{
	name = "Tile";

	BoxCollider2D* collider = new BoxCollider2D(LAYERS::DEFAULT, { LAYERS::EXPLOSION });
	collider->width = TILE_LENGTH;
	collider->height = TILE_LENGTH;
	float s = 0.8f * static_cast<float>(Tile::TILE_LENGTH);
	collider->SetScale(s);

	components.push_back(collider);

	m_colour = Vector3(0.9f, 0.9f, 0.9f);
}

Tile::~Tile()
{

}

void Tile::Init()
{

}

void Tile::Update(float dt)
{
	if (m_id == BlockType::NONE || m_id == BlockType::HARD || m_id == BlockType::DOOR_OPEN)
	{
		return;
	}

	std::vector<Collider2D*> colliders;
	GameObjectManager::Instance().GetComponents(colliders);
	if (CollisionSystem2D::Instance().CheckCollision(GetCollider(), colliders))
	{
		OnCollision();
	}
}

void Tile::Render()
{
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;

	if (m_id == BlockType::DOOR_OPEN)
	{

	}
	if (m_id == BlockType::DOOR_CLOSE)
	{
		Rect* rect = new Rect();
		rect->position = GetCollider()->position;
		rect->width = GetCollider()->width * 0.9f;
		rect->height = GetCollider()->height * 0.9f;
		RenderSystem::Instance().DrawBrick(rect, r, g, b);
		//RenderSystem::Instance().DrawBrick(rect, 1.0f, 0.3f, 0.0f);
	}
	if (m_id == BlockType::HARD)
	{
		Rect* rect = new Rect();
		rect->position = GetCollider()->position;
		rect->width = GetCollider()->width * 0.9f;
		rect->height = GetCollider()->height * 0.9f;
		RenderSystem::Instance().DrawRect(rect, r, g, b);
	}
	if (m_id == BlockType::SOFT)
	{
		Rect* rect = new Rect();
		rect->position = GetCollider()->position;
		rect->width = GetCollider()->width * 0.9f;
		rect->height = GetCollider()->height * 0.9f;
		RenderSystem::Instance().DrawBrick(rect, r, g, b);
	}
}

void Tile::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetCollider()->SetPosition(x, y);
}

void Tile::OnCollision()
{
	int id = Level::Instance().GetMapID(m_mapX, m_mapY);

	int x, y;
	GetMapPos(x, y);
	int newId = (id == -1) ? -2 : 0;
	if (newId == -2)
	{
		Transform* transform = GetTransform();
		float x = transform->position.x;
		float y = transform->position.y;

		Exit* exit = new Exit();
		exit->SetPosition(x, y);
		exit->SetTilePos(m_tileX, m_tileY);
		GameObjectManager::Instance().ClearGameObjects();
		GameObjectManager::Instance().AddGameObject(exit);
	}
	else
	{
		if (rand() % 100 <= PERCENT_PANEL_CHANCE)
		{
			Transform* transform = GetTransform();
			float x = transform->position.x;
			float y = transform->position.y;

			if (rand() % 100 <= 50)
			{
				FireUp* panel = new FireUp();
				panel->SetPosition(x, y);
				panel->SetTilePos(m_tileX, m_tileY);
				GameObjectManager::Instance().ClearGameObjects();
				GameObjectManager::Instance().AddGameObject(panel);
			}
			else
			{
				BombUp* panel = new BombUp();
				panel->SetPosition(x, y);
				panel->SetTilePos(m_tileX, m_tileY);
				GameObjectManager::Instance().ClearGameObjects();
				GameObjectManager::Instance().AddGameObject(panel);
			}
		}
	}

	Level::Instance().SetMapID(x, y, newId);
	Level::Instance().RefreshAllTileID();
}