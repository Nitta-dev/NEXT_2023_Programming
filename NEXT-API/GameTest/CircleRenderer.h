#pragma once
#include "ShapeRenderer.h"
#include "Circle.h"

/// <summary>
/// Renderer class that draws a circle shape
/// </summary>
class CircleRenderer : public ShapeRenderer
{
public:
	CircleRenderer(Circle* circle, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void Render();
	void SetCircle(Circle* circle) { m_circle = circle; }

private:
	Circle* m_circle;
};

