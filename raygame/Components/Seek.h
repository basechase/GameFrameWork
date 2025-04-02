#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"
#include "Component.h"
#include "Components/Component.h"
#include "Actors/Actor.h"
#include "raylib.h"
#include "Scenes/SteeringScene.h"
#include "Actors/SteeringAgent.h"
class SteeringAgent;
class Seek : public Component
{

public:
	
	Seek();
	//Seek(Actor* owner);
	Seek(Actor* owner,  const char* name = "");
	~Seek();
	virtual void update (float deltaTime);

	void setTarget(MathLibrary::Vector2 target);
	
	//void SetDestinationActor(Actor* targetActor) { m_target = targetActor->getTransform()->getLocalPosition(); }
	void SetDestinationVector2(MathLibrary::Vector2 targetVector) { m_target = targetVector; }
	


	//Seek(SteeringAgent* owner);
public:
	MathLibrary::Vector2 m_target;
	
	

};