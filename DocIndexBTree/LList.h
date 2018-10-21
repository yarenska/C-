#ifndef _LIST_
#define _LIST_
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class LList{
public:
	Node<T>* head;
	int size; 
	LList(){ size = 0; head = NULL; }
	~LList(){
		Node<T>* newNode;
		while(head != NULL){
			newNode = head;
			head = head->next;
			delete newNode;
		}
	}
	int getSize() const{ return size; }
	bool isEmpty() const{ return size == 0; }
	bool isFull() const{ return false; };

	void traverse() const {
		Node<T> *walk = head;
		if(walk != NULL){
			while(walk != NULL){
				cout << walk->data << " ";
				walk = walk->next;
			}
			//cout << "NULL" << endl;
		}

		else{
			cout << "List is empty." << endl;
		}
	}

	void insertToFront(const T& data){
		Node<T>* newNode = new Node<T>(data);
		newNode->next = head;
		head = newNode;
		size++;
	}

	void insertToEnd(const T& data){
		Node<T>* newNode = new Node<T>(data);
		Node<T>* walk = head;
		if(size == 0){
			head = newNode;
			size++;
		}
		else{
			while(walk->next != NULL){
				walk = walk->next;
			}

			walk->next = newNode;
			size++;
		}
	}

	T& itemAt(int pos){
		int count = 0;
		Node<T>* walk = head;
		T val;
		if(pos >= 0 && pos < size){
			if(pos == 0)
				return head->data;
			else{
				while(count != pos){
					walk = walk->next;
					count++;
				}

			return walk->data;
			}
		}
	}

	bool deleteAt(int pos, const T& value){
		if(pos >= 0 && pos < size){
			if(pos == 0){
				value = head->data;
				Node<T>* old = head;
				head = head->next;
				delete old;
				return true;
			}

			else{
				int count = 0;
				Node<T>* walk = head;
				Node<T>* prev = NULL;
				while(count != pos){
					prev = walk;
					walk = walk->next;
					count++;
				}

				value = walk->data;
				prev->next = walk->next;
				delete walk;
				return true;
			}
		}

		return false;
	}

	

	int indexOf(T value){
		Node<T>* walk = head;
		int count = -1;

		while(walk != NULL){
			count++;
			if(walk->data == value)
				return count;
			walk = walk->next;
		}

		return -1;
	}

	void insertAt(int position, T data){
		if(position == 0){
			insertToFront(data);
		}
		else if(position == size){
			insertToEnd(data);
		}
		else if(position < size){
			Node<T>* walk = head;
			Node<T>* prev = NULL;
			int count = 0;

			while(count != position){
				prev = walk;
				walk = walk->next;
				count++;
			}

			Node<T>* myNode = new Node<T>(data);
			prev->next = myNode;
			myNode->next = walk;

		}

		return;
	}
};

#endif