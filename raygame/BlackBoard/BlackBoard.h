#pragma once
#include "Actors/Actor.h"
class SteeringAgent;
enum class BlackboardItemType
{

	type_vector,
	type_string,
	

};


class Blackboard 
{
public:
	Blackboard() {}
	Blackboard(Actor* actor);
	~Blackboard();

	
	Actor* m_owner;
	bool isOffScreen();
	char getName();
	
	
public:
	struct BlackBoardItem {
		BlackboardItemType type;
		

		union
		{
			MathLibrary::Vector2 blackboardVector;
			const char* name;
			
		};
		BlackBoardItem() {}
	

	



	};





};
