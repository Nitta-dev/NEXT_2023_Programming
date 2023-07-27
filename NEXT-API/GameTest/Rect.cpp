///////////////////////////////////////////////////////////////////////////////
// Filename: Rect.cpp
// Simple struct to hold data for rectangular shapes
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Rect.h"

Rect::Rect()
{
	position = Vector2::Zero();
	width = 1;
	height = 1;
}

bool Rect::Contains(Vector2 point)
{
	double xMin = GetXMin();
	double xMax = GetXMax();
	double yMin = GetYMin();
	double yMax = GetYMax();

	return point.x > xMin && point.x < xMax&& point.y < yMin&& point.y < yMax;
}

bool Rect::Overlaps(Rect* other)
{
	if (position.x < other->position.x + other->width &&
		position.x + width > other->position.x &&
		position.y < other->position.y + other->height &&
		position.y + height > other->position.y)
	{
		// Overlap detected
		return true;
	}
	else
	{
		// No overlap
		return false;
	}
}

void Rect::Set(double x, double y, double width, double height)
{
	position = Vector2(x, y);
	this->width = width;
	this->height = height;
}