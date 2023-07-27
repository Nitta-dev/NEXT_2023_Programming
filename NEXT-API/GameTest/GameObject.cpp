///////////////////////////////////////////////////////////////////////////////
// Filename: GameObject.cpp
// Basic game object class
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	name = "Game Object";
	layer = 0;
	tag = "Default";
	components.push_back(new Transform());
}

void GameObject::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
}

void GameObject::SetRotation(float x, float y)
{
	Transform* transform = GetTransform();
	transform->rotation = Vector2(x, y);
	SetTransform(transform);
}

void GameObject::SetScale(float s)
{
	Transform* transform = GetTransform();
	transform->scale = Vector2(s, s);
	SetTransform(transform);
}