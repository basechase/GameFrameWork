#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"

class Seek : public Behavior
{
public:
	Seek();
	virtual ~Seek();
	virtual void Update(float deltaTime, PathAgent& agent);
	inline virtual const char* GetBehaviorName() { return "Seek"; }

	Vector2* m_targetPosition;
	
};