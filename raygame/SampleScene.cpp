#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Pathfinding/Pathfinding.h"

void SampleScene::start()
{
	Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });

	addActor(test);
}
/*
void SampleScene::update(float deltaTime)
{
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	m_nodeMap.Draw(true);
	pathfinding::DrawPath(m_pathAgent->path, lineColor);
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		pathfinding::Node* end = m_nodeMap.GetClosestNode(mousePos);
		m_pathAgent->GoToNode(end);
	}

	m_pathAgent->Update(deltaTime);
	m_pathAgent->Draw();

}

void SampleScene::end()
{
	delete m_pathAgent;
}

*/