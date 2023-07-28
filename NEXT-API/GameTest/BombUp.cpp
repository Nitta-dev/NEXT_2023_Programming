#include "stdafx.h"
#include "BombUp.h"
#include "Settings.h"
#include "Level.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"
#include "GameManager.h"

BombUp::BombUp()
{
	BoxCollider2D* collider = new BoxCollider2D(LAYERS::PICKUP, { LAYERS::PLAYER });
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	float s = Tile::TILE_LENGTH * 0.8f;
	collider->SetScale(s);

	components.push_back(new DiamondRenderer(0.0f, 0.2f, 1.0f));
	components.push_back(collider);
}

BombUp::~BombUp()
{

}

void BombUp::Update(float dt)
{
	if (m_destroy)
	{
		return;
	}

	Collider2D* collider = GameObjectManager::Instance().GetPlayer()->GetCollider();
	if (CollisionSystem2D::Instance().CheckCollision(GetCollider(), { collider }))
	{
		OnCollision();
	}
}

void BombUp::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetRenderer()->SetPosition(x, y);
	GetCollider()->SetPosition(x, y);
}

void BombUp::OnCollision()
{
	GameManager::Instance().BombUp();
	Disable();
	m_destroy = true;
}
