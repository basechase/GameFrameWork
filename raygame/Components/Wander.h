#pragma once
#include "Pathfinding/Behavior.h"
#include "Transform2D.h"
#include "Component.h"
#include "Components/Component.h"
#include "Actors/Actor.h"
#include "raylib.h"
#include "Actors/SteeringAgent.h"

class Wander
{
public:
	Wander();

	Wander(Actor* owner);
	~Wander();

	void updateBehavior(float deltaTime);
	MathLibrary::Vector2 getSteeringForce(MathLibrary::Vector2 targetDirection);
	MathLibrary::Vector2 setAngle(MathLibrary::Vector2 vector, float value);



	void setTarget(MathLibrary::Vector2 target);

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_agentPosition;
	MathLibrary::Vector2 m_force;

	float m_speed = 0.05;

	Actor* m_owner;
	float m_circleDistance = 60;
	float m_circleRadius = 50;
	float m_wanderAngle = 100;

	const float m_angleChange = 50;



};