#pragma once
#include "Circle.h"
#include "Collider2D.h"

/// <summary>
/// Collider for 2D physics representing a circle
/// </summary>
class CircleCollider2D : public Circle, public Collider2D
{
public:
	CircleCollider2D();
	CircleCollider2D(int layer, std::vector<int> collisionLayers);
	void SetScale(float s) { radius = s / 2; }

	bool Colliding(Rect* rect);
	bool Colliding(Circle* circle);
};

