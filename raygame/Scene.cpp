#include "Scene.h"
#include "Transform2D.h"
#include "DynamicArray.h"
#include "Actor.h"

Scene::Scene()
{
    
    m_world = new MathLibrary::Matrix3();
}

MathLibrary::Matrix3* Scene::getWorld()
{
    return m_world;
}

void Scene::addUIElement(Actor* actor)
{
    m_UIElements.Add(actor);

    //Adds all children of the UI to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_UIElements.Add(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeUIElement(int index)
{
    m_UIElements.Remove(m_UIElements[index]);
    return true;
    
}

bool Scene::removeUIElement(Actor* actor)
{
    m_UIElements.Remove(actor);
    return true;
}

void Scene::addActor(Actor* actor)
{
    m_actors.Add(actor);

    //Adds all children of the actor to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        m_actors.Add(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeActor(Actor* index)
{
    m_actors.Remove(index);
    return true;
}

bool Scene::removeActor(Actor* actor)
{
    m_actors.Remove(actor);
    return true;
}

void Scene::start()
{
    m_started = true;
}

void Scene::update(float deltaTime)
{
    //Updates all actors
    for (int i = 0; i < m_actors.Length(); i++)
    {
        if (!m_actors.Contains(i)->getStarted())
            m_actors.getActor(i)->start();

        m_actors.getActor(i)->update(deltaTime);
    }

    //Checks collision for all actors
    for (int i = 0; i < m_actors.Length(); i++)
    {
        for (int j = 0; j < m_actors.Length(); j++)
        {
            if (m_actors.getActor(i)->checkForCollision(m_actors.getActor(j)) && j != i && m_actors.getActor(j)->getStarted())
                m_actors.getActor(i)->onCollision(m_actors.getActor(j));
        }
    }
}

void Scene::updateUI(float deltaTime)
{
    //Calls update for all actors in UI array
    for (int i = 0; i < m_UIElements.Length(); i++)
    {
        if (!m_UIElements.getActor(i)->getStarted())
            m_UIElements.getActor(i)->start();

        m_UIElements.getActor(i)->update(deltaTime);
    }
}

void Scene::draw()
{
    //Calls draw for all actors in the array
    for (int i = 0; i < m_actors.Length(); i++)
    {
        m_actors.Contains(i)->draw();
    }
}

void Scene::drawUI()
{
    //Calls draw for all actors in UI array
    for (int i = 0; i < m_UIElements.Length(); i++)
    {
        m_UIElements.Contains(i)->draw();
    }
}

void Scene::end()
{
    //Calls end for all actors in the array
    for (int i = 0; i < m_actors.Length(); i++)
    {
        if (m_actors.Contains(i)->getStarted())
            m_actors.Contains(i)->end();
    }

    m_started = false;
}