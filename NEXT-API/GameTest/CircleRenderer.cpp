#include "stdafx.h"
#include "CircleRenderer.h"
#include "RenderSystem.h"

CircleRenderer::CircleRenderer(Circle* circle, float r, float g, float b)
{
	m_circle = circle;
	m_colour = Vector3(r, g, b);
}

void CircleRenderer::Render()
{
	float r = m_colour.x;
	float g = m_colour.y;
	float b = m_colour.z;
	RenderSystem::Instance().DrawCircle(m_circle, r, g, b);
}