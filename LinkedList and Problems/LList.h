#ifndef _LIST_
#define _LIST_
#include "Node.h"
#include "Stack.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;


class LList{
public:
	Node* head;
	int size; 
	LList(){ size = 0; head = NULL; }
	int getSize() const{ return size; }
	bool isEmpty() const{ return size == 0; }
	bool isFull() const{ return false; };
	bool operator == (const LList& l){
		if(this->head == NULL && l.head == NULL)
			return true;
		if(this->head == NULL && l.head != NULL)
			return false;
		if(this->head != NULL && l.head == NULL)
			return false;
		int counter = 0;
		Node* walk1 = this->head;
		Node* walk2 = l.head;

		while(walk1 != NULL && walk2 != NULL){
			if(walk1->data == walk2->data)
				counter++;
			walk1 = walk1->next;
			walk2 = walk2->next;
		}

		if((walk1 == NULL && walk2 != NULL) || (walk1 != NULL && walk2 == NULL))
			return false;
		else if(counter == l.size)
			return true;
		return false;
	}
	void traverse() const {
		Node *walk = head;
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

	void insertToFront(int data){
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		size++;
	}

	void insertToEnd(int data){
		Node* newNode = new Node(data);
		Node* walk = head;
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

	void itemAt(int pos, bool &status, int &val){
		status = false;
		int count = 0;
		Node* walk = head;
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

	bool deleteAt(int pos, int &value){
		if(pos >= 0 && pos < size){
			if(pos == 0){
				value = head->data;
				Node* old = head;
				head = head->next;
				delete old;
				return true;
			}

			else{
				int count = 0;
				Node* walk = head;
				Node* prev = NULL;
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
		Node* newNode;
		while(head != NULL){
			newNode = head;
			head = head->next;
			delete newNode;
		}
	}

	int indexOf(int value){
		Node* walk = head;
		int count = -1;

		while(walk != NULL){
			count++;
			if(walk->data == value)
				return count;
			walk = walk->next;
		}

		return -1;
	}

	void insertAt(int position, int data){
		if(position == 0){
			insertToFront(data);
		}
		else if(position == size){
			insertToEnd(data);
		}
		else if(position < size){
			Node* walk = head;
			Node* prev = NULL;
			int count = 0;

			while(count != position){
				prev = walk;
				walk = walk->next;
				count++;
			}

			Node* myNode = new Node(data);
			prev->next = myNode;
			myNode->next = walk;

		}

		return;
	}

	
	// MY SOLUTIONS FOR SOME OF GEEKS FOR GEEKS LINKED LIST PROBLEMS
	void reverse(){
	
		Node* walk = head->next;
		Node* prev = head;
		while(walk != NULL)
		{
			prev->next = walk->next;
			walk->next = head;
			head = walk;
			walk = prev->next;
			this->traverse();
		}

		return;
	}

	void shrink(){
		Node* walk = head->next;
		Node* prev = head;
		Node* old;

		while(walk != NULL){
			if(prev->data == walk->data){
				old = walk;
				prev->next = walk->next;
				walk = walk->next;
				delete old;
				size--;
				continue;
			}

			prev = walk;
			walk = walk->next;
		}
	}

	void expand(){
		Node* walk = head;

		while(walk != NULL){
			int data = walk->data;

			for(int i = 0; i < data; i++){
				Node* newNode = new Node(data);
				newNode->next = walk->next;
				walk->next = newNode;
				walk = walk->next;
			}

			walk = walk->next;
		}
	
	}

	void skipMdeleteN(int M, int N){
		if(M < 0 || N < 0)
			return;

		Node* walk = head;
		Node* prev = NULL;
		int MFlag = 1, MCount = 0, NCount = 0, NFlag = 0;
		if(M == 0){
			while(head != NULL){
				Node* old = head;
				head = head->next;
				delete old;
				size--;
			}
			return;
		}

		while(walk != NULL){
			if(MCount < M && MFlag == 1){
				prev = walk;
				walk = walk->next;
				MCount++;
				continue;
			}
			else if(MCount >= M){
				MFlag = 0;
				MCount = 0;
				NFlag = 1;
			}
			else if(NCount < N && NFlag == 1){
				Node* old = walk;
				prev->next = walk->next;
				walk = walk->next;
				delete old;
				size--;
				NCount++;
				continue;
			}
			else if(NCount >= N){
				NFlag = 0;
				NCount = 0;
				MFlag = 1;
			}
		}
	}

	void removeSingleDigits(){
		if(head == NULL)
			return;
		while(head != NULL)
		{
			if(head->data / 10 == 0){
				Node* old = head;
				head = head->next;
				delete old;
				size--;
			}
			else 
				break;
		}

		Node* prev = head;
		Node* walk = head->next;

		while(walk != NULL){
			if(walk->data / 10 == 0){
				Node* old = walk;
				prev->next = walk->next;
				walk = walk->next;
				delete old;
				size--;
			}
			else{
				prev = walk;
				walk = walk->next;
			}
		}
	}

	static int intersectionPoint(LList &l1, LList& l2){
		if(l1.head == NULL || l2.head == NULL)
			exit(0);
		
		Node* w1 = l1.head;
		Node* w2 = l2.head;
		int iPoint = 0;
		int flag = 0;
		int point = 0;

		while(w1 != NULL){
			point = w1->data;
			w2 = l2.head;
			while(w2 != NULL){
				if(w2->data == point)
				{
					flag = 1;
					iPoint = point;
					break;
				}
				w2 = w2->next;
			}
			if(flag)
				break;
			w1 = w1->next;
		}
		return iPoint;
	}

	void rotate_kth(int k){
		if(k >= this->size || k == 0)
			return;
		Node* walk = head;
		Node* prev = NULL;
		int count = 0;
		while(count != k){
			prev = walk;
			walk = walk->next;
			count++;
		}

		Stack s;
		while(walk != NULL)
		{
			s.push(walk->data);
			Node* old = walk;
			prev->next = walk->next;
			walk = walk->next;
			delete old;		
			size--;
		}
		while(!s.isEmpty()){
			int data = s.pop();
			this->insertToFront(data);
		}
	}

	void reverse_kNode(int k){
		if(k == 0)
			return;
		if(k >= size)
			k = k % size;

		Node* prev = head;
		Node* walk = head->next;
		int count = 0;
		while(count != k){
			prev->next = walk->next;
			walk->next = head;
			head = walk;
			walk = prev->next;
			count++;	
		}

	}

	void segregateEvenOdd(){
		if(head == NULL)
			return;

		Node* prev = head;
		Node* walk = head->next;
		Stack s;

		while(walk != NULL){
			if(walk->data % 2 == 0){
				Node* old = walk;
				prev->next = walk->next;
				s.push(walk->data);
				walk = walk->next;
				delete old;
			}
			else{
				prev = walk;
				walk = walk->next;
			}
		}

		while(!s.isEmpty()){
			this->insertToFront(s.pop());
		}
		
	}

	void removeDup(){ //from unsorted list
		if(head == NULL)
			return;
		Node* walk = head;
		Node* prev = NULL;
		Node* w1;
		int data;

		while(walk != NULL){
			prev = walk;
			w1 = walk->next;

			while(w1 != NULL){
				if(w1->data == walk->data){
					Node* old = w1;
					prev->next = w1->next;
					w1 = w1->next;
					delete old;
					size--;
				}
				else{
					prev = w1;
					w1 = w1->next;
				}
			}

			walk = walk->next;
		}
	}

	void reArrange(){
		if(head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		Node* prev = head;
		Node* w1 = head->next;
		Node* w2 = head->next->next;

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