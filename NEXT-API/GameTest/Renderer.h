#pragma once
#include "Component.h"

/// <summary>
/// Base class for all renderer classes
/// </summary>
class Renderer : public Component
{
public:
	virtual void Render() {}

	void Enable() { m_enabled = true; }
	void Disable() { m_enabled = false; }
	bool Enabled() { return m_enabled; }

protected:
	bool m_enabled = true;
};

