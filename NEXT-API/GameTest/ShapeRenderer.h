//-----------------------------------------------------------------------------
// ShapeRenderer.h
// Base class for drawing shapes
//-----------------------------------------------------------------------------
#pragma once
#include "Renderer.h"
#include "Vector3.h"

class ShapeRenderer : public Renderer
{
public:
	void SetColour(float r, float g, float b) { m_colour = Vector3(r, g, b); }

protected:
	Vector3 m_colour;
};

