//-----------------------------------------------------------------------------
// Transform.h
// Holds basic transform information
//-----------------------------------------------------------------------------
#pragma once
#include "Component.h"
#include "Vector2.h"

class Transform : public Component
{
public:
	Transform();
	Transform(double poxX, double posY, double rotX = 0, double rotY = 0, double scaleX = 1, double scaleY = 1);

	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
};