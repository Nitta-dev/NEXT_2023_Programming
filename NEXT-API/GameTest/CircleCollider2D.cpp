#include "stdafx.h"
#include "CircleCollider2D.h"

CircleCollider2D::CircleCollider2D()
{
	position = Vector2::Zero();
	radius = 1;
}

CircleCollider2D::CircleCollider2D(int layer, std::vector<int> collisionLayers)
{
	position = Vector2::Zero();
	radius = 1;
	m_layer = layer;
	m_collisionLayers = collisionLayers;
}

bool CircleCollider2D::Colliding(Rect* rect)
{
	double dx = abs(rect->position.x - position.x);
	double dy = abs(rect->position.y - position.y);

	if (dx > rect->width / 2 + radius ||
		dy > rect->height / 2 + radius)
	{
		return false;
	}

	if (dx <= rect->width / 2 ||
		dy <= rect->height / 2)
	{
		return true;
	}

	double dist = pow(dx - rect->width / 2, 2) + pow(dy - rect->height / 2, 2);

	return dist <= pow(radius, 2);
}

bool CircleCollider2D::Colliding(Circle* circle)
{
	return Overlaps(circle);
}
