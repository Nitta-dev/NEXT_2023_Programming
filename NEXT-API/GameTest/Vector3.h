#pragma once

/// <summary>
/// Representation of 3D vectors and points
/// </summary>
struct Vector3
{
	double x;
	double y;
	double z;

	Vector3();
	Vector3(double x, double y, double z);

	static Vector3 Back() { return Vector3(0, 0, -1); }
	static Vector3 Down() { return Vector3(0, -1, 0); }
	static Vector3 Forward() { return Vector3(0, 0, 1); }
	static Vector3 Left() { return Vector3(-1, 0, 0); }
	static Vector3 One() { return Vector3(1, 1, 1); }
	static Vector3 Right() { return Vector3(1, 0, 0); }
	static Vector3 Up() { return Vector3(0, 1, 0); }
	static Vector3 Zero() { return Vector3(0, 0, 0); }

	double Magnitude();

	Vector3 operator- (Vector3 v);
	bool operator!= (Vector3 v);
	Vector3 operator* (double n);
	Vector3 operator/ (double n);
	Vector3 operator+ (Vector3 v);
	bool operator== (Vector3 v);
};