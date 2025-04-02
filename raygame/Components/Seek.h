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
class Seek
{

public:
	
	Seek();

	Seek(Actor* owner);
	~Seek();
	void updateBehavior (float deltaTime);

	void setTarget(MathLibrary::Vector2 target);
	
	
	MathLibrary::Vector2 getSteeringForce(MathLibrary::Vector2 targetDirection);


	
public:
	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_agentPosition;
	MathLibrary::Vector2 m_force;

	float m_speed = 50;

	Actor* m_owner;
	

};