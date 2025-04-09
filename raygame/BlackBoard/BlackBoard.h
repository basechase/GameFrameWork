#pragma once
#include "Actors/Actor.h"

enum class BlackboardItemType
{

	type_vector,
	type_bool,
	

};


class Blackboard 
{
public:
	Blackboard() {}
	Blackboard(Actor* actor);
	~Blackboard();

	
	Actor* m_owner;
	bool isStarted();
	bool isOffScreen();

	
	
public:
	struct BlackBoardItem {
		BlackboardItemType type;
		

		union
		{
			MathLibrary::Vector2 blackboardVector;
			bool m_started;
			
		};
		BlackBoardItem() {}
	

	



	};





};
