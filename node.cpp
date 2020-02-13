#include <iostream>

#include "node.h"

using namespace std;

Node::Node(char* tempData){
	data = tempData; //pass in and set data 
	//left = NULL;
	//right = NULL;
}

/*Node::~Node(){
	delete node;
	left = NULL;
	right = NULL;
}*/

char* Node::getData(){
	return data;//return data
}

/*void Node::setData(char token){ //is this even needed
  data = token;
}*/



void Node::setLeft(Node * newLeft){
	left = newLeft;//set input to left node
}

void Node::setRight(Node * newRight){
	right = newRight;//set the input to right node
}

void Node::setNext(Node* newNext){
	next = newNext;//set next to input
}



Node * Node::getRight(){ //returns right node
	return right;
}

Node * Node::getLeft(){
	return left; 
}

Node* Node::getNext(){ //for navigating queue
	return next;
}



bool Node::checkLeft(){ //check for a node to the right
	if (left != NULL){
		return true;
	}
	return false;//else return false
}

bool Node::checkRight(){ //check for a node to the right
	if (right != NULL){
		return true;
	}
	return false;
}