#include "stdafx.h"
#include "Circle.h"
#include <cmath>

Circle::Circle()
{
	position = Vector2::Zero();
	radius = 1;
}

double Circle::Diameter() { return radius * 2; }

bool Circle::Contains(Vector2 point)
{
	double dx = position.x - point.x;
	double dy = position.y - point.y;

	double distance = sqrt(dx * dx + dy * dy);

	return distance < radius;
}

bool Circle::Overlaps(Circle* other)
{
	double dx = position.x - other->position.x;
	double dy = position.y - other->position.y;

	double distance = sqrt(dx * dx + dy * dy);

	if (distance < radius + other->radius)
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

void Circle::Set(double x, double y, double radius)
{
	position = Vector2(x, y);
	this->radius = radius;
}