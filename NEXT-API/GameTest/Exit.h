#pragma once
#include "GameObject.h"
#include "DoorRenderer.h"
#include "BoxCollider2D.h"

/// <summary>
/// Holds data for the stage exit object
/// </summary>
class Exit : public GameObject
{
public:
	Exit();
	~Exit();

	DoorRenderer* GetRenderer() { return dynamic_cast<DoorRenderer*>(components.at(1)); }
	BoxCollider2D* GetCollider() { return dynamic_cast<BoxCollider2D*>(components.at(2)); }

	void Update(float dt);

	void SetPosition(float x, float y);
	void OnCollision();
};

