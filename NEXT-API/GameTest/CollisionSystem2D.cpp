///////////////////////////////////////////////////////////////////////////////
// Filename: CollisionSystem2D.cpp
// Holds methods to check collisions
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "CollisionSystem2D.h"

bool CollisionSystem2D::CheckCollision(BoxCollider2D* other, std::vector<Collider2D*> colliders)
{
	std::vector<int> collisionLayers = other->GetCollisionLayers();
	for each (Collider2D * collider in colliders)
	{
		int layer = collider->GetLayer();
		if (std::count(collisionLayers.begin(), collisionLayers.end(), layer))
		{
			if (collider->Colliding(other))
			{
				return true;
			}
		}
	}

	return false;
}

bool CollisionSystem2D::CheckCollision(CircleCollider2D* other, std::vector<Collider2D*> colliders)
{
	int layer = other->GetLayer();
	for each (Collider2D * collider in colliders)
	{
		std::vector<int> collisionLayers = collider->GetCollisionLayers();
		if (std::count(collisionLayers.begin(), collisionLayers.end(), layer))
		{
			if (collider->Colliding(other))
			{
				return true;
			}
		}
	}

	return false;
}