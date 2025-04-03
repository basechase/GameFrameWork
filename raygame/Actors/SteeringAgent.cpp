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
	
	m_wanderComponent = new Wander(this);
	m_fleeComponent = new Flee(this);
	m_seekComponent = new Seek(this);
	addComponent(new SpriteComponent(this, "Images/enemy.png"));
}
void SteeringAgent::start()
{
	

	
}

void SteeringAgent::update(float deltaTime)
{
	Actor::update(deltaTime);

	
	
	
	currentState = seek;
	switch (currentState)
	{
	case SteeringAgent::seek:
		// get seek component 
		//call updatebehavior
		if (m_seekComponent)
		{
			m_seekComponent->updateBehavior(deltaTime);
			m_seekComponent->setTarget(getTargetPosition());
			m_seekComponent->m_agentPosition = m_transform->LocalPosition();
			
		
		}
		break;
	case SteeringAgent::wander:
		if(m_wanderComponent)
		m_wanderComponent->updateBehavior(deltaTime);
		m_wanderComponent->setTarget(getTargetPosition());
		m_wanderComponent->m_agentPosition = m_transform->LocalPosition();
		break;
	case SteeringAgent::arrive:
		break;
	case SteeringAgent::persue:
		break;
	case SteeringAgent::flee:
		
		if (m_fleeComponent)
			m_fleeComponent->updateBehavior(deltaTime);
			m_fleeComponent->setTarget(getTargetPosition());
			m_fleeComponent->m_agentPosition = m_transform->LocalPosition();
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
	currentState = states;
}

