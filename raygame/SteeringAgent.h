#pragma once
#include "Actor.h"
#include "Transform2D.h"
#include "Components/Seek.h"

class SteeringAgent : public Actor
{

public:
	

	enum States 
	{
		wander,
		seek,
		arrive,
		persue,
		flee,
		evade

	};
	SteeringAgent(float x, float y, const char* name);
	void Start();
	void Update(float deltaTime);
	void end();

	void changeState(States states);
public:
	Seek* m_seekComponent;
	SteeringAgent* agent;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;

};