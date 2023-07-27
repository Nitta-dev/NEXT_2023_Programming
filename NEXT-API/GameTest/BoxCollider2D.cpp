///////////////////////////////////////////////////////////////////////////////
// Filename: BoxCollider2D.cpp
// 2D collider class for boxes
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "BoxCollider2D.h"
#include "Settings.h"

BoxCollider2D::BoxCollider2D()
{
	position = Vector2::Zero();
	width = 1;
	height = 1;
	m_layer = LAYERS::DEFAULT;
	m_collisionLayers = { 0 };
}

BoxCollider2D::BoxCollider2D(int layer, std::vector<int> collisionLayers)
{
	position = Vector2::Zero();
	width = 1;
	height = 1;
	m_layer = layer;
	m_collisionLayers = collisionLayers;
}

bool BoxCollider2D::Colliding(Rect* rect)
{
	return Overlaps(rect);
}

bool BoxCollider2D::Colliding(Circle* circle)
{
	double dx = abs(position.x - circle->position.x);
	double dy = abs(position.y - circle->position.y);

	if (dx > width / 2 + circle->radius ||
		dy > height / 2 + circle->radius)
	{
		return false;
	}

	if (dx <= width / 2 ||
		dy <= height / 2)
	{
		return true;
	}

	double dist = pow(dx - width / 2, 2) + pow(dy - height / 2, 2);

	return dist <= pow(circle->radius, 2);
}