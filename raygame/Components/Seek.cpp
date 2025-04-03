#include "Seek.h"
#include "Pathfinding/PathAgent.h"
#include "raylib.h"
#include "Actors/SteeringAgent.h"
#include "Transform2D.h"
#include <iostream>
#include "Actors/SteeringAgent.h"



Seek::Seek()
{
	
}



Seek::Seek(Actor* owner)
{
	m_owner = owner;
	
}

Seek::~Seek()
{

}

void Seek::updateBehavior(float deltaTime)
{
	//this behavior goes at max speed always
	float distance = (m_target - m_agentPosition).getMagnitude();
	
	MathLibrary::Vector2 displacement = m_target - m_agentPosition;

	MathLibrary::Vector2 direction = displacement.getNormalized();

	MathLibrary::Vector2 steeredDirection = direction + getSteeringForce(direction);

	MathLibrary::Vector2 seekVelocity = steeredDirection * m_speed * deltaTime;

	//apply to the agent
	m_owner->moveActor(seekVelocity);
	m_owner->getTransform()->setForward(seekVelocity);
	
	
}



void Seek::setTarget(MathLibrary::Vector2 target)
{

	m_target = target;

}

MathLibrary::Vector2 Seek::getSteeringForce(MathLibrary::Vector2 targetDirection)
{
	// targetDirection and ownerdirection have to be normalized
	MathLibrary::Vector2 result = targetDirection.normalize() - m_owner->getTransform()->getForward().normalize();
	

	//my forward
	//minus
	//desired forward
	
	return result;
}

