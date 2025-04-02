#include "SteeringAgent.h"
#include "Components/SpriteComponent.h"
#include "Transform2D.h"
#include "raylib.h"
#include <iostream>
#include "Actors/Actor.h"



SteeringAgent::SteeringAgent(float x, float y, const char* name)
{
	
	m_transform = new Transform2D(this);
	m_transform->setLocalPosition({ x,y });
	m_name = name;
	m_seekComponent = new Seek();

	addComponent(new SpriteComponent(this, "Images/enemy.png"));
}
void SteeringAgent::start()
{
	

	
}

void SteeringAgent::update(float deltaTime)
{
	Actor::update(deltaTime);

	
	std::cout << m_transform->LocalPosition().x << std::endl;

	
	currentState = seek;
	switch (currentState)
	{
	case SteeringAgent::seek:
		// get seek component 
		//call updatebehavior
		if (m_seekComponent)
		{
			m_seekComponent->update(deltaTime);
			m_seekComponent->setTarget(getTargetPosition());
			
		}
		break;

	case SteeringAgent::wander:
		break;
	case SteeringAgent::arrive:
		break;
	case SteeringAgent::persue:
		break;
	case SteeringAgent::flee:
		break;
	case SteeringAgent::evade:
		break;
	default:
		break;
	}



}

void SteeringAgent::end()
{
}

void SteeringAgent::changeState(States states)
{
}

