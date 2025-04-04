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



