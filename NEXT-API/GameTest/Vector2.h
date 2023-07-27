//-----------------------------------------------------------------------------
// Vector2.h
// Simple 2-value struct to hold data such as position, rotation, etc.
//-----------------------------------------------------------------------------
#pragma once

struct Vector2
{
	double x;
	double y;

	Vector2();
	Vector2(double x, double y);

	static Vector2 Down() { return Vector2(0, -1); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 One() { return Vector2(1, 1); }
	static Vector2 Right() { return Vector2(1, 0); }
	static Vector2 Up() { return Vector2(0, 1); }
	static Vector2 Zero() { return Vector2(0, 0); }

	double Magnitude();

	Vector2 operator- (Vector2 v);
	bool operator!= (Vector2 v);
	Vector2 operator* (double n);
	Vector2 operator/ (double n);
	Vector2 operator+ (Vector2 v);
	bool operator== (Vector2 v);
};