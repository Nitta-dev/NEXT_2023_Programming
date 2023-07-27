//-----------------------------------------------------------------------------
// RenderSystem.h
// Holds methods to draw shapes
//-----------------------------------------------------------------------------
#pragma once
#include "Singleton.h"
#include "Rect.h"
#include "Circle.h"
#include "Vector2.h"
#include <vector>

class RenderSystem : public Singleton<RenderSystem>
{
public:
	void DrawRect(Rect* rect, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawDoor(Rect* rect, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawBrick(Rect* rect, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawDiamond(Rect* rect, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawPolygon(std::vector<Vector2> vertices, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawCircle(Circle* circle, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	void DrawCircle(Circle* circle, int segments, float radians, float r = 1.0f, float g = 1.0f, float b = 1.0f);
};

