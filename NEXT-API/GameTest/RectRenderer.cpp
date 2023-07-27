///////////////////////////////////////////////////////////////////////////////
// Filename: RectRenderer.cpp
// Renderer class that draws a circle rectangle
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "RectRenderer.h"
#include "RenderSystem.h"

RectRenderer::RectRenderer(Rect* rect, float r, float g, float b)
{
	m_rect = rect;
	m_colour = Vector3(r, g, b);
}

void RectRenderer::Render()
{
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;
	RenderSystem::Instance().DrawRect(m_rect, r, g, b);
}