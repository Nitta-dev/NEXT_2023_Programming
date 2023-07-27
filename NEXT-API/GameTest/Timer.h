//-----------------------------------------------------------------------------
// Timer.h
// Basic timer class
//-----------------------------------------------------------------------------
#pragma once
class Timer
{
public:
	Timer();
	Timer(float triggerTime);
	void Update(float dt);
	float GetTime() { return m_timer; }
	bool Trigger() { return m_timer <= 0.0f; }
	void ResetTimer() { m_timer = m_triggerTime; }

private:
	float m_timer;
	float m_triggerTime;
};

