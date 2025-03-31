#pragma once
#include "Scene.h"
#include "Actors/SteeringAgent.h"

class SteeringScene : public Scene
{
    void start() override;

    void update(float deltaTime) override;
    void end();


    Actor* player_actor;
    SteeringAgent* enemy_actor;
};