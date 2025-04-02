#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider/Collider.h"
#include "Components/Component.h"
#include <iostream>
Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

MathLibrary::Vector2 Actor::Truncate(MathLibrary::Vector2 v, float max)
{
    float i = max / sqrtf((v.x * v.x) + (v.y * v.y));
    i = i < 1.0 ? i : 1.0;
    return v.operator*(i);
}
void Actor::AddBehaviour(Behavior* behavior)
{
    m_behaviorList.Add(behavior);
}
void Actor::start()
{
    m_started = true;

    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->start();
    }
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->onCollision(other);
    }
}

void Actor::update(float deltaTime)
{
    m_transform->updateTransforms();
      
    //need to calculate velocity
   // velocity = change in distance/ change in time

    
    m_velocity = Truncate(m_velocity.operator+(m_force.operator*(deltaTime)), m_maxSpeed);
    m_position = m_position.operator+(m_velocity.operator*(deltaTime));
    
  //  m_velocity = m_velocity.operator*(m_frictionModifier);
 //  std::cout << m_velocity.x << std::endl;

    


    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->draw();
    }
}

void Actor::end()
{
    m_started = false;
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->end();
    }
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());

    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->onDestroy();
    }
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}