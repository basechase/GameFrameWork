#pragma once
#include "Actors/Actor.h"
#include "Transform2D.h"
#include "Components/Seek.h"
#include "Components/Flee.h"
#include "Components/Wander.h"
#include "BlackBoard/BlackBoard.h"

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
	float getMaxSpeed() { return m_maxSpeed; }
	Blackboard& GetBlackboard() { return m_blackboard; }
	

public:
	Blackboard m_blackboard;
	MathLibrary::Vector2 force = {0,0};
	float m_maxSpeed = 100;
	Wander* m_wanderComponent;
	Flee* m_fleeComponent;
	Seek* m_seekComponent;
	SteeringAgent* agent;
	Blackboard* blackboard;
	Actor* target;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;
	

};