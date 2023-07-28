#include "stdafx.h"
#include "Explosion.h"
#include "Settings.h"
#include "Level.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"

Explosion::Explosion()
{
	CircleCollider2D* collider = new CircleCollider2D(LAYERS::EXPLOSION, { });
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	float s = Tile::TILE_LENGTH;
	collider->SetScale(s);

	components.push_back(new ExplosionRenderer(1.0f, 0.0f, 0.0f));
	components.push_back(collider);

	m_timer = Timer(0.5f);
}

Explosion::~Explosion()
{

}

void Explosion::Update(float dt)
{
	m_timer.Update(dt);

	if (m_timer.Trigger())
	{
		Disable();
		m_destroy = true;
	}
}

void Explosion::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetRenderer()->SetPosition(x, y);
	GetCollider()->SetPosition(x, y);
}

void Explosion::OnCollision()
{

}
