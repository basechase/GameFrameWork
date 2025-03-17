#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

class Behavior;


namespace pathfinding
{ 
	struct MovementInfo 
	{
		Vector2 m_position;
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_maxSpeed;
		float m_maxForce;

		float m_rotation;
		float m_rotationDampening;

	};
	class PathAgent
	{
	public:
		Vector2 position;

		std::vector<Node*> path;
		int currentIndex;
		Node* currentNode;

		float speed;

		void SetNode(Node* node);
		void Update(float deltaTime);
		void GoToNode(Node* node);

		void Draw();
	};
}
