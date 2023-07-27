///////////////////////////////////////////////////////////////////////////////
// Filename: DoorRenderer.cpp
// Renderer class that draws a custom shape
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DoorRenderer.h"
#include "Rect.h"
#include "Tile.h"
#include "RenderSystem.h"

DoorRenderer::DoorRenderer(float r, float g, float b)
{
	m_colour = Vector3(r, g, b);
	m_position = Vector2::Zero();
}

void DoorRenderer::Render()
{
	Rect* rect = new Rect();
	rect->position = m_position;
	rect->width = Tile::TILE_LENGTH * 0.8f;
	rect->height = Tile::TILE_LENGTH * 0.8f;
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;
	RenderSystem::Instance().DrawDoor(rect, r, g, b);
}