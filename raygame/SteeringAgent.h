#pragma once
#include "Actor.h"
#include "Transform2D.h"
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

	void Start();
	void Update();
	void end();

	void changeState(States states);
public:
	SteeringAgent* agent;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;

};