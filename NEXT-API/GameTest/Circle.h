//-----------------------------------------------------------------------------
// Circle.h
// Simple struct to hold data for circle shapes
//-----------------------------------------------------------------------------
#pragma once
#include "Vector2.h"

struct Circle
{
	Vector2 position;
	double radius;

	Circle();

	double Diameter();

	void SetPosition(float x, float y) { position.x = x; position.y = y; }

	bool Contains(Vector2 point);
	bool Overlaps(Circle* other);
	void Set(double x, double y, double radius);
};