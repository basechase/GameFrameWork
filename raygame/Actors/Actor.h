#pragma once
#include "Components/Component.h"
#include "Vector2.h"
#include "DynamicArray.h"
#include "Pathfinding/Behavior.h"
#include<vector>
class Collider;
class Transform2D;
class Actor
{
public:
    Actor();
    ~Actor();
    friend class Seek;
    friend class Wander;
    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    /// <summary>
    /// Iterates through all components in the component array to find one
    /// that matches the given name.
    /// </summary>
    /// <param name="componentName">The name of the component to search for.</param>
    /// <returns>A pointer to the component if a match was found.
    /// Returns nullptr if a match wasn't found.</returns>
    /// 
    
    template <typename T>
   T* getComponent();
    template <typename T>
    T* addComponent(T* component);
    float GetMaxSpeed() { return m_maxSpeed; }
    void SetMaxSpeed(float speed) { m_maxSpeed = speed; }



    MathLibrary::Vector2& getPosition() { return m_position; }
   
   void SetVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
   MathLibrary::Vector2 GetVelocity() { return m_velocity; }
   MathLibrary::Vector2 Truncate(MathLibrary::Vector2 v, float max);
   
   void AddBehaviour(Behavior* behavior);
    
    // bool removeComponent(const char* componentName);

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);
    void moveActor(MathLibrary::Vector2 movement);
public:
    float m_frictionModifier;
    MathLibrary::Vector2 m_position;
    DynamicArray<Behavior*> m_behaviorList;
    MathLibrary::Vector2 m_force = { 0,0 };
    MathLibrary::Vector2 m_velocity = {0,0};
    const char* m_name;
    float m_maxSpeed = 100;
   // Vector2 m_playerPosition;
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    DynamicArray<Component*> m_components;
    Actor* m_owner;
};
template<typename T>
inline T* Actor::getComponent()
{
    //Iterate through all of the components in the array.
    for (int i = 0; i < m_components.Length(); i++)
    {
        //If the component name matches the name given...
        if (dynamic_cast<T>(m_components[i]))
        {
            //...return the component.
            return m_components[i];
            
        }
    }

    //Return null by default.
    return nullptr;
}


template<typename T>
inline T* Actor::addComponent(T* component)
{
    //If this actor doesn't own this component...
    Actor* owner = component->getOwner();
    if (owner && owner != this)
    {
        //...return nullptr to prevent it from being added.
        return nullptr;
    }
    else 
    {


    m_components.Add(component);
    }

    //Return the new component that was added.
    return component;
}
