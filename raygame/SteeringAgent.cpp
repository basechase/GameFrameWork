#include "SteeringAgent.h"
#include "Components/SpriteComponent.h"
#include "Transform2D.h"
#include "raylib.h"
#include <iostream>
#include "Actor.h"

SteeringAgent::SteeringAgent(float x, float y, const char* name)
{
	m_transform = new Transform2D(this);
	m_transform->setLocalPosition({ x,y });
	m_name = name;
}
void SteeringAgent::Start()
{
	SpriteComponent* sprite = new SpriteComponent(this, "Images/enemy.png");
	// add seek component
}

void SteeringAgent::Update()
{
	
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
	{
		//change to player position?
		std::cout << "mouse read" << std::endl;
		Vector2 temp = GetMousePosition();
		target_Position.x = temp.x;
		target_Position.y = temp.y;
	
	}

	currentState = seek;
	switch (currentState)
	{
	case SteeringAgent::wander:
		break;
	case SteeringAgent::seek:
		// get seek component 
		//call updatebehavior

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
