#pragma once
#include "Scene.h"
#include "Actors/SteeringAgent.h"
#include "Transform2D.h"
#include "Components/Seek.h"
#include "BlackBoard/BlackBoard.h"
class SteeringScene : public Scene
{
public:
    friend Seek;
    void start() override;

    void update(float deltaTime) override;
    void end();


    MathLibrary::Vector2 playerPosition(Actor* actor);
    Blackboard* playerBlackboard;
    Blackboard* agentBlackboard;
  Actor* player_actor;
  SteeringAgent* other_agent;
   // Actor* enemy_actor;
   SteeringAgent* agent;
    
};