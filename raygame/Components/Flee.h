#pragma once
#include "Components/Component.h"
#include "Actors/Actor.h"
#include "raylib.h"
#include "Transform2D.h"




class Flee 
{
public:

	Flee();

	Flee(Actor* owner);
	~Flee();
	void updateBehavior(float deltaTime);

	void setTarget(MathLibrary::Vector2 target);


	MathLibrary::Vector2 getSteeringForce(MathLibrary::Vector2 targetDirection);



public:
	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_agentPosition;
	MathLibrary::Vector2 m_force;

	float m_speed = 50;

	Actor* m_owner;



};