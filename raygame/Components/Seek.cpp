#include "Seek.h"
#include "Pathfinding/PathAgent.h"

#include "SteeringAgent.h"
#include "Transform2D.h"
#include <iostream>

Seek::Seek()
{
}

Seek::Seek(Actor* owner, const char* name) : Component::Component(owner, name)
{

}
Seek::~Seek()
{

}

void Seek::UpdateBehavior(float deltaTime, Actor* actor, Actor* actor2)
{
	//subtract destination vector and actor vector to get distance
	// (*m_targetPosition, actor->getTransform()->getLocalPosition())
	
	MathLibrary::Vector2 distance;
	
	MathLibrary::Vector2 actorPosition = actor->getTransform()->getLocalPosition();
	MathLibrary::Vector2 targetPosition = actor2->getTransform()->getLocalPosition();

	distance = targetPosition - actorPosition;
	//scale distances normailzed vector by the actors max speed
	
	Vector2 raylib;
	
	

	raylib.x = actor->getTransform()->getLocalPosition().x;
	raylib.y = actor->getTransform()->getLocalPosition().y;

	DrawCircleV(raylib, 50, RED);
	//subtract the desired velovity by the agents current velocity to get it's steering force
	MathLibrary::Vector2 normalizedDistance = distance.getNormalized();

	MathLibrary::Vector2 desiredVelocity = normalizedDistance.operator*(actor->GetMaxSpeed());
	MathLibrary::Vector2 steeringForce = desiredVelocity - actor->GetVelocity();
	//std::cout << actor->GetVelocity().x << std::endl;
	//std::cout << steeringForce.x << std::endl;
	actor->AddForce(steeringForce);
	
	//return true;
}
