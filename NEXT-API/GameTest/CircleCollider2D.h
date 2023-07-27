//-----------------------------------------------------------------------------
// CircleCollider2D.h
// 2D collider class for circles
//-----------------------------------------------------------------------------
#pragma once
#include "Circle.h"
#include "Collider2D.h"

class CircleCollider2D : public Circle, public Collider2D
{
public:
	CircleCollider2D();
	CircleCollider2D(int layer, std::vector<int> collisionLayers);
	void SetScale(float s) { radius = s / 2; }

	bool Colliding(Rect* rect);
	bool Colliding(Circle* circle);
};

