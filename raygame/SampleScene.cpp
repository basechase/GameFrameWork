#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Pathfinding/Pathfinding.h"

void SampleScene::start()
{
	//This is a better comment
	Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });

	addActor(test);
}

void SampleScene::update(float deltaTime)
{
	Pathfinding::Node a(100, 100);
	Pathfinding::Node b(600, 400);
	Pathfinding::Node c(600, 600);

	a.ConnectoTo(&b, 1);
	b.ConnectoTo(&c, 1);

	List<Pathfinding::Node*> path = { &a,&b,&c };

	Pathfinding::DrawPath(path, RED);
}
