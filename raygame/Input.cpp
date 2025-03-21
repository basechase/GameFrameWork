#include "Input.h"
#include "Actor.h"
#include "raylib.h"
#include "Transform2D.h"
#include <iostream>
Input::Input(Actor* owner, const char* name) : Component::Component(owner, name)
{
	
	m_speed = 100;
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
		std::cout << "read" << std::endl;
		
		
	}

	if (IsKeyDown(KEY_S))
	{
		

	}

	if (IsKeyDown(KEY_A))
	{
		

	}

	if (IsKeyDown(KEY_D))
	{

	}
}

void Input::end()
{
}
