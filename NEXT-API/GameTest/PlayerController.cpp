///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerController.cpp
// Holds all player data and related methods
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PlayerController.h"
#include "GameObjectManager.h"
#include "CollisionSystem2D.h"
#include "App/app.h"
#include "Settings.h"
#include "Level.h"
#include "GameManager.h"
#include "RenderSystem.h"
#include "Bomb.h"

PlayerController::PlayerController()
{
	name = "Player";

	BoxCollider2D* collider = new BoxCollider2D(LAYERS::PLAYER, { LAYERS::ENEMY, LAYERS::EXPLOSION });
	float w = 0.8f * static_cast<float>(Tile::TILE_LENGTH);
	float h = 0.8f * static_cast<float>(Tile::TILE_LENGTH);
	collider->SetScale(w, h);

	components.push_back(new RectRenderer(collider, 0.0f, 0.0f, 1.0f));
	components.push_back(collider);

	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	m_numBombs = 0;
	m_bombCapacity = 1;
	m_blastRadius = 1;
}

PlayerController::~PlayerController()
{

}

void PlayerController::Init()
{
	Reset();
	delayTimer = Timer(moveDelay);
}

void PlayerController::Update(float dt)
{
	if (GameManager::Instance().GetUIController().GetStateID() != State::StateID::GAME)
	{
		return;
	}

	CheckInput(dt);

	std::vector<Collider2D*> colliders;
	GameObjectManager::Instance().GetComponents(colliders);
	if (CollisionSystem2D::Instance().CheckCollision(GetCollider(), colliders))
	{
		OnCollision();
	}
}

void PlayerController::Reset()
{
	float x, y;
	m_tileX = 1;
	m_tileY = Level::GRID_HEIGHT - 2;
	Level::Instance().GetTile(m_tileX, m_tileY).GetPosition(x, y);
	SetPosition(x, y);
}

void PlayerController::MoveRight()
{
	Tile tile = Level::Instance().GetTile(m_tileX + 1, m_tileY);
	if (!GetPassability(tile))
	{
		return;
	}

	m_tileX++;
	float x, y;
	tile.GetPosition(x, y);
	SetPosition(x, y);
	delayTimer.ResetTimer();
}

void PlayerController::MoveLeft()
{
	Tile tile = Level::Instance().GetTile(m_tileX - 1, m_tileY);
	if (!GetPassability(tile))
	{
		return;
	}

	m_tileX--;
	float x, y;
	tile.GetPosition(x, y);
	SetPosition(x, y);
	delayTimer.ResetTimer();
}

void PlayerController::MoveUp()
{
	Tile tile = Level::Instance().GetTile(m_tileX, m_tileY + 1);
	if (!GetPassability(tile))
	{
		return;
	}

	float x, y;
	m_tileY++;
	tile.GetPosition(x, y);
	SetPosition(x, y);
	delayTimer.ResetTimer();
}

void PlayerController::MoveDown()
{
	Tile tile = Level::Instance().GetTile(m_tileX, m_tileY - 1);
	if (!GetPassability(tile))
	{
		return;
	}

	float x, y;
	m_tileY--;
	tile.GetPosition(x, y);
	SetPosition(x, y);
	delayTimer.ResetTimer();
}

void PlayerController::PerformActionButton()
{
	if (m_numBombs >= m_bombCapacity)
	{
		return;
	}

	Transform* transform = GetTransform();
	float x = transform->position.x;
	float y = transform->position.y;

	Bomb* bomb = new Bomb();
	bomb->SetPosition(x, y);
	bomb->SetTilePos(m_tileX, m_tileY);
	GameObjectManager::Instance().AddGameObject(bomb);

	m_numBombs++;
}

void PlayerController::PerformCancelButton()
{

}

void PlayerController::SetPosition(float x, float y)
{
	Transform* transform = GetTransform();
	transform->position = Vector2(x, y);
	SetTransform(transform);
	GetCollider()->SetPosition(x, y);
}

bool PlayerController::GetPassability(Tile tile)
{
	if (tile.GetID() == Tile::BlockType::NONE)
	{
		return true;
	}

	if (tile.GetID() == Tile::BlockType::DOOR_OPEN)
	{
		return true;
	}

	return false;
}

void PlayerController::OnCollision()
{
	GameManager::Instance().GameOver();
}