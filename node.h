#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
	public:
		Node(char*);
		//~Node();
		char* getData();
		void setRight(Node*);
		void setLeft(Node*);
		void setNext(Node*);
		Node* getRight();
		Node* getLeft();
		Node* getNext();
		bool checkLeft();
		bool checkRight();
	private:
		Node* next = NULL; //the next node in linked list
		char* data; //data parameter that each node holds
		Node* left = NULL; //parameter for the node left of node
		Node* right = NULL; //parameter for the node right of node
};

#endif