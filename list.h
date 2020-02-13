#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

class List{
	public:
		List();
		void push(Node*);
		void pop();
		Node* peek();
		void dissociate();
		
		void enqueue(Node*); //add node to the end of list
		void dequeue(); //remove node from front of list
		bool isEmpty();
		bool isFull();
		
		Node* getHead();//returns head
		Node* getTail();//returns tail
	private: //individual
		Node* head = NULL;
		Node* tail = NULL;
};

#endif