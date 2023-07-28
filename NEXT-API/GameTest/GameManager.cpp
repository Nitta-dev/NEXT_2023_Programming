#include "stdafx.h"
#include "GameManager.h"
#include "StageUIState.h"
#include "GameUIState.h"
#include "GameObjectManager.h"
#include "LoseUIState.h"

GameManager::GameManager()
{
	ResetVariables();
	m_stageTimer = Timer(3.0f);
	m_gameTimer = Timer(200.0f);
	m_loseTimer = Timer(3.0f);
	m_highScore = DEFAULT_SCORE;
}

void GameManager::Init()
{
	m_uiController.ChangeState(StageUIState());
}

void GameManager::Update(float dt)
{
	if (m_uiController.GetStateID() == State::StateID::TITLE)
	{

	}
	if (m_uiController.GetStateID() == State::StateID::STAGE)
	{
		m_stageTimer.Update(dt);

		if (m_stageTimer.Trigger())
		{
			m_stageTimer.ResetTimer();
			m_uiController.Transition(GameUIState());
			ResetStage();
			GameObjectManager::Instance().GetPlayer()->Enable();
			GameObjectManager::Instance().GetPlayer()->MoveDown();
			m_gameOver = false;
		}

	}
	if (m_uiController.GetStateID() == State::StateID::GAME)
	{
		m_gameTimer.Update(dt);

		if (m_gameTimer.Trigger())
		{
			m_gameTimer.ResetTimer();
			GameOver();
		}
	}
	if (m_uiController.GetStateID() == State::StateID::WIN)
	{

	}
	if (m_uiController.GetStateID() == State::StateID::LOSE)
	{
		m_loseTimer.Update(dt);

		if (m_loseTimer.Trigger())
		{
			m_loseTimer.ResetTimer();
			m_uiController.Transition(StageUIState());
			ResetVariables();
		}
	}
}

void GameManager::Render()
{
	m_uiController.Render();
}

void GameManager::Cleanup()
{

}

void GameManager::ResetStage()
{
	Level::Instance().Reset();
	GameObjectManager::Instance().GetPlayer()->Reset();
	GameObjectManager::Instance().ClearGameObjects();
}

void GameManager::ResetVariables()
{
	m_stage = DEFAULT_STAGE;
	m_score = DEFAULT_SCORE;
	m_lives = DEFAULT_LIVES;
}

void GameManager::FireUp()
{
	GameObjectManager::Instance().GetPlayer()->AddBlastRadius();
	m_score += PANEL_POINTS;
}

void GameManager::BombUp()
{
	GameObjectManager::Instance().GetPlayer()->AddBombCapacity();
	m_score += PANEL_POINTS;
}

void GameManager::NextStage()
{
	if (m_gameOver)
	{
		return;
	}

	GameObjectManager::Instance().GetPlayer()->Disable();
	m_stage++;
	m_score += BONUS_POINTS * ceil(m_gameTimer.GetTime());
	m_lives++;
	m_gameOver = true;

	m_gameTimer.ResetTimer();
	m_uiController.Transition(StageUIState());
}

void GameManager::GameOver()
{
	if (m_gameOver)
	{
		return;
	}

	GameObjectManager::Instance().GetPlayer()->Disable();
	m_lives--;
	m_gameOver = true;

	m_gameTimer.ResetTimer();
	if (m_lives >= 0)
	{
		m_uiController.Transition(StageUIState());
	}
	else
	{
		m_uiController.Transition(LoseUIState());
	}
}