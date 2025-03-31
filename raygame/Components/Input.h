#pragma once
#include "Components/Component.h"
#include "Actors/Actor.h"
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