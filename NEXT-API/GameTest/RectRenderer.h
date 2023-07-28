#pragma once
#include "ShapeRenderer.h"
#include "Rect.h"

/// <summary>
/// Renderer class that draws a rectangle shape
/// </summary>
class RectRenderer : public ShapeRenderer
{
public:
	RectRenderer(Rect* rect, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void Render();
	void SetRect(Rect* rect) { m_rect = rect; }

private:
	Rect* m_rect;
};

