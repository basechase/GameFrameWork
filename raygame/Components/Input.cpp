#include "Input.h"
#include "Actor.h"
#include "raylib.h"
#include "Transform2D.h"
#include <iostream>
Input::Input(Actor* owner, const char* name) : Component::Component(owner, name)
{
	
	m_speed = 0.03;
}

Input::~Input()
{
}

void Input::start()
{
	
}

void Input::update(float deltaTime)
{
	
	if (IsKeyDown(KEY_W))
	{
		//std::cout << "read" << std::endl;
		m_owner->getTransform()->Translate(m_owner->getTransform()->getForward() * m_speed);
		
	}

	if (IsKeyDown(KEY_S))
	{
		m_owner->getTransform()->Translate(m_owner->getTransform()->getForward() * -m_speed);

	}

	if (IsKeyDown(KEY_A))
	{
		m_owner->getTransform()->rotate(m_speed/180);

	}

	if (IsKeyDown(KEY_D))
	{
		m_owner->getTransform()->rotate(-m_speed/180);
	}
}

void Input::end()
{
}
