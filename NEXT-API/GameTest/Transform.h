#pragma once
#include "Component.h"
#include "Vector2.h"

/// <summary>
/// Position, rotation, and scale of an object
/// </summary>
class Transform : public Component
{
public:
	Transform();
	Transform(double poxX, double posY, double rotX = 0, double rotY = 0, double scaleX = 1, double scaleY = 1);

	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
};