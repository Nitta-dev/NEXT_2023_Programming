//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "GameManager.h"
#include "GameObjectManager.h"
#include "Level.h"

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	GameManager::Instance().Init();
	GameObjectManager::Instance().Init();
	Level::Instance().Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	GameManager::Instance().Update(deltaTime);
	GameObjectManager::Instance().Update(deltaTime);

	if (GameManager::Instance().GetUIController().GetStateID() == State::StateID::GAME)
	{
		Level::Instance().Update(deltaTime);

		if (Level::Instance().GetLeftCol() < Level::FULL_GRID_WIDTH - 16 && GameObjectManager::Instance().GetPlayer()->GetTileX() > 8)
		{
			Level::Instance().ShiftGridLeft();
			GameObjectManager::Instance().GetPlayer()->MoveLeft();
			GameObjectManager::Instance().ShiftGameObjectsLeft();
		}
		if (Level::Instance().GetLeftCol() > 0 && GameObjectManager::Instance().GetPlayer()->GetTileX() < 8)
		{
			Level::Instance().ShiftGridRight();
			GameObjectManager::Instance().GetPlayer()->MoveRight();
			GameObjectManager::Instance().ShiftGameObjectsRight();
		}
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	GameManager::Instance().Render();
	GameObjectManager::Instance().Render();

	if (GameManager::Instance().GetUIController().GetStateID() == State::StateID::GAME)
	{
		Level::Instance().Render();
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	

}