#pragma once
#include "Scene.h"
#include "Actors/SteeringAgent.h"
#include "Transform2D.h"
#include "Components/Seek.h"
class SteeringScene : public Scene
{
public:
    friend Seek;
    void start() override;

    void update(float deltaTime) override;
    void end();


    MathLibrary::Vector2 playerPosition(Actor* actor);

   
    Actor* player_actor;
    MathLibrary::Vector2 player_pos;
    Actor* enemy_actor;
    
};