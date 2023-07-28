#pragma once
#include "GameObject.h"
#include "DiamondRenderer.h"
#include "BoxCollider2D.h"

/// <summary>
/// Holds data for the Fire Up panel object
/// </summary>
class FireUp : public GameObject
{
public:
	FireUp();
	~FireUp();

	DiamondRenderer* GetRenderer() { return dynamic_cast<DiamondRenderer*>(components.at(1)); }
	BoxCollider2D* GetCollider() { return dynamic_cast<BoxCollider2D*>(components.at(2)); }

	void Update(float dt);

	void SetPosition(float x, float y);
	void OnCollision();
};

