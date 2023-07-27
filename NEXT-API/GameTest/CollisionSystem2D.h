//-----------------------------------------------------------------------------
// CollisionSystem2D.h
// Holds methods to check collisions
//-----------------------------------------------------------------------------
#pragma once
#include "Singleton.h"
#include "Collider2D.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include <vector>

class CollisionSystem2D : public Singleton<CollisionSystem2D>
{
public:
	bool CheckCollision(BoxCollider2D* other, std::vector<Collider2D*> colliders);
	bool CheckCollision(CircleCollider2D* other, std::vector<Collider2D*> colliders);
};

