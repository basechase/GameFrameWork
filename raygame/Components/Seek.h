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

	void SetDestination(Actor* owner) { m_target = owner->getTransform()->getLocalPosition(); }

private:
	MathLibrary::Vector2 m_target;

	

};