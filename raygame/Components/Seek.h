#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"
#include "Component.h"

class Seek : public Component
{

public:
	Seek();
	~Seek();
	bool UpdateBehavior(float deltaTime, Actor* actor);
	
	Vector2* m_targetPosition;



};