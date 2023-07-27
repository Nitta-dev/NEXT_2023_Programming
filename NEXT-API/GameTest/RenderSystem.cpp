///////////////////////////////////////////////////////////////////////////////
// Filename: RenderSystem.cpp
// Holds methods to draw shapes
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "RenderSystem.h"
#include "App/app.h"

void RenderSystem::DrawRect(Rect* rect, float r, float g, float b)
{
	float xMin = rect->GetXMin();
	float xMax = rect->GetXMax();
	float yMin = rect->GetYMin();
	float yMax = rect->GetYMax();

	std::vector<Vector2> vertices;
	vertices.push_back(Vector2(xMin, yMin));
	vertices.push_back(Vector2(xMin, yMax));
	vertices.push_back(Vector2(xMax, yMax));
	vertices.push_back(Vector2(xMax, yMin));

	DrawPolygon(vertices, r, g, b);
}

void RenderSystem::DrawDoor(Rect* rect, float r, float g, float b)
{
	float xMin = rect->GetXMin();
	float yMin = rect->GetYMin();
	float yMax = rect->GetYMax();

	float dx = rect->width / 2.0f;

	DrawRect(rect, r, g, b);
	App::DrawLine(xMin + dx, yMin, xMin + dx, yMax, r, g, b);
}

void RenderSystem::DrawBrick(Rect* rect, float r, float g, float b)
{
	float xMin = rect->GetXMin();
	float xMax = rect->GetXMax();
	float yMin = rect->GetYMin();

	float x = rect->width / 3.0f;
	float y = rect->height / 3.0f;

	DrawRect(rect, r, g, b);
	App::DrawLine(xMin, yMin + y, xMax, yMin + y, r, g, b);
	App::DrawLine(xMin, yMin + y * 2, xMax, yMin + y * 2, r, g, b);
	App::DrawLine(xMin + x * 2, yMin, xMin + x * 2, yMin + y, r, g, b);
	App::DrawLine(xMin + x, yMin + y, xMin + x, yMin + y * 2, r, g, b);
}

void RenderSystem::DrawDiamond(Rect* rect, float r, float g, float b)
{
	float xMin = rect->GetXMin();
	float xMax = rect->GetXMax();
	float yMin = rect->GetYMin();
	float yMax = rect->GetYMax();

	float dx = rect->width / 2.0f;
	float dy = rect->height / 2.0f;

	std::vector<Vector2> vertices;
	vertices.push_back(Vector2(xMin, yMin + dy));
	vertices.push_back(Vector2(xMin + dx, yMax));
	vertices.push_back(Vector2(xMax, yMax - dy));
	vertices.push_back(Vector2(xMax - dx, yMin));

	DrawPolygon(vertices, r, g, b);
}

void RenderSystem::DrawPolygon(std::vector<Vector2> vertices, float r, float g, float b)
{
	size_t size = vertices.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		App::DrawLine(vertices.at(i).x, vertices.at(i).y, vertices.at(i + 1).x, vertices.at(i + 1).y, r, g, b);
	}

	App::DrawLine(vertices.at(size - 1).x, vertices.at(size - 1).y, vertices.at(0).x, vertices.at(0).y, r, g, b);
}

void RenderSystem::DrawCircle(Circle* circle, float r, float g, float b)
{
	int segments = 20;
	float radians = 2 * PI / segments;
	DrawCircle(circle, segments, radians, r, g, b);
}

void RenderSystem::DrawCircle(Circle* circle, int segments, float radians, float r, float g, float b)
{
	for (size_t i = 0; i < segments; i++)
	{
		float x = circle->position.x;
		float y = circle->position.y;
		float r = circle->radius;

		float sx = x + r * sinf(i * radians);
		float sy = y + r * cosf(i * radians);
		float ex = x + r * sinf(radians + i * radians);
		float ey = y + r * cosf(radians + i * radians);

		App::DrawLine(sx, sy, ex, ey, r, g, b);
	}
}