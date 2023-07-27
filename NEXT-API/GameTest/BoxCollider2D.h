//-----------------------------------------------------------------------------
// BoxCollider2D.h
// 2D collider class for boxes
//-----------------------------------------------------------------------------
#pragma once
#include "Rect.h"
#include "Collider2D.h"

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

