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
}
void SteeringAgent::Start()
{
	Actor::start();
	SpriteComponent* sprite = new SpriteComponent(this, "Images/enemy.png");
	// add seek component
	//m_seekComponent = new Seek();

	// Set the target position
	m_seekComponent->setTarget(m_owner->getTransform()->getLocalPosition());
}

void SteeringAgent::update(float deltaTime)
{
	Actor::update(deltaTime);
	std::cout << "steeringagent:working" << std::endl;
	
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
	{
		//wont need this now that there is a player
		std::cout << "mouse read" << std::endl;
		Vector2 temp = GetMousePosition();
		target_Position.x = temp.x;
		target_Position.y = temp.y;
	
	}

	currentState = seek;
	switch (currentState)
	{
	case SteeringAgent::seek:
		// get seek component 
		//call updatebehavior
		if (m_seekComponent)
		{
			//m_seekComponent->UpdateBehavior(deltaTime, this, this);
		}
		break;
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
