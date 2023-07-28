#pragma once

/// <summary>
/// Basic state class (for state machine)
/// </summary>
class State
{
public:
	enum class StateID
	{
		DEFAULT = -1,
		TITLE = 0,
		STAGE,
		GAME,
		WIN,
		LOSE
	};

	StateID GetStateID() { return m_stateID; }
	void SetStateID(StateID id) { m_stateID = id; }

	virtual void OnEnterState() {}
	virtual void StateUpdate(float dt) {}
	virtual void OnExitState() {}

private:
	StateID m_stateID;
};

