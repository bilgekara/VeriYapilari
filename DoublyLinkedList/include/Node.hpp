#ifndef NODE_HPP
#define NODE_HPP


#include <iostream>
using namespace std;

class Node{
	public:
		int data; // veri
		Node *next; // bir sonraki
		Node *prev; // bir onceki

		//veri sabit cunku veri yapisinin gorevi veriyi tasimak degistirmek degil
		Node(const int data,Node *next=NULL,Node *prev=NULL){ // eger girilmezse bos bir object olustursun, next de girilmezse ilerisiini null a esitleriz
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
};
#endif