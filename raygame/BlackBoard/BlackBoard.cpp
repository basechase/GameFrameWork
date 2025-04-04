#include "BlackBoard.h"

Blackboard::Blackboard(Actor* owner)
{
	m_owner = owner;
	BlackBoardItem data;
	data.type = BlackboardItemType::type_vector;
	data.blackboardVector = m_owner->getPosition();
	

}

Blackboard::~Blackboard()
{
	
}

bool Blackboard::isOffScreen()
{
	BlackBoardItem data;
	data.type = BlackboardItemType::type_vector;
	if (data.blackboardVector.x < 0 or data.blackboardVector.y < 0) {
		return false;
		
	}
		return true;

	
}

char Blackboard::getName()
{
	BlackBoardItem data;
	data.type = BlackboardItemType::type_string;
	data.name = m_owner->getName();
	return *data.name;
}
