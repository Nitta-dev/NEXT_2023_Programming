//-----------------------------------------------------------------------------
// Tile.h
// Holds tile data
//-----------------------------------------------------------------------------
#pragma once
#include "GameObject.h"
#include "BoxCollider2D.h"
#include "ShapeRenderer.h"

class Tile : public GameObject, public ShapeRenderer
{
public:
	static const int TILE_LENGTH = 50.0f;
	static const int PERCENT_PANEL_CHANCE = 2;

	enum class BlockType
	{
		DOOR_OPEN = -2,
		DOOR_CLOSE = -1,
		NONE = 0,
		HARD,
		SOFT,
		REGEN,
		FLICKER,
		PRESSURE
	};

	Tile();
	~Tile();

	BoxCollider2D* GetCollider() { return dynamic_cast<BoxCollider2D*>(components.at(1)); }

	void Init();
	void Update(float dt);
	void Render();
	void SetPosition(float x, float y);
	void SetID(BlockType id) { m_id = id; }
	void SetMapPos(int x, int y) { m_mapX = x; m_mapY = y; }
	void SetDoor(bool value = true) { m_door = value; }
	void GetPosition(float& x, float& y) { x = GetTransform()->position.x; y = GetTransform()->position.y; }
	BlockType GetID() { return m_id; }
	void GetMapPos(int& x, int& y) { x = m_mapX; y = m_mapY; }
	bool GetDoor() { return m_door; }
	void OnCollision();

private:
	BlockType m_id;
	int m_mapX;
	int m_mapY;
	bool m_door;
};

