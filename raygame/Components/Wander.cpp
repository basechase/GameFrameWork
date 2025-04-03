#include "Wander.h"
#include "Pathfinding/PathAgent.h"
#include "raylib.h"
#include "Actors/SteeringAgent.h"
#include "Transform2D.h"
#include <iostream>
#include "Actors/SteeringAgent.h"
#include <iostream>
Wander::Wander()
{
}

Wander::Wander(Actor* owner)
{
	m_owner = owner;
}

Wander::~Wander()
{
}

void Wander::updateBehavior(float deltaTime)
{
	
	
	MathLibrary::Vector2 circleCenter = m_agentPosition;
	MathLibrary::Vector2 displacement = { 0,1 };

	displacement = displacement.operator*(m_circleRadius);

	displacement = setAngle(displacement, m_wanderAngle);

	m_wanderAngle += (rand() % (int)m_angleChange) - m_angleChange * .5;



	MathLibrary::Vector2 wanderForce = m_agentPosition.operator+(displacement) * deltaTime * m_speed;
	
	
	m_owner->moveActor(wanderForce);
	m_owner->getTransform()->setForward(wanderForce);
	std::cout << "wandering" << std::endl;
}

MathLibrary::Vector2 Wander::getSteeringForce(MathLibrary::Vector2 targetDirection)
{
	MathLibrary::Vector2 result = targetDirection.normalize() - m_owner->getTransform()->getForward().normalize();


	//my forward
	//minus
	//desired forward

	return result;
}

MathLibrary::Vector2 Wander::setAngle(MathLibrary::Vector2 vector, float value)
{
	float length = vector.getMagnitude();
	return { cosf(value) * length, sinf(value) * length };
}

void Wander::setTarget(MathLibrary::Vector2 target)
{

	m_target = target;
}
