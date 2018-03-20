#ifndef _NODE_
#define _NODE_
#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(){
		next = NULL;
		data = 0;
	}
	Node(int data){
		next = NULL;
		this->data = data;
	}
	bool operator ==(const Node& node){
		return (this->data == node.data && this->next == node.next);
	}
};


#endif