#ifndef SHUNTING_H
#define SHUNTING_H

#include <iostream>
#include <cstring>

#include "list.h"
#include "node.h"

using namespace std;

class Shunting{
	public:
		Shunting();//constructor
		//~Shunting();
		//void deleteShunting(Node*);
		List* getQueue();
		void setQueue(List*);
		void doPostfix();
		void makeTree(List*);
		void infix(Node*);
		void postfix(Node*);
		void prefix(Node*);
	private:
		bool isOperator(char);//is the char inputed a operator
		int precedence(char);//what is the precedence of the operator inputed
		List* stack;//make new linked list for output stack
		List* operatorStack;//make new linked list for operator stack
		List* inputQueue;//make new linked list for the input queue
};

#endif