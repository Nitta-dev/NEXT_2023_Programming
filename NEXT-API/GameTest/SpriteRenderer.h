#pragma once
#include "Renderer.h"
#include "App/SimpleSprite.h"
#include <string>

/// <summary>
/// Renders a CSimpleSprite for 2D graphics
/// </summary>
class SpriteRenderer : public Renderer
{
public:
	SpriteRenderer();
	SpriteRenderer(std::string fileName, int columns, int rows, bool animated = false, int frame = 0);
	void SetPosition(float x, float y) { m_sprite->SetPosition(x, y); }
	void SetAngle(float a) { m_sprite->SetAngle(a); }
	void SetScale(float s) { m_sprite->SetScale(s); }
	void SetAnimation(int id) { m_sprite->SetAnimation(id); }
	float GetWidth()  const { return m_sprite->GetWidth(); }
	float GetHeight() const { return m_sprite->GetHeight(); }

	void Init();
	void Update(float dt);
	void Render();
	void Destroy();

private:
	CSimpleSprite* m_sprite;
	std::string m_fileName;
	int m_columns;
	int m_rows;
	float m_speed = 1.0f / 15.0f;
	bool m_animated;
	int m_frame;
};

