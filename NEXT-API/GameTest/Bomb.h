//-----------------------------------------------------------------------------
// Bomb.h
// Holds data for bomb game objects
//-----------------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "CircleRenderer.h"
#include "CircleCollider2D.h"
#include "Timer.h"

class Bomb : public GameObject
{
public:
	Bomb();
	~Bomb();

	CircleRenderer* GetRenderer() { return dynamic_cast<CircleRenderer*>(components.at(1)); }
	CircleCollider2D* GetCollider() { return dynamic_cast<CircleCollider2D*>(components.at(2)); }

	void Update(float dt);
	void Cleanup();

	void SetPosition(float x, float y);
	void OnCollision();
	void GenerateExplosion();

private:
	Timer timer;
};

