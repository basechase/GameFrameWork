#pragma once
class Agent;

class Behavior 
{
	Behavior();
	virtual ~Behavior() = 0 {};
	virtual void Update(float deltatime, Agent& agent) = 0;
	virtual const char* GetBehaviorName() = 0;
	

	
};