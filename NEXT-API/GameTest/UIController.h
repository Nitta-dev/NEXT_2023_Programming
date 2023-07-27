//-----------------------------------------------------------------------------
// UIController.h
// Controls UI states
//-----------------------------------------------------------------------------
#pragma once
#include "Renderer.h"
#include "StateMachine.h"

class UIController : public Renderer, public StateMachine
{
public:
	void Render();
};

