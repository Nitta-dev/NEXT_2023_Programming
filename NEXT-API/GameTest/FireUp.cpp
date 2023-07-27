///////////////////////////////////////////////////////////////////////////////
// Filename: FireUp.cpp
// Holds data for the Fire Up panel object
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "FireUp.h"
#include "Settings.h"
#include "Level.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"
#include "GameManager.h"

FireUp::FireUp()
{
	BoxCollider2D* collider = new BoxCollider2D(LAYERS::PICKUP, { LAYERS::PLAYER });
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	float s = Tile::TILE_LENGTH * 0.8f;
	collider->SetScale(s);

	components.push_back(new DiamondRenderer(1.0f, 0.2f, 0.0f));
	components.push_back(collider);
}

FireUp::~FireUp()
{

}

void FireUp::Update(float dt)
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

void FireUp::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetRenderer()->SetPosition(x, y);
	GetCollider()->SetPosition(x, y);
}

void FireUp::OnCollision()
{
	GameManager::Instance().FireUp();
	Disable();
	m_destroy = true;
}

