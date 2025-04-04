#pragma once
#include "Actors/Actor.h"
#include "Actors/SteeringAgent.h"
enum class BlackboardItemType 
{

	type_vector,
	type_state,
	type_bool,
	type_player_pointer,
	type_agent_pointer,

};


class Blackboard 
{
public:
	Blackboard();
	~Blackboard();
	MathLibrary::Vector2 returnPosition();
	bool setVector(MathLibrary::Vector2);
	

private: 
	struct BlackBoardItem {
		BlackboardItemType type;
		

		union
		{
			MathLibrary::Vector2 blackboardVector;
			float distance;
			bool unknown;
			void* playerPointer;
			void* agentPointer;
		};
		BlackBoardItem() {}
	

	



	};





};
