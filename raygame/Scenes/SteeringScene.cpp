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
	
	SteeringAgent* agent = new SteeringAgent(400,500, "agent");
	
	Actor* player_actor = new Actor(100, 50, "player");
	//player_actor = new Actor(100,50, "player");
	
	
	agent->addComponent(new SpriteComponent(agent, "Images/enemy.png"));
	agent->getTransform()->setScale({ 50,50 });
	agent->addComponent(new Seek(agent, "agent"));

	player_actor->addComponent(new Input(player_actor, "player"));
	player_actor->addComponent(new SpriteComponent(player_actor, "Images/player.png"));
	player_actor->getTransform()->setScale({ 50,50 });
	
	
	
	
	
	
	

	

	addActor(agent);
	

	addActor(player_actor);

	
	
}

void SteeringScene::update(float deltaTime)
{
	
	
	
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
