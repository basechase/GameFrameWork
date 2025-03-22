#include "Seek.h"
#include "Pathfinding/PathAgent.h"
#include "raymath.h"
#include "SteeringAgent.h"
Seek::Seek()
{
	m_targetPosition = nullptr;
}
Seek::~Seek()
{

}

bool Seek::UpdateBehavior(float deltaTime, Actor* actor)
{
	// v = Vector2Subtract(*m_targetPosition, actor->getTransform()->getLocalPosition());

	//if (v.x == 0 && v.y == 0)
	//{
		// if seeker on top of target, v is 0 so following calculations are not needed
	//	return true;
	//}

	//Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), actor->GetMaxSpeed());
	//Vector2 steeringForce = Vector2Subtract(desiredVelocity, actor->GetVelocity());

	//actor->AddForce(steeringForce);

	return true;
}
