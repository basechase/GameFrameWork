#pragma once
#include "Component.h"
#include "Actor.h"
#include "raylib.h"
class Input : public Component 
{
public:
	Input(Actor* owner, const char* name = "");
	~Input();

	void start();
	void update(float deltaTime);
	void end();

	float m_speed;
 




};