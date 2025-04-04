#pragma once
#include "Actors/Actor.h"

enum class BlackboardItemType 
{

	type_vector,
	type_float,
	

};


class Blackboard 
{
public:
	Blackboard() {}
	Blackboard(Actor* owner);
	~Blackboard();
	
	Actor* m_owner;

	
	
private: 
	struct BlackBoardItem {
		BlackboardItemType type;
		

		union
		{
			MathLibrary::Vector2 blackboardVector;
			float distance;
			
		};
		BlackBoardItem() {}
	

	



	};





};
