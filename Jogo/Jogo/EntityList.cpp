#include "EntityList.h"
#include <iostream>


EntityList::EntityList() {
}

EntityList::~EntityList() {
    destroyEntities();
}


void EntityList::insert(Entity* info) {
    list.insert(info);
}


void EntityList::initEntities(GraphicsManager& gm)
{
    Entity* paux = list.getBegin();

    while (paux) {

        paux->init(gm);

        paux = list.getNext();

    }
}

void EntityList::updateEntities(GraphicsManager& gm) {

    Entity* paux = list.getBegin();


    while (paux) {

        paux->update(gm);

        paux = list.getNext();

    }

}

void EntityList::drawEntities(GraphicsManager& gm) {


    Entity* paux = list.getBegin();

    while (paux) {

        paux->draw(gm);

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