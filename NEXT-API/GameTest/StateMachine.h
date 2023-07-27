//-----------------------------------------------------------------------------
// StateMachine.h
// Basic state machine class
//-----------------------------------------------------------------------------
#pragma once
#include "Behaviour.h"
#include "State.h"
#include <stack>

class StateMachine : public Behaviour
{
public:
	void Update(float dt);

	State::StateID GetStateID() { return m_state.top().GetStateID(); }

	virtual State GetState(State state);
	virtual void ChangeState(State state);
	virtual void Transition(State state);

protected:
	std::stack<State> m_state;
	State m_previousState;
	bool inTransition;
};

