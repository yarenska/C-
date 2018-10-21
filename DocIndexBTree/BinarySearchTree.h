#ifndef _BINARYSEARCHTREE_
#define _BINARYSEARCHTREE_
#include "BTreeNode.h"
#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree{
	private:
		BTreeNode<string> *root;
		BTreeNode<string>*& insertWord(BTreeNode<string>* r, const string& w, int fileName){
			if(r == NULL){ //the word is new, so must added itself as well as the file contains this word.
			    r = new BTreeNode<string>(w);
				r->listOfFiles.insertToEnd(fileName);
				return r;
			}
			if(r->word.compare(w) == 0) //the word is found before, so we need to update its file list. 
			{
				r->listOfFiles.insertToEnd(fileName);
				r->frequency++;
				return r;
			}
			if(r->word.compare(w) > 0) //if this condition is satisfied,
								       //our word must reside in the left of the current child.
				r->lchild = insertWord(r->lchild,w,fileName);

			if(r->word.compare(w) < 0)//if this condition is satisfied,
								       //our word must reside in the right of the current child.
				r->rchild = insertWord(r->rchild,w,fileName);
			
			return r;
		}

		void printFiles(BTreeNode<string>* r, const string& w, bool* f){
			if(r == NULL) 
				return;
			if(r->word.compare(w) == 0){
				r->listOfFiles.traverse();
				*f = 1;
			}
			if(r->word.compare(w) > 0)
				printFiles(r->lchild,w,f);
			if(r->word.compare(w) < 0)
				printFiles(r->rchild,w,f);
		} 

		void inorder(BTreeNode<string> *r)const {
			if(r == NULL)
				return;
			inorder(r->lchild);
			string word = r->word;
			cout << word << " ";
			inorder(r->rchild);
		}

		void postorder(BTreeNode<string> *r)const {
			if(r == NULL)
				return;
			postorder(r->lchild);
			postorder(r->rchild);
			string word = r->word;
			cout << word << " ";
		}

		void preorder(BTreeNode<string> *r)const {
			if(r == NULL)
				return;
			string word = r->word;
			cout << word << " ";
			preorder(r->lchild);
			preorder(r->rchild);	
		}

	public:
		BinarySearchTree():root(NULL){}
		void insertWord(const string &w, int fileName) //(wrapper function)
		{
			root = insertWord(root,w,fileName); //insert new node if word is not in BST,
											    //otherwise just update list of files
		}											 
		void printListOfFiles(const string &w){ //print files that contain w
			bool flag = 0;
			printFiles(root,w,&flag);
			if(flag != 1)
				cout << "No such word found..";
		}  

		void inOrderTraversal()const //wrapper method for private inorder method
		{
			cout << "Inorder: ";
			inorder(root);
		}

		void preOrderTraversal()const //wrapper method for private inorder method
		{
			cout << "Preorder: ";
			preorder(root);
		}

		void postOrderTraversal()const //wrapper method for private inorder method
		{
			cout << "Postorder: ";
			postorder(root);
		}

};

#endif
	
