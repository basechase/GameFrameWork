#include "SteeringScene.h"
#include "Components/SpriteComponent.h"
#include "Transform2D.h"
#include "Components/Input.h"
#include "Actors/SteeringAgent.h"
#include "Components/Seek.h"
#include <iostream>
void SteeringScene::start()
{
	
	
	Scene::start();
	agent = new SteeringAgent(200,500, "a");
	
	player_actor = new Actor(100, 50, "b");
	
	
	
	agent->getTransform()->setScale({ 50,50 });
	agentBlackboard = new Blackboard(agent);

	
	player_actor->addComponent(new Input(player_actor, "player"));
	player_actor->addComponent(new SpriteComponent(player_actor, "Images/player.png"));
	player_actor->getTransform()->setScale({ 50,50 });
	playerBlackboard = new Blackboard(player_actor);
	// LocalPosition().x
	
	
	other_agent = new SteeringAgent(30, 500, "c");
	other_agent->getTransform()->setScale({ 50,50 });
	

	

	addActor(agent);
	
	addActor(other_agent);
	addActor(player_actor);
	agent->setTarget(player_actor);
	other_agent->setTarget(player_actor);
	
	
	
}

void SteeringScene::update(float deltaTime)
{
	
	if (agentBlackboard->isOffScreen())
	{
		std::cout << "one is offscreen";
	}
	//std::cout << agent->getTransform()->LocalPosition().y << std::endl;
	Scene::update(deltaTime);

	


}

void SteeringScene::end()
{
	Scene::end();
}

MathLibrary::Vector2 SteeringScene::playerPosition(Actor* actor)
{

	return actor->getTransform()->getLocalPosition();
}
