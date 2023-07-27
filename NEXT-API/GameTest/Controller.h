//-----------------------------------------------------------------------------
// Controller.h
// Base controller class
//-----------------------------------------------------------------------------
#pragma once
#include "Behaviour.h"
#include "Timer.h"

class Controller
{
public:
	void CheckInput(float dt);

	virtual void MoveRight() {}
	virtual void MoveLeft() {}
	virtual void MoveUp() {}
	virtual void MoveDown() {}
	virtual void PerformActionButton() {}
	virtual void PerformCancelButton() {}

protected:
	float moveDelay = 0.15f;
	Timer delayTimer;
};

