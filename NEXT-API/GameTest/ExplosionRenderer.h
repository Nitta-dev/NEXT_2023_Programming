#pragma once
#include "ShapeRenderer.h"
#include "Vector2.h"

/// <summary>
/// Renderer class that draws a custom shape
/// </summary>
class ExplosionRenderer : public ShapeRenderer
{
public:
	ExplosionRenderer(float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void Render();
	void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

private:
	Vector2 m_position;
};

