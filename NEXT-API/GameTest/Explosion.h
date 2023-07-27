//-----------------------------------------------------------------------------
// Explosion.h
// Holds data for explosion game objects
//-----------------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "ExplosionRenderer.h"
#include "CircleCollider2D.h"
#include "Timer.h"

class Explosion : public GameObject
{
public:
	Explosion();
	~Explosion();

	ExplosionRenderer* GetRenderer() { return dynamic_cast<ExplosionRenderer*>(components.at(1)); }
	CircleCollider2D* GetCollider() { return dynamic_cast<CircleCollider2D*>(components.at(2)); }

	void Update(float dt);

	void SetPosition(float x, float y);
	void OnCollision();

private:
	Timer m_timer;
};

