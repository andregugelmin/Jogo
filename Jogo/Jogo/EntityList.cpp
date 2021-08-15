#include "EntityList.h"
#include <iostream>
#include "Collider.h"

EntityList::EntityList() {
}

EntityList::~EntityList() {
    destroyEntities();
}


void EntityList::insert(Entity* info) {
    list.insert(info);
}

void EntityList::removeEntity(Entity* info)
{
    list.removeElement(info);
}


void EntityList::initEntities(LevelManager* lvl, CollisionManager& cm)
{
    Entity* paux = list.getBegin();

    while (paux) {

        paux->init(lvl, cm);

        paux = list.getNext();

    }
}

void EntityList::updateEntities(CollisionManager& cm) {
    
    Entity* paux = list.getBegin();
    while (paux) {
        paux->update();
        cm.checkCollisions();
        paux->updatePhysics();
        paux = list.getNext();

    }

}

void EntityList::drawEntities() {


    Entity* paux = list.getBegin();

    while (paux) {

        paux->draw();

        paux = list.getNext();

    }

}

void EntityList::destroyEntities() {

    Entity* paux = list.getBegin();

    while (paux) {

        delete paux;

        paux = list.getNext();

    }

    list.clear();
}