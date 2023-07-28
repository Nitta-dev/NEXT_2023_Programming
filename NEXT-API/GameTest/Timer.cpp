#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{

}

Timer::Timer(float triggerTime)
{
	m_triggerTime = triggerTime;
	m_timer = m_triggerTime;
}

void Timer::Update(float dt)
{
	m_timer -= dt / 1200.0f;
}