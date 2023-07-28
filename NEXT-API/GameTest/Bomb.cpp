#include "stdafx.h"
#include "Bomb.h"
#include "Settings.h"
#include "RenderSystem.h"
#include "Level.h"
#include "GameObjectManager.h"
#include "GameManager.h"
#include "Explosion.h"

Bomb::Bomb()
{
	name = "Bomb";

	CircleCollider2D* collider = new CircleCollider2D(LAYERS::DEFAULT, { LAYERS::ENEMY });
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	float s = 0.8f * static_cast<float>(Tile::TILE_LENGTH);
	collider->SetScale(s);

	components.push_back(new CircleRenderer(collider, 0.0f, 0.0f, 1.0f));
	components.push_back(collider);

	timer = Timer(2.5f);
}

Bomb::~Bomb()
{

}

void Bomb::Update(float dt)
{
	if (m_destroy)
	{
		return;
	}

	timer.Update(dt);

	if (timer.Trigger())
	{
		GenerateExplosion();
		Disable();
		m_destroy = true;
	}
}

void Bomb::Cleanup()
{
	GameObjectManager::Instance().GetPlayer()->SubNumBombs();
}

void Bomb::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetCollider()->SetPosition(x, y);
}

void Bomb::OnCollision()
{

}

void Bomb::GenerateExplosion()
{
	std::vector<Vector2> positions;
	Transform* transform = GetTransform();
	float x = transform->position.x;
	float y = transform->position.y;
	positions.push_back(Vector2(x, y));

	for (size_t i = 1; i < GameObjectManager::Instance().GetPlayer()->GetBlastRadius() + 1; i++)
	{
		if (m_tileX < Level::GRID_WIDTH - 1 && m_tileX + i < Level::GRID_WIDTH)
		{
			if (Level::Instance().GetTile(m_tileX + i, m_tileY).GetID() != Tile::BlockType::HARD)
			{
				positions.push_back(Vector2(x + i * Tile::TILE_LENGTH, y));
			}
		}
		if (m_tileX > 0 && m_tileX - i >= 0)
		{
			if (Level::Instance().GetTile(m_tileX - i, m_tileY).GetID() != Tile::BlockType::HARD)
			{
				positions.push_back(Vector2(x - i * Tile::TILE_LENGTH, y));
			}
		}
		if (Level::Instance().GetTile(m_tileX, m_tileY + i).GetID() != Tile::BlockType::HARD)
		{
			positions.push_back(Vector2(x, y + i * Tile::TILE_LENGTH));
		}
		if (Level::Instance().GetTile(m_tileX, m_tileY - i).GetID() != Tile::BlockType::HARD)
		{
			positions.push_back(Vector2(x, y - i * Tile::TILE_LENGTH));
		}
	}

	for (size_t i = 0; i < positions.size(); i++)
	{
		Vector2 position = positions.at(i);
		Explosion* explosion = new Explosion();
		explosion->SetPosition(position.x, position.y);
		GameObjectManager::Instance().AddGameObject(explosion);
	}
}