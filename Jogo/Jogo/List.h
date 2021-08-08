#pragma once


template<typename TL>
class List
{
private:

	template<typename TE>
	class Element {
	private:
		TE pInfo;

		Element* pPrev;
		Element* pNext;

	public:

		Element(TE info = nullptr, Element* prev = nullptr, Element* next = nullptr);
		~Element();

		TE getInfo() const;
		Element* getPrev() const;
		Element* getNext() const;

		void setInfo(const TE info);
		void setPrev(Element* prev);
		void setNext(Element* next);
	};

	Element<TL>* begin;
	Element<TL>* end;
	Element<TL>* current;

public:

	List();
	~List();

	void insert(const TL info);
	void removeElement(const TL& info);
	void clear();

	TL getBegin();
	TL getNext();


};

template<typename TL>
template<typename TE>
List<TL>::Element<TE>::Element(TE info, Element<TE>* prev, Element<TE>* next) :
	pInfo(info), pPrev(prev), pNext(next)
{
}

template<typename TL>
template<typename TE>
List<TL>::Element<TE>::~Element()
{
}

template<typename TL>
template<typename TE>
TE List<TL>::Element<TE>::getInfo() const
{
	return pInfo;
}

template<typename TL>
template<typename TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getPrev() const
{
	return pPrev;
}

template<typename TL>
template<typename TE>
List<TL>::Element<TE>* List<TL>::Element<TE>::getNext() const
{
	return pNext;
}

template<typename TL>
template<typename TE>
void List<TL>::Element<TE>::setInfo(TE info)
{
	pInfo = info;
}

template<typename TL>
template<typename TE>
void List<TL>::Element<TE>::setPrev(Element<TE>* prev)
{
	pPrev = prev;
}

template<typename TL>
template<typename TE>
void List<TL>::Element<TE>::setNext(Element<TE>* next)
{
	pNext = next;
}

template<typename TL>
List<TL>::List() :
	begin(nullptr), end(nullptr), current(nullptr)
{
}

template<typename TL>
List<TL>::~List()
{
	clear();
}

template<typename TL>
void List<TL>::insert(TL info)
{
	if (info) {
		Element<TL>* paux = new Element<TL>(info);

		if (!begin) {
			begin = paux;
			end = paux;
		}

		else {
			end->setNext(paux);
			paux->setPrev(end);

			end = paux;
		}
	}

}

template<typename TL>
void List<TL>::clear()
{
	Element<TL>* paux = nullptr;
	current = begin;

	while (current != nullptr) {
		paux = current->getNext();

		delete current;

		current = paux;
	}

	begin = nullptr;
	end = nullptr;
	current = nullptr;
}

template<typename TL>
TL List<TL>::getBegin()
{
	current = begin;

	return (current) ? current->getInfo() : nullptr;
}

template<typename TL>
TL List<TL>::getNext()
{
	current = current->getNext();

	return (current) ? current->getInfo() : nullptr;
}

template<typename TL>
void List<TL>::removeElement(const TL& elemInfo)
{
	Element<TL>* paux = nullptr;

	if (begin != nullptr) {
		paux = begin;

		while (paux != nullptr && paux->getInfo() != elemInfo) {
			paux = paux->getNext();
		}

		if (paux != nullptr) {

			if (paux->getNext() != nullptr) paux->getNext()->setPrev(paux->getPrev());
			else end = paux->getPrev();

			if (paux->getPrev() != nullptr) paux->getPrev()->setNext(paux->getNext());
			else begin = paux->getNext();

			delete paux;
		}
	}
}
