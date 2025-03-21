#include "SteeringScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Input.h"
#include "SteeringAgent.h"

void SteeringScene::start()
{

	Scene::start();
	player_actor = new Actor(50,50, "player");
	
	

	player_actor->addComponent(new Input(player_actor));
	player_actor->addComponent(new SpriteComponent(player_actor, "Images/player.png"));
	
	player_actor->getTransform()->setScale({ 50,50 });


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
