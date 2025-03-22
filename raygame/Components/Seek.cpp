#include "Seek.h"
#include "Pathfinding/PathAgent.h"

#include "SteeringAgent.h"
#include "Transform2D.h"
#include <iostream>

Seek::Seek()
{
	m_targetPosition = {500,500    };
}
Seek::~Seek()
{

}

bool Seek::UpdateBehavior(float deltaTime, Actor* actor)
{
	//subtract destination vector and actor vector to get distance
	// (*m_targetPosition, actor->getTransform()->getLocalPosition())
	MathLibrary::Vector2 distance = (m_targetPosition - actor->getTransform()->getLocalPosition());
	//scale distances normailzed vector by the actors max speed


	//subtract the desired velovity by the agents current velocity to get it's steering force


	MathLibrary::Vector2 desiredVelocity = distance.operator*(actor->GetMaxSpeed());
	MathLibrary::Vector2 steeringForce = desiredVelocity.operator-(actor->GetVelocity());

	actor->AddForce(steeringForce);
	
	return true;
}
