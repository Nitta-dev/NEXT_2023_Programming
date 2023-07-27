//-----------------------------------------------------------------------------
// PlayerController.h
// Holds all player data and related methods
//-----------------------------------------------------------------------------
#pragma once
#include "Controller.h"
#include "GameObject.h"
#include "RectRenderer.h"
#include "BoxCollider2D.h"
#include "Tile.h"

class PlayerController : public GameObject, public Controller
{
public:
	PlayerController();
	~PlayerController();

	RectRenderer* GetRenderer() { return dynamic_cast<RectRenderer*>(components.at(1)); }
	BoxCollider2D* GetCollider() { return dynamic_cast<BoxCollider2D*>(components.at(2)); }

	void Init();
	void Update(float dt);
	void Reset();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void PerformActionButton();
	void PerformCancelButton();

	void SetPosition(float x, float y);
	void SubNumBombs() { m_numBombs--; }
	void AddBombCapacity() { m_bombCapacity++; }
	void AddBlastRadius() { m_blastRadius++; }
	int GetBlastRadius() { return m_blastRadius; }

	bool GetPassability(Tile tile);
	void OnCollision();

private:
	int m_numBombs;
	int m_bombCapacity;
	int m_blastRadius;
};

