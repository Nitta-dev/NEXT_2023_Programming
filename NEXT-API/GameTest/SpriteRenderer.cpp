///////////////////////////////////////////////////////////////////////////////
// Filename: SpriteRenderer.cpp
// Renderer class holding CSimpleSprite and related data
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SpriteRenderer.h"
#include "App/app.h"

SpriteRenderer::SpriteRenderer()
{
	m_fileName = ".\\TestData\\Test.bmp";
	m_columns = 8;
	m_rows = 4;
	m_animated = true;
	m_frame = -1;
}

SpriteRenderer::SpriteRenderer(std::string fileName, int columns, int rows, bool animated, int frame)
{
	m_fileName = fileName;
	m_columns = columns;
	m_rows = rows;
	m_animated = animated;
	m_frame = frame;
}

void SpriteRenderer::Init()
{
	m_sprite = App::CreateSprite(m_fileName.c_str(), m_columns, m_rows);

	if (m_animated)
	{
		for (size_t i = 0; i < m_rows; i++)
		{
			std::vector<int> frames;
			for (size_t j = 0; j < m_columns; j++)
			{
				frames.push_back(i * m_columns + j);
			}
			m_sprite->CreateAnimation(i, m_speed, frames);
		}
	}
	else
	{
		m_sprite->SetFrame(m_frame);
	}
}

void SpriteRenderer::Update(float dt)
{
	m_sprite->Update(dt);
}

void SpriteRenderer::Render()
{
	m_sprite->Draw();
}

void SpriteRenderer::Destroy()
{
	delete m_sprite;
}