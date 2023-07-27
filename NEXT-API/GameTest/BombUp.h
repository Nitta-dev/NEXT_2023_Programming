//-----------------------------------------------------------------------------
// BombUp.h
// Holds data for the Bomb Up panel object
//-----------------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "DiamondRenderer.h"
#include "BoxCollider2D.h"

class BombUp : public GameObject
{
public:
	BombUp();
	~BombUp();

	DiamondRenderer* GetRenderer() { return dynamic_cast<DiamondRenderer*>(components.at(1)); }
	BoxCollider2D* GetCollider() { return dynamic_cast<BoxCollider2D*>(components.at(2)); }

	void Update(float dt);

	void SetPosition(float x, float y);
	void OnCollision();
};

