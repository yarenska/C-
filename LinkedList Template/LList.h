#ifndef _LIST_
#define _LIST_
#include "Node.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class LList{
public:
	Node<T>* head;
	int size; 
	LList(){ size = 0; head = NULL; }
	int getSize() const{ return size; }
	bool isEmpty() const{ return size == 0; }
	bool isFull() const{ return false; };

	void traverse() const {
		Node<T> *walk = head;
		if(walk != NULL){
			while(walk != NULL){
				cout << walk->data << "-->";
				walk = walk->next;
			}
			cout << "NULL" << endl;
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

	void itemAt(int pos, bool &status, const T& data){
		status = false;
		int count = 0;
		Node<T>* walk = head;
		T val;
		if(pos >= 0 && pos < size){
			if(pos == 0)
				val = head->data;
			else{
				while(count != pos){
					walk = walk->next;
					count++;
				}

				val = walk->data;
				status = true;
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

	void clear(){
		Node<T>* newNode;
		while(head != NULL){
			newNode = head;
			head = head->next;
			delete newNode;
		}
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

	void buildFromTextFile(char* fname){
	
		ifstream myReadFile;
		myReadFile.open(fname);
		double value;
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				 myReadFile >> value;
				 insertToEnd(value);
			}
			myReadFile.close();
		}
		
		
		else{
			cout << "Can not open file.." << endl;
		}
	}

	int negatives(){
		if(head == NULL)
			return -1;
		int count = 0;
		Node<T>* walk = head;
		while(walk != NULL){
			if(walk->data < 0)
				count++;
			walk = walk->next;
		}

		return count;
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

	void update(const T& data, const T& newData){
		if(head == NULL)
		{
			cout << "Can not change any value..";
		}

		Node<T>* walk = head;
		while(walk != NULL){
			if(walk->data == data)
			{
				walk->data = newData;
				break;
			}
			walk = walk->next;
		}
		return;
	}

	void saveAndExit(string filename){
		if(head == NULL)
			return;
		
		Node<T>* walk = head;
		ofstream myfile;
		myfile.open(filename);
	
		while(walk != NULL){
			myfile << walk->data << endl;
			walk = walk->next;
		}
		myfile.close();
	}

	void reArrange(){
		if(head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		Node<T>* prev = head;
		Node<T>* w1 = head->next;
		Node<T>* w2 = head->next->next;

		while(true){
			w1->next = w2->next;
			prev->next = w2;
			w2->next = w1;

			if(w1->next == NULL)
				break;
			prev = w1;
			w1 = prev->next;
			if(w1->next == NULL)
				break;
			w2 = w1->next;
		}
	}


};

#endif