#ifndef _BTREENODE_
#define _BTREENODE_
#include "LList.h"
#include <iostream>
using namespace std;

template<class T>
class BTreeNode{
	public:
		BTreeNode<T> *lchild;
		BTreeNode<T> *rchild;
		T word;
		int frequency;
		LList<int> listOfFiles;
	
	public:
		BTreeNode():lchild(NULL), rchild(NULL), frequency(0){}
		BTreeNode(const T &w):lchild(NULL), rchild(NULL), word(w), frequency(1){}
};

#endif