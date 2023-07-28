#include "stdafx.h"
#include "Controller.h"
#include "App/app.h"

void Controller::CheckInput(float dt)
{
	delayTimer.Update(dt);
	if (delayTimer.Trigger())
	{
		if (App::GetController().GetLeftThumbStickX() > 0.5f)
		{
			MoveRight();
		}
		if (App::GetController().GetLeftThumbStickX() < -0.5f)
		{
			MoveLeft();
		}
		if (App::GetController().GetLeftThumbStickY() < -0.5f)
		{
			MoveUp();
		}
		if (App::GetController().GetLeftThumbStickY() > 0.5f)
		{
			MoveDown();
		}
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		PerformActionButton();
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		PerformCancelButton();
	}
}