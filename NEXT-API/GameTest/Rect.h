#pragma once
#include "Vector2.h"

/// <summary>
/// Simple struct to hold data for rectangular shapes
/// </summary>
struct Rect
{
	Vector2 position;
	double height;
	double width;

	Rect();

	double GetXMin() { return position.x - width / 2; }
	double GetXMax() { return position.x + width / 2; }
	double GetYMin() { return position.y - height / 2; }
	double GetYMax() { return position.y + height / 2; }

	void SetPosition(float x, float y) { position.x = x; position.y = y; }

	bool Contains(Vector2 point);
	bool Overlaps(Rect* other);
	void Set(double x, double y, double width, double height);
};

