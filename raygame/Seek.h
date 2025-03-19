#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"

class Seek : public Behavior
{
public:
	Seek() {};
	virtual ~Seek() {};
	virtual void Update(PathAgent* agent, float deltaTime);
	inline virtual const char* GetBehaviorName() { return "Seek"; }
	void SetDestination(Vector2* destination) { m_destination = destination; }

private:
	Vector2* m_destination;

};