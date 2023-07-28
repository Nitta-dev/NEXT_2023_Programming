#pragma once
#include "Behaviour.h"
#include "Renderer.h"
#include "Singleton.h"
#include "Timer.h"
#include "UIController.h"
#include "Level.h"
#include "PlayerController.h"

/// <summary>
/// Holds main game data and methods
/// </summary>
class GameManager : public Behaviour, public Renderer, public Singleton<GameManager>
{
public:
	static const int MAX_STAGE = 5;
	static const int DEFAULT_STAGE = 1;
	static const int DEFAULT_SCORE = 0;
	static const int DEFAULT_LIVES = 2;
	static const int BONUS_POINTS = 50;
	static const int PANEL_POINTS = 1000;

	GameManager();
	void Init();
	void Update(float dt);
	void Render();
	void Cleanup();
	void ResetStage();
	void ResetVariables();
	void SetStage(int stage) { m_stage = stage; }
	void SetHighScore(int highScore) { m_highScore = highScore; }
	void AddPoints(int points) { m_score += points; }
	void SubPoints(int points) { m_score -= points; }
	void SetScore(int score) { m_score = score; }
	void AddLife() { m_lives++; }
	void SubLife() { m_lives--; }
	void SetLives(int lives) { m_lives = lives; }
	int GetStage() { return m_stage; }
	float GetStageTime() { return m_stageTimer.GetTime(); }
	float GetGameTime() { return m_gameTimer.GetTime(); }
	int GetHighScore() { return m_highScore; }
	int GetScore() { return m_score; }
	int GetLives() { return m_lives; }
	UIController GetUIController() { return m_uiController; }
	void FireUp();
	void BombUp();
	void NextStage();
	void GameOver();

private:
	int m_stage;
	Timer m_stageTimer;
	Timer m_gameTimer;
	Timer m_loseTimer;
	int m_highScore;
	int m_score;
	int m_lives;
	UIController m_uiController;
	bool m_gameOver;
};