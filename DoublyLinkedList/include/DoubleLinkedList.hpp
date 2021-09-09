#ifndef DOUBLE_LINKEDLIST_HPP
#define DOUBLE_LINKEDLIST_HPP

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


#include "Node.hpp"

class DoubleLinkedList{
	private: 
		Node *head; // dugum turunden bir pointer
		int size; //eleman sayisi
		
		Node* FindPrevByPosition(int);
		
		
	public:
		DoubleLinkedList();
		bool isEmpty()const;
		int Count()const;
		void add(const int);
		
		Node* FindByHead();
		void insert(int,const int);
		
		void removeAt(int);
		const int karsilastir(int)const;

		void inverse();
		
		void guncelleme(Node*);
		void yerDegistir(Node*, Node*, int);
		
		friend ostream& operator<<(ostream&, DoubleLinkedList&);
		
		void clear();
		
		~DoubleLinkedList();
};
#endif