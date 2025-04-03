#include "Flee.h"
#include <iostream>
Flee::Flee()
{
}

Flee::Flee(Actor* owner)
{
	m_owner = owner;
}

Flee::~Flee()
{
}

void Flee::updateBehavior(float deltaTime)
{//this behavior goes at max speed always
	MathLibrary::Vector2 displacement = m_agentPosition - m_target;

	MathLibrary::Vector2 direction = displacement.getNormalized();

	MathLibrary::Vector2 steeredDirection = direction + getSteeringForce(direction);

	MathLibrary::Vector2 seekVelocity = steeredDirection * m_speed * deltaTime;

	//apply to the agent
	m_owner->moveActor(seekVelocity);
	m_owner->getTransform()->setForward(seekVelocity);
	std::cout << "working" << std::endl;
}

void Flee::setTarget(MathLibrary::Vector2 target)
{
	m_target = target;
}

MathLibrary::Vector2 Flee::getSteeringForce(MathLibrary::Vector2 targetDirection)
{
	MathLibrary::Vector2 result = targetDirection.normalize() - m_owner->getTransform()->getForward().normalize();
	return result;
}
