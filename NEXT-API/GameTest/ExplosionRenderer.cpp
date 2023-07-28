#include "stdafx.h"
#include "ExplosionRenderer.h"
#include "Circle.h"
#include "Tile.h"
#include "RenderSystem.h"

ExplosionRenderer::ExplosionRenderer(float r, float g, float b)
{
	m_colour = Vector3(r, g, b);
	m_position = Vector2::Zero();
}

void ExplosionRenderer::Render()
{
	Circle* circle = new Circle();
	circle->position = m_position;
	circle->radius = Tile::TILE_LENGTH / 2.0f;
	int segments = 20;
	float radians = 360.0f / 10;
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;
	RenderSystem::Instance().DrawCircle(circle, segments, radians, r, g, b);
}