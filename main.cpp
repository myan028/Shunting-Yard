#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <ctype.h>

#include "node.h"
#include "list.h"
#include "shunting.h"

using namespace std;

/*
Code by Michael Yan 2/10/2020

This code runs a Shunting Yard algorithm that can convert an equation, separated by spaces " ", into
the forms infix, postfix, and prefix.

*/

void Shunting::doPostfix(){ //postfix algorithm, prefix from here
	List* stack = new List();
	List* operatorStack = new List();
	
	while (!inputQueue->isEmpty()){
		
		char* headData = inputQueue->getHead()->getData(); //store head's data
		
		if (!isOperator(*headData)){ //if the first char in chararray is not an operator, push head to stack
			Node* newNode = new Node(headData);
			stack->push(newNode);
			inputQueue->dequeue();
		}
		else{ //if operator
			if (*headData == '('){ //dealing with parenthesis
				Node* newNode = new Node(headData); //push parenthesis straight to operator stack
				operatorStack->push(newNode);
				inputQueue->dequeue();
			}
			else if(*headData != ')'){ //not close parenthesis
				int pres = precedence(*headData); 
				if (operatorStack->peek() != NULL){ // if operator stack is not empty
					if (pres != 1){ //if operator has precedence of the main operators (2 3 or 4)
						while(operatorStack->peek() != NULL && precedence(*operatorStack->peek()->getData()) > pres){ //while nothing is in operator stack AND presedence of the top of operator stack is higher than new operator//push the top of the operator stack to the stack
							Node* newNode = new Node(operatorStack->peek()->getData()); //push the top of the operator stack to the stack
							stack->push(newNode);
							operatorStack->pop();
						}
						Node* newNode = new Node(headData); //push new operator to the stack
						operatorStack->push(newNode);
						inputQueue->dequeue();
					}
				}
				else{ //if operator stack is empty
					Node* newNode = new Node(headData);
					operatorStack->push(newNode);
					inputQueue->dequeue();
				}
			}
			else{ //close parenthesis
				while (*operatorStack->peek()->getData() != '('){ //while top of operator stack is not open parenthesis
					//push top of operator stack to main stack
					Node* newNode = new Node(operatorStack->peek()->getData());
					stack->push(newNode);
					operatorStack->pop();
				}
				inputQueue->dequeue(); //algorithm does not keep parenthesis
				operatorStack->pop();
			}			
		}
	}
	while (!operatorStack->isEmpty()){ //while operator stack is not empty, push top of operator stack to main stack
		Node* newNode = new Node(operatorStack->peek()->getData());
		stack->push(newNode);
		operatorStack->pop();
	}
	Node* current = stack->getHead();//set current to the head of stack
	
	List* inputQueue = new List();//reintialize the list 
	
	while(0 != current){ //while current is not null, push current to input queue
		Node* newNode = new Node(current->getData());
		inputQueue->push(newNode);
		current = current->getNext();
	}
	
	//while(playing == 1){
	makeTree(inputQueue); //build
	//}
	//;
}

/*void Shunting::deleteTree(Node* marker){ //discontinued delete
	if(marker != NULL){
		deleteTree(marker->getLeft());
		deleteTree(marker->getRight());
		delete marker;
	}
}*/

void Shunting::makeTree(List* input){ //building the tree (previously in main.cpp)
	List* tree = new List(); //initialize tree as a list class member
	while (!input->isEmpty()){ //while input is not empty
		if(isdigit(*input->peek()->getData())){ //if first char of input is a digit
			//push the input head to the tree list
			Node* filler = new Node(input->peek()->getData());
			tree->push(filler);
			input->dequeue();
		}
		else{
			Node* currentNode = new Node(input->peek()->getData());//create node for operator
			currentNode->setRight(tree->peek()); //set right node to the head of tree
			tree->dissociate(); //take head out of tree
			currentNode->setLeft(tree->peek()); //set left node to the head of tree
			tree->dissociate(); //take out the head of tree
			tree->push(currentNode); //add the operator to the tree
			input->dequeue(); //take head out of the input queue
		}
	}
	
	//int playing = 1;
	cout << "Which output would you like? ('infix', 'postfix', 'prefix', or 'quit') "; //prompt the user for choice of algorithm
	
	char typeInput[100];
	cin.get(typeInput, 100);
	cin.get();
	
	if(strcmp(typeInput, "infix") == 0){ //run infix algorithm with head
		infix(tree->peek());
		cout << endl;
	}
	else if(strcmp(typeInput, "postfix") == 0){ //run postfix algorithm with head
		postfix(tree->peek());
		cout << endl;
	}
	else if(strcmp(typeInput, "prefix") == 0){ //run prefix algorithm with head
		prefix(tree->peek());
		cout << endl;
	}
	/*else if (strcmp(typeInput, "quit") == 0){
		playing = 0;
	}*/
	//deleteTree(tree->getHead);
	
}






int main(){
	Shunting* shunt = new Shunting();//create a new shunting object
	
	cout << "Type an equation: ";
	char input[100];//create input char
	cin.get(input, 100);//get input
	cin.get();
	
	char* token; 
	token = strtok(input, " "); //automatically separate char into tokens
	
	List* newList = new List();//make a new linked list
	
	while (token != NULL){
		Node* newNode = new Node(token);//create a new node with the value of token
		newList->enqueue(newNode); //add to linked list
		token = strtok(NULL, " ");
	}
	
	shunt->setQueue(newList); //setting inputQueue equal to user input tokens
	
	shunt->doPostfix(); //execute postfix algorithm
		
	
	
	
}