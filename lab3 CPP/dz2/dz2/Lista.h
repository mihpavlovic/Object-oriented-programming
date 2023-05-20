#ifndef _Lista_h_
#define _Lista_h_
#include<iostream>
#include"ListaIndexGreska.h"
using namespace std;
template<typename T>
class Lista
{
	struct Node
	{
		T* elem;
		Node* next;
		Node(T* e, Node* n=nullptr): elem(e),next(n){}
	};

	Node* head = nullptr;
	int size;
	void kopiraj(const Lista& l)
	{
		for (Node* curr = l.head; curr != nullptr; curr = curr->next)
			*this += curr->elem;
	}
	void premesti(Lista& l)
	{
		this->head = l.head;
		this->size = size;
		l.head = nullptr;
	}
	void brisi()
	{
		Node* curr = head;
		Node* tmp = head;
		while (curr != nullptr)
		{
			tmp = curr;
			curr = curr->next;
			tmp->elem = nullptr;
			delete tmp;
		}
	}
public:
	//konstruktori i operatori dodele
	Lista() { size = 0; }
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l)
	{
		if (this != &l)
		{
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l)
	{
		if (this != &l)
		{
			brisi();
			premesti(l);
		}
		return *this;
	}
	~Lista()
	{
		brisi();
	}
	//metode
	int getSize()const { return size; }
	bool find(T& f)
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			if (*(curr->elem) == f) return true;
			curr = curr->next;
		}
		return false;
	}

	//preklopljeni operatori
	Lista& operator+=(T* add)
	{
		Node* tmp = new Node(add);
		Node* curr = head; 
		Node* prev = nullptr;
		size++;
		if (this->head == nullptr)
		{
			head = tmp;
			return *this;
		}
		while (curr->next != nullptr)
			curr = curr->next;
		curr->next = tmp;
		return *this;
	}
	T* operator[] (int i)
	{
		int num = 0, n=getSize();
		Node* curr = head;
		for (int j = 0; j < i; j++)
		{
			if (curr == nullptr) throw ListaIndexGreska();//fali konstruktor za gresku
			curr = curr->next;
		}
		if (curr == nullptr) throw ListaIndexGreska();
		return curr->elem;
	}
	const T* operator[] (int i) const
	{
		int num = 0, n = getSize();
		Node* curr = head;
		for (int j = 0; j < i; j++)
		{
			if (curr == nullptr) throw ListaIndexGreska();//fali konstruktor za gresku
			curr = curr->next;
		}
		if (curr == nullptr) throw ListaIndexGreska();
		return curr->elem;
	}
	
};
#endif


