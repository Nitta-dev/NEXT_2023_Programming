#pragma once
#include "Renderer.h"
#include "StateMachine.h"

/// <summary>
/// Controls UI states
/// </summary>
class UIController : public Renderer, public StateMachine
{
public:
	void Render();
};

