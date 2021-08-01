#pragma once

#include "Entity.h"


class GraphicsManager;

class EntitiesList
{
private:

    class ElementList {
    private:
        Entity* info;
        ElementList* prev;
        ElementList* next;

    public:
        ElementList(Entity* Info = nullptr, ElementList* Prev = nullptr, ElementList* Next = nullptr);
        ~ElementList();

        Entity* getInfo();
        void setInfo(Entity* Info);

        ElementList* getAnt();
        void setAnt(ElementList* Prev);

        ElementList* getProx();
        void setProx(ElementList* Next);
    };

    ElementList* begin;
    ElementList* end;
    ElementList* current;

public:

    EntitiesList();
    ~EntitiesList();

    void insert(Entity* info);
    void clear();
       

    Entity* getBegin(); 
    Entity* getNext(); 

    void initEntities(GraphicsManager& gm);
    void updateEntities();
    void drawEntities(GraphicsManager& gm);
    void destroyEntities();
};

