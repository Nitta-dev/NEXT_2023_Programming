///////////////////////////////////////////////////////////////////////////////
// Filename: StateMachine.cpp
// Basic state machine class
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "StateMachine.h"

void StateMachine::Update(float dt)
{
	if (m_state.size() <= 0)
	{
		return;
	}

	m_state.top().StateUpdate(dt);
}

State StateMachine::GetState(State state)
{
	State target;
	if (m_state.size() > 0)
	{
		target = m_state.top();
	}

	if (target.GetStateID() != state.GetStateID())
	{
		m_state.push(state);
		m_state.top().OnEnterState();
		target = state;
	}

	return target;
}

void StateMachine::ChangeState(State state)
{
	GetState(state);
}

void StateMachine::Transition(State state)
{
	if (m_state.top().GetStateID() == state.GetStateID() || inTransition)
	{
		// Transition failed
		return;
	}

	inTransition = true;

	if (m_state.size() > 0)
	{
		m_previousState = m_state.top();
		m_state.pop();
		m_previousState.OnExitState();
	}

	m_state.push(state);

	if (m_state.size() > 0)
	{
		m_state.top().OnEnterState();
	}

	inTransition = false;
}