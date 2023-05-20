#ifndef _Lista_h_
#define _Lista_h_
#include<iostream>
#include"TekElemGreska.h"
using namespace std;

template<typename T>
class Lista
{
	struct Node
	{
		T* elem;
		Node* next;
		Node(T* e, Node* n = nullptr) :elem(e), next(n) {}
	};
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* curr = nullptr;
	void kopiraj(const Lista& l)
	{
		/*
		Node* trenNovi = nullptr;
		Node* trenStari = l.head;
		if (l.head == nullptr) return;//lista koja se kopira je prazna
		Node* tmp = new Node(l.head->elem);
		head = tmp;
		if (l.head == l.tail)
		{
			tail = head;
			return;
		}
		while (trenStari != tail)
		{
			trenNovi = new Node(trenStari->elem);
			tmp->next = trenNovi;
			tmp = tmp->next;
			trenStari = trenStari->next;
		}
		trenNovi = new Node(trenStari->elem);
		tmp->next = trenNovi;
		tail = trenNovi;
		size = l.size;
		*/
		for (Node* tren = l.head; tren != nullptr; tren = tren->next)
		{
			dodaj(tren->elem);
		}
	}
	void premesti(Lista& l)
	{
		this->size = l.size;
		this->head = l.head;
		this->curr = l.curr;
		this->tail = l.tail;
		l.head = nullptr;
		l.curr = nullptr;
		l.size = 0;
		l.tail = nullptr;
	}
	void obrisi()
	{
		Node* tren = head;
		head = nullptr;
		Node* prev = nullptr;
		curr = nullptr;
		tail = nullptr;
		while (tren != nullptr)
		{
			prev = tren;
			prev->elem = nullptr;
			tren = tren->next;
			delete prev;

		}
	}
public:
	//konstruktori,operatori dodele i destruktor
	Lista() = default;
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l)
	{
		if (this != &l)
		{
			obrisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l)
	{
		if (this != &l)
		{
			obrisi();
			premesti(l);
		}
		return *this;
	}
	~Lista() { obrisi(); }

	//metode
	int getSize() const { return size; }
	void dodaj(T* t)//dodajem na kraj
	{
		Node* tmp = new Node(t);
		size++;
		if (head == nullptr)
		{
			head = tmp;
			tail = tmp;
			return;
		}
		if (head == tail)
		{
			tail = tmp;
			head->next = tmp;
			return;
		}
		tail->next = tmp;
		tail = tmp;
		tail->next = nullptr;
		return;

	}
	void naPrvi()
	{
		curr = head;
	}
	void naSled()
	{
		if (curr == nullptr) throw TekElemGreska();
		curr = curr->next;
	}
	bool postojiTekuci() const
	{
		if (curr == nullptr) return false;
		else return true;
	}
	void naPrvi() const
	{
		curr = head;
	}
	void naSled() const
	{
		if (curr == nullptr) throw TekElemGreska();
		curr = curr->next;
	}
	T* dohvPodTek()
	{
		if (curr == nullptr) throw TekElemGreska();
		return curr->elem;
	}
	void pisiCurr()
	{
		if (curr == nullptr)
			cout << "Nema curr" << endl;
		else cout << *(curr->elem) << endl;
	}

	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, Lista& l)
	{
		for (Node* x = l.head; x != nullptr; x = x->next)
		{
			it << *(x->elem) << endl;
		}
		return it;
	}
};
#endif

