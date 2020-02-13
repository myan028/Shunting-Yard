#include <iostream>
#include <cstring>

#include "list.h"
#include "node.h"
#include "shunting.h"

using namespace std;

Shunting::Shunting(){ //constructor
  List* inputQueue = new List(); //initialize queue for user input
}


void Shunting::infix(Node* subtree){
	if (isOperator(*subtree->getData())){ //if the data in the node is an operator
		cout << "("; //add an open parenthesis for operator
	}
	if (subtree->getLeft() != NULL){ //if there is a node to the left
		infix(subtree->getLeft()); //recursion using the left node
	}
	
	cout << subtree->getData() << ""; //print node using infix
	
	if (subtree->getRight() != NULL){ //if there is a node to the left
		infix(subtree->getRight()); //right
	}
	if (isOperator(*subtree->getData())){ //if operator
		cout << ")";//add a closed parenthesis for operator
	}
}



void Shunting::postfix(Node* subtree){
	if (subtree->checkLeft()){ 
  		postfix(subtree->getLeft()); //recursion using left
	}
	if(subtree->checkRight()){
	   postfix(subtree->getRight()); //right node
	}
	cout << subtree->getData() << " "; //print node using postfix
}



void Shunting::prefix(Node* subtree){
	cout << subtree->getData() << " "; //print node
	if (subtree->getLeft() != NULL){
  		prefix(subtree->getLeft()); //recursion on left node
	}
	if(subtree->getRight() != NULL){
		prefix(subtree->getRight()); //recursion on left node
	}
}



List* Shunting::getQueue(){
	return inputQueue; //return input queue
}


void Shunting::setQueue(List * newQueue){ //set queue globally
	inputQueue = newQueue; //sets the input queue to the inputted list
}


bool Shunting::isOperator(char data){ //check for operator in node
	if (data == '+' || data == '-' || data == '/' || data == '*' || data == '^' || data == ')' || data == '(') //supported operators
	{
		return true;
	}
	return false; //if none of those characters, it is not a supported operator
}


int Shunting::precedence(char data){ //assigned precedence for the operators
	if (data == '^'){
		return 4; //highest precedence
	}
	else if (data == '*' || data == '/'){
		return 3;
	}
	else if (data == '+' || data == '-'){
		return 2; //lowest precedence
	}
	else{
		return 1; //must be a value or variable
	}
}		//parenthesis are dealt with in a different way




