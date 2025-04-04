#include "BlackBoard.h"

Blackboard::Blackboard()
{
}

Blackboard::~Blackboard()
{
}
	

bool Blackboard::setVector(MathLibrary::Vector2 vector)
{
	BlackBoardItem data;
	data.type = BlackboardItemType::type_vector;
	data.blackboardVector = vector;
	return true;
}

void Blackboard::setDistance(float distance)
{
	BlackBoardItem data;
	data.type = BlackboardItemType::type_float;
	data.distance = distance;
	
}

