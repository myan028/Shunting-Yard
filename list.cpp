#include <iostream>

#include "list.h"
#include "node.h"

List::List(){ //list constructor
	
}


void List::push(Node* newNode){ //add node to the front of the list
	if(isEmpty()){ //empty list
		head = newNode; 
		tail = newNode;
	}
	else{
		newNode->setNext(head);
		head = newNode; //node is at the front now
	}
}


void List::pop(){ //deletes node from the front of the list
	if (!isEmpty()){ //if list has contents
		Node* temp = head; //temporary pointer to head
		head = head->getNext();
		delete temp; //bye
	}
	if (head == 0){ //if head is null
		head = 0;
		tail = 0; //
	}
}


void List::dissociate(){ ///same as pop, but does not delete the node
	if (!isEmpty()){
		head = head->getNext();
	}
	if (head == 0){
		head = 0;
		tail = 0;
	}
}


Node* List::peek(){ //looks at head
	return head;
}


void List::enqueue(Node* newNode){ //add node to tail of list
	if(isEmpty()){
		head = newNode; //set head and tail to new node
		tail = newNode;
	}
	else{ //set new node as new tail
		tail->setNext(newNode); 
		tail = newNode;
	}
}


void List::dequeue(){ //just like pop, takes from front
	if (!isEmpty()){
		Node* temp = head;
		head = head->getNext();
		delete temp;
	}
	if (isEmpty()){
		head = 0;
		tail = 0;
	}
}


bool List::isEmpty(){ //check if list is empty
	if (head == 0){
		tail = 0;
		return true;
	}
	return false; //not empty
}

Node* List::getHead(){ //return head
	return head;
}

Node* List::getTail(){ //return tail
	return tail;
}