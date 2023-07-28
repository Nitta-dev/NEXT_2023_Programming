#include "stdafx.h"
#include "Exit.h"
#include "Settings.h"
#include "Level.h"
#include "GameManager.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"

Exit::Exit()
{
	BoxCollider2D* collider = new BoxCollider2D(LAYERS::DOOR, { LAYERS::PLAYER });
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	float s = Tile::TILE_LENGTH * 0.8f;
	collider->SetScale(s);

	components.push_back(new DoorRenderer(1.0f, 0.0f, 0.0f));
	components.push_back(collider);
}

Exit::~Exit()
{

}

void Exit::Update(float dt)
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

void Exit::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetRenderer()->SetPosition(x, y);
	GetCollider()->SetPosition(x, y);
}

void Exit::OnCollision()
{
	GameManager::Instance().NextStage();
	m_destroy = true;
}
