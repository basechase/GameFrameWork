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


MathLibrary::Vector2 Blackboard::returnPosition()
{
	BlackBoardItem data;
	return data.blackboardVector;
}