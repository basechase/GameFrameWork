#pragma once
#include "Actors/Actor.h"
#include "Transform2D.h"
#include "Components/Seek.h"

class SteeringAgent : public Actor
{
	friend class Seek;




	

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
	void setTarget(Actor* actor);
	void setTarget(MathLibrary::Vector2 vector);
	void changeState(States states);
	MathLibrary::Vector2 getTarget() { return target_Position; }
public: 

	Seek* m_seekComponent;
	SteeringAgent* agent;
	MathLibrary::Vector2 target_Position;
	MathLibrary::Vector2 agent_Position;
	States currentState;

};