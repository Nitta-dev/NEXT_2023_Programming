///////////////////////////////////////////////////////////////////////////////
// Filename: Vector2.cpp
// Simple 2-value struct to hold data such as position, rotation, etc.
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Vector2::Magnitude()
{
	double x2 = pow(x, 2);
	double y2 = pow(y, 2);

	return sqrt(x2 + y2);
}

Vector2 Vector2::operator- (Vector2 v)
{
	return Vector2(x - v.x, y - v.y);
}

bool Vector2::operator!= (Vector2 v)
{
	return x != v.x || y != v.y;
}

Vector2 Vector2::operator* (double n)
{
	return Vector2(x * n, y * n);
}

Vector2 Vector2::operator/ (double n)
{
	return Vector2(x / n, y / n);
}

Vector2 Vector2::operator+ (Vector2 v)
{
	return Vector2(x + v.x, y + v.y);
}

bool Vector2::operator== (Vector2 v)
{
	return x == v.x && y == v.y;
}