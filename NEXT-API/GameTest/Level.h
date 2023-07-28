#pragma once
#include "Behaviour.h"
#include "Renderer.h";
#include "Tile.h"
#include "Singleton.h"

/// <summary>
/// Manages all level data
/// </summary>
class Level : public Behaviour, public Renderer, public Singleton<Level>
{
public:
	static const int FULL_GRID_WIDTH = 31;
	static const int GRID_WIDTH = 16;
	static const int GRID_HEIGHT = 13;
	static const int LEFT_BUFFER = 50.0f;
	static const int BOTTOM_BUFFER = 50.0f;
	static const int PERCENT_BLOCK_CHANCE = 20;

	Level();
	void Init();
	void Update(float dt);
	void Render();
	void Reset();
	Vector2 GetPosition(int tileX, int tileY);
	int GetMapID(int x, int y) { return m_map[x][y]; }
	Tile GetTile(int x, int y) { return m_tiles[x][y]; }
	void GenerateGrid();
	void SetMapID(int x, int y, int id) { m_map[x][y] = id; }
	void SetTileID(int x, int y, Tile::BlockType type) { m_tiles[x][y].SetID(type); }
	void RefreshAllTileID();
	void ShiftGridLeft();
	void ShiftGridRight();
	int GetLeftCol() { return m_leftCol; }

private:
	int m_map[FULL_GRID_WIDTH][GRID_HEIGHT];
	Tile m_tiles[GRID_WIDTH][GRID_HEIGHT];
	int m_leftCol = 0;
};

