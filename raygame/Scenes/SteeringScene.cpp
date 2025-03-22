#include "SteeringScene.h"
#include "Components/SpriteComponent.h"
#include "Transform2D.h"
#include "Components/Input.h"
#include "SteeringAgent.h"
#include "Components/Seek.h"
#include <iostream>
void SteeringScene::start()
{

	Scene::start();
	player_actor = new Actor(100,50, "player");
	enemy_actor = new SteeringAgent(100,300, "enemy");
	

	player_actor->addComponent(new Input(player_actor));
	player_actor->addComponent(new SpriteComponent(player_actor, "Images/player.png"));
	player_actor->getTransform()->setScale({ 50,50 });
	
	
	
	
	Seek* seek = new Seek();
	enemy_actor->addComponent(new SpriteComponent(enemy_actor, "Images/enemy.png"));
	enemy_actor->addComponent(seek);
	enemy_actor->getTransform()->setScale({ 50,50 });
	
	addActor(enemy_actor);
	
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
