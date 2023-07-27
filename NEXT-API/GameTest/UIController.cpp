///////////////////////////////////////////////////////////////////////////////
// Filename: UIController.cpp
// Controls UI states
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "UIController.h"
#include "App/app.h"
#include "GameManager.h"
#include <string>

void UIController::Render()
{
	if (m_state.top().GetStateID() == State::StateID::TITLE)
	{

	}
	if (m_state.top().GetStateID() == State::StateID::STAGE)
	{
		std::string text = "STAGE " + std::to_string(GameManager::Instance().GetStage());
		App::Print(400, 400, text.c_str());
	}
	if (m_state.top().GetStateID() == State::StateID::GAME)
	{
		std::string textA = "TIME " + std::to_string(static_cast<int>(ceil(GameManager::Instance().GetGameTime())));
		std::string textB = std::to_string(GameManager::Instance().GetScore());
		std::string textC = "LEFT " + std::to_string(GameManager::Instance().GetLives());
		App::Print(30, 730, textA.c_str());
		App::Print(600, 730, textB.c_str());
		App::Print(800, 730, textC.c_str());
	}
	if (m_state.top().GetStateID() == State::StateID::WIN)
	{

	}
	if (m_state.top().GetStateID() == State::StateID::LOSE)
	{
		App::Print(400, 400, "GAME OVER");
	}
}