///////////////////////////////////////////////////////////////////////////////
// Filename: DiamondRenderer.cpp
// Renderer class that draws a diamond shape
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DiamondRenderer.h"
#include "Tile.h"
#include "RenderSystem.h"

DiamondRenderer::DiamondRenderer(float r, float g, float b)
{
	m_colour = Vector3(r, g, b);
	m_position = Vector2::Zero();
}

void DiamondRenderer::Render()
{
	Rect* rect = new Rect();
	rect->position = m_position;
	rect->width = Tile::TILE_LENGTH;
	rect->height = Tile::TILE_LENGTH;
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;
	RenderSystem::Instance().DrawDiamond(rect, r, g, b);
}