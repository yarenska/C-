#ifndef _QUEUE_
#define _QUEUE_
#include "Node.h"
#include <string>

template <class T>
class Queue{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue(){
		front = rear = NULL;
	}
	~Queue(){
		Node <T> *tmp = front;
		while(front != NULL){
			tmp = front;
			front = front ->next;
			delete tmp;

		}
		rear = front = NULL;
	}
	Queue(const Queue &other){
		Node<T> *walk,*walk_other;
		if(other.front != NULL){
			front = new Node<T>(other.front->data);
			walk = front;
			walk_other = other.front->next;
			while(walk_other != NULL){
				walk->next = new Node<T>(walk_other->data);
				rear = walk->next;
				walk_other = walk_other->next;
				walk = walk->next;
			}
		}
	}
	const Queue operator=(const Queue &rhs){
		if(this != &rhs){//in order to avoid self assignment
			Node <T> *tmp = front;
			while(front != NULL){
				tmp = front;
				front = front ->next;
				delete tmp;

			}
			rear = front = NULL;
			Node<T> *walk,*walk_other;
			if(rhs.front != NULL){
				front = new Node<T>(rhs.front->data);
				walk = front;
				walk_other = rhs.front->next;
				while(walk_other != NULL){
					walk->next = new Node<T>(walk_other->data);
					rear = walk->next;
					walk_other = walk_other->next;
					walk = walk->next;
				}

			}
		}
		return *this;
	}

	bool isEmpty()const{ return front == NULL; }
	bool isFull()const{ return false; }
	void enqueue(const T& data){
		Node<T>* newNode = new Node<T>(data);
		if(isEmpty())
			rear = front = newNode;
		else{
			rear->next = newNode;
			rear = rear->next;
		}
	}
	T dequeue(){
		if(isEmpty())
			exit(0);
		T element;
		if(front->next == NULL){ // front == rear
			element = front->data;
			front = rear = NULL;
		}
		else{
			Node<T>* old = front;
			element = front->data;
			front = front->next;
			delete old;
		}
		return element;
	}
	T itemAtFront()const{
		if(!isEmpty())
			return front->data;
		else
			exit(0);
	}
	void print()const{
		if(isEmpty()){
			cout << "Queue is empty.." << endl;
			return;
		}
		Node<T>* walk = front;
		while(walk != NULL){
			cout << walk->data << " ";
			walk = walk->next;
			}
		cout << endl;
		}
};



#endif