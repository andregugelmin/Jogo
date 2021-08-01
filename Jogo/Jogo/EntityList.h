#pragma once

#include "SFML/Graphics.hpp"

template <typename TL>
class EntityList
{
private:
	
	template <typename TE>
	class ListElement {
	private:
		TE* pInfo;
		ListElement<TE>* pPrev;
		ListElement<TE>* pNext;

	public:
		ListElement(TE* info = NULL, ListElement<TE>* prev = NULL, ListElement<TE>* next = NULL);
		~ListElement();

		TE* getInfo() const;
		ListElement* getPrev() const;
		ListElement* getNext() const;

		void setInfo(TE* info);
		void setPrev(ListElement* prev);
		void setNext(ListElement* next);
	};

	EntityList();
	~EntityList();

	void insert(TL* info);
	void clear();
		

	TL* getFirst() const; 
	TL* getNext() const; 

	void updateElement(float t);
	void drawElement(sf::RenderWindow* window);
	void destroyElement();
};

template <typename TL>
template <typename TE>
EntityList<TL>::ListElement<TE>::ListElement(TE* info, ListElement<TE>* prev, ListElement<TE>* next) :
    pInfo{ info }, pPrev{ prev }, pNext{ next } {

}

template <typename TL>
template <typename TE>
EntityList<TL>::ListElement<TE>::~ListElement() {

}

template <typename TL>
template <typename TE>
TE* EntityList<TL>::ListElement<TE>::getInfo() const{
    return pInfo;
}


template<typename TL>
template<typename TE>
typename EntityList<TL>::template ListElement<TE>* EntityList<TL>::ListElement<TE>::getPrev() const
{
    return pPrev;
}

template<typename TL>
template<typename TE>
typename EntityList<TL>::template ListElement<TE>* EntityList<TL>::ListElement<TE>::getNext() const
{
	return pNext;
}

template<typename TL>
template<typename TE>
 void EntityList<TL>::ListElement<TE>::setInfo(TE* info)
{
	 pInfo = info;
}

