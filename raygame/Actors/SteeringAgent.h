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
	void start();
	void update(float deltaTime);   
	void end();
	void setTarget(Actor* actor);
	void changeState(States states);
public: 
	Seek* m_seekComponent;
	SteeringAgent* agent;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;

};