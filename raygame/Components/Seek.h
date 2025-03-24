#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"
#include "Component.h"
#include "Components/Component.h"
#include "Actor.h"
#include "raylib.h"
class Seek : public Component
{

public:
	Seek();
	Seek(Actor* owner, const char* name = "");
	~Seek();
	void UpdateBehavior(float deltaTime, Actor* actor, Actor* actor2);
	void setTarget(MathLibrary::Vector2 target) { m_targetPosition = target; }
	MathLibrary::Vector2 m_targetPosition;

	

};