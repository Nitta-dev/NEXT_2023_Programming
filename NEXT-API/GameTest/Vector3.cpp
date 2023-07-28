#include "stdafx.h"
#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector3::Magnitude()
{
	double x2 = pow(x, 2);
	double y2 = pow(y, 2);
	double z2 = pow(z, 2);

	return sqrt(x2 + y2 + z2);
}

Vector3 Vector3::operator- (Vector3 v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

bool Vector3::operator!= (Vector3 v)
{
	return x != v.x || y != v.y || z != v.z;
}

Vector3 Vector3::operator* (double n)
{
	return Vector3(x * n, y * n, z * n);
}

Vector3 Vector3::operator/ (double n)
{
	return Vector3(x / n, y / n, z / n);
}

Vector3 Vector3::operator+ (Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

bool Vector3::operator== (Vector3 v)
{
	return x == v.x && y == v.y && z == v.z;
}