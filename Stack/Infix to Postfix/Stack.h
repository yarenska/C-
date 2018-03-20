#ifndef _STACK_
#define _STACK_
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class Stack{
public:
	Node<T>* top;
	Stack(){
		top = NULL;
	}
	Stack(const Stack<T>& rhs){
		if(rhs.isEmpty())
			this->top = NULL;
		else{
			Node<T>* walk = rhs.top;
			top = NULL;
			Node<T>* walk2;
			while (walk != NULL)
			{
				if(top == NULL){
					top = new Node<T>(walk->data);
					walk2 = top;
				}
				else
				{
					walk2->next = new Node<T>(walk->data);
					walk2 = walk2->next;
				}
				walk = walk->next;
			}
		}
	}

	const Stack<T>& operator =(const Stack<T>& rhs){
		if (this != &rhs)
		{
			Node<T>* walk = top;
			while (walk != NULL)
			{
				Node<T>* t = walk;
				walk = walk->next;
				delete t;
			}
			top = NULL;

			Node<T>* walk = rhs.top;
			top = NULL;
			Node<T>* walk2;
			while (walk != NULL)
			{
				if(top == NULL){
					top = new Node<T>(walk->data);
					walk2 = top;
				}
				else
				{
					walk2->next = new Node<T>(walk->data);
					walk2 = walk2->next;
				}
				walk = walk->next;

			}
		}
	}

	~Stack(){
		while (top != NULL)
		{
			Node<T>* t = top;
			top = top->next;
			delete t;
		}
	}

	bool isEmpty() const{ return top == NULL; }
	bool isFull() const{ return false; }
	T peek() const{ 
		if(isEmpty())
			exit(0);
		T e = top->data;
		return e; 
	} // Sadece topdaki datayý döndürüyor, stackte herhangi bir deðiþiklik yok.
	void push(T value){
		Node<T>* myNode = new Node<T>(value);
		myNode->next = top;
		top = myNode;
	}
	T pop(){
		if(isEmpty())
			exit(0);

		T element = top->data;
		Node<T>* old = top;
		top = top->next;
		delete old;
		return element; // Silinen nodedaki datayý return ediyor. Stackten 1 node çýkartýlýyor..
	}

	void print(){
		Node<T>* tempTop;
		tempTop = top;
		int count = 0;

		cout << "top-->";
		while(tempTop != NULL){
			if(count != 0)
				cout << "      " << tempTop->data << endl;
			else
				cout << "" << tempTop->data << endl;
			tempTop = tempTop->next;
			count++;
		}

		cout << endl;
	}
};

#endif

