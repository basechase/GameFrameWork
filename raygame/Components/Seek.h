#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"
#include "Component.h"
#include "Components/Component.h"
#include "Actors/Actor.h"
#include "raylib.h"
class Seek : public Component
{

public:
	
	//Seek(Actor* owner);
	Seek(Actor* owner, const char* name = "");
	~Seek();
	void update(float deltaTime);
	void setTarget(MathLibrary::Vector2 target) { m_targetPosition = target; }


	MathLibrary::Vector2 m_targetPosition;

	

};