#pragma once
#include "Rect.h"
#include "Collider2D.h"

/// <summary>
/// Collider for 2D physics representing a rectangle
/// </summary>
class BoxCollider2D : public Rect, public Collider2D
{
public:
	BoxCollider2D();
	BoxCollider2D(int layer, std::vector<int> collisionLayers);
	void SetScale(float s) { width = s; height = s; }
	void SetScale(float x, float y) { width = x; height = y; }

	bool Colliding(Rect* rect);
	bool Colliding(Circle* circle);
};

