#pragma once
#include "Actors/Actor.h"
#include "Transform2D.h"
#include "Components/Seek.h"

class SteeringAgent : public Actor
{
	

	enum States 
	{
		wander,
		seek,
		arrive,
		persue,
		flee,
		evade

	};
public:

	SteeringAgent(float x, float y, const char* name);
	virtual void start();
	virtual void update(float deltaTime);   
	virtual void end();
	
	
	void setTarget(Actor* actor) { target = actor; }
	MathLibrary::Vector2 getTargetPosition() { return target->getTransform()->LocalPosition(); }

	void changeState(States states);



public:
	MathLibrary::Vector2 force = {0,0};


	Seek* m_seekComponent;
	SteeringAgent* agent;
	MathLibrary::Vector2 distance;
	Actor* target;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;

};