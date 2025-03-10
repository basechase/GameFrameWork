#include "Pathfinding.h"
namespace Pathfinding {
	
void Node::ConnectoTo(Node* other, float cost)
{
	connections.pushBack(Edge(other, cost));
}

List<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
{
	return List<Node*>();
}

void DrawPath(List<Node*>& path, Color lineColor)
{
	auto currentIter = path.begin();
	auto previousIter = currentIter;
	currentIter++;

	for (currentIter; currentIter != path.end(); currentIter++, previousIter++)
	{
		DrawLine(
			(*previousIter)->position.x, (*previousIter)->position.y, (*currentIter)->position.x, (*currentIter)->position.y
	}

}


void DrawNode(Node* node, bool selected)
{
	DrawCircle(node->position.x, node->position.y, 25 YELLOW);
}

void DrawGraph(Node* node, List<Node*>* drawnList)
{
}

}