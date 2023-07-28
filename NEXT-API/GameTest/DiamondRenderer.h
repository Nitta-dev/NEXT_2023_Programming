#pragma once
#include "ShapeRenderer.h"
#include "Rect.h"

/// <summary>
/// Renderer class that draws a diamond shape
/// </summary>
class DiamondRenderer : public ShapeRenderer
{
public:
	DiamondRenderer(float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void Render();
	void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

private:
	Vector2 m_position;
};

