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
	Seek();
	//Seek(Actor* owner);
	Seek(Actor* owner, const char* name = "");
	~Seek();
	void update(float deltaTime);

	
	void SetDestination(Actor* targetActor) { m_target = targetActor->getTransform()->getLocalPosition(); }
	void SetDestination(MathLibrary::Vector2 targetVector) { m_target = targetVector; }

private:
	MathLibrary::Vector2 m_target;

	

};