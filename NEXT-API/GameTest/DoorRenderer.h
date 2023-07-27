//-----------------------------------------------------------------------------
// DoorRenderer.h
// Renderer class that draws a custom shape
//-----------------------------------------------------------------------------
#pragma once
#include "ShapeRenderer.h"
#include "Vector2.h"

class DoorRenderer : public ShapeRenderer
{
public:
	DoorRenderer(float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void Render();
	void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

private:
	Vector2 m_position;
};