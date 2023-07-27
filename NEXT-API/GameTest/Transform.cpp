///////////////////////////////////////////////////////////////////////////////
// Filename: Transform.cpp
// Holds basic transform information
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position = Vector2::Zero();
	rotation = Vector2::Zero();
	scale = Vector2::One();
}

Transform::Transform(double posX, double posY, double rotX, double rotY, double scaleX, double scaleY)
{
	position = Vector2(posX, posY);
	rotation = Vector2(rotX, rotY);
	scale = Vector2(scaleX, scaleY);
}