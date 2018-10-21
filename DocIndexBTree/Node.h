#ifndef _NODE_
#define _NODE_
#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T data;
	Node<T> *next;
	Node(){
		next = NULL;
	}
	Node(const T& data){
		next = NULL;
		this->data = data;
	}
};


#endif