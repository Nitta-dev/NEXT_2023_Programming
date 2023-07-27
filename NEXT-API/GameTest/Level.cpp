///////////////////////////////////////////////////////////////////////////////
// Filename: Level.cpp
// Manages all level data
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Level.h"
#include "RenderSystem.h"
#include <stdlib.h>

Level::Level()
{

}

void Level::Init()
{
	GenerateGrid();
	for (size_t i = 0; i < GRID_WIDTH; i++)
	{
		for (size_t j = 0; j < GRID_HEIGHT; j++)
		{
			m_tiles[i][j].Init();
			m_tiles[i][j].SetPosition(LEFT_BUFFER + i * Tile::TILE_LENGTH, BOTTOM_BUFFER + j * Tile::TILE_LENGTH);
		}
	}
	RefreshAllTileID();
}

void Level::Update(float dt)
{
	for each (Tile tile in m_tiles)
	{
		tile.Update(dt);
	}
}

void Level::Render()
{
	// Draw level box
	Rect* rect = new Rect();
	float w = GRID_WIDTH * Tile::TILE_LENGTH;
	float h = GRID_HEIGHT * Tile::TILE_LENGTH;
	float x = (LEFT_BUFFER + w) / 2.0f;
	float y = (BOTTOM_BUFFER + h) / 2.0f;
	rect->Set(x, y, w, h);
	RenderSystem::Instance().DrawRect(rect);

	// Draw blocks
	for each (Tile tile in m_tiles)
	{
		tile.Render();
	}
}

void Level::Reset()
{
	m_leftCol = 0;
	GenerateGrid();
	RefreshAllTileID();
}

Vector2 Level::GetPosition(int tileX, int tileY)
{
	float x = LEFT_BUFFER + tileX * Tile::TILE_LENGTH;
	float y = BOTTOM_BUFFER + tileY * Tile::TILE_LENGTH;

	return Vector2(x, y);
}

void Level::GenerateGrid()
{
	for (size_t i = 0; i < FULL_GRID_WIDTH; i++)
	{
		for (size_t j = 0; j < GRID_HEIGHT; j++)
		{
			if (i == 0 || i == FULL_GRID_WIDTH - 1 || j == 0 || j == GRID_HEIGHT - 1)
			{
				m_map[i][j] = static_cast<int>(Tile::BlockType::HARD);
			}
			else if (i % 2 == 0 && j % 2 == 0)
			{
				m_map[i][j] = static_cast<int>(Tile::BlockType::HARD);
			}
			else
			{
				m_map[i][j] = rand() % 100 <= PERCENT_BLOCK_CHANCE ? static_cast<int>(Tile::BlockType::SOFT) : static_cast<int>(Tile::BlockType::NONE);
			}
		}
	}

	// Ensure starting area is clear
	m_map[1][10] = static_cast<int>(Tile::BlockType::NONE);
	m_map[1][11] = static_cast<int>(Tile::BlockType::NONE);
	m_map[2][11] = static_cast<int>(Tile::BlockType::NONE);

	// Set stage exit door
	int x = 0;
	do
	{
		x = rand() % FULL_GRID_WIDTH;
	} while (x == 0 || x == FULL_GRID_WIDTH - 1 || x % 2 == 0);
	int y = 0;
	do
	{
		y = rand() % GRID_HEIGHT;
	} while (y == 0 || y == GRID_HEIGHT - 1 || y % 2 == 0);
	m_map[x][y] = static_cast<int>(Tile::BlockType::DOOR_CLOSE);
}

void Level::RefreshAllTileID()
{
	for (size_t i = 0; i < GRID_WIDTH; i++)
	{
		for (size_t j = 0; j < GRID_HEIGHT; j++)
		{
			Tile::BlockType id = static_cast<Tile::BlockType>(m_map[i + m_leftCol][j]);
			m_tiles[i][j].SetID(id);
			m_tiles[i][j].SetMapPos(i + m_leftCol, j);
			m_tiles[i][j].SetTilePos(i, j);
		}
	}
}

void Level::ShiftGridLeft()
{
	m_leftCol++;
	RefreshAllTileID();
}

void Level::ShiftGridRight()
{
	m_leftCol--;
	RefreshAllTileID();
}