//-----------------------------------------------------------------------------
// Collider2D.h
// Base class for 2D collider classes
//-----------------------------------------------------------------------------
#pragma once
#include "Component.h"
#include "Rect.h"
#include "Circle.h"
#include <vector>

class Collider2D : public Component
{
public:
	void SetLayer(int layer) { m_layer = layer; }
	void SetCollisionLayers(const std::vector<int>& layers) { m_collisionLayers = layers; }
	int GetLayer() { return m_layer; }
	std::vector<int> GetCollisionLayers() { return m_collisionLayers; }

	virtual bool Colliding(Rect* rect) { return false; }
	virtual bool Colliding(Circle* circle) { return false; }

protected:
	int m_layer;
	std::vector<int> m_collisionLayers;
};

