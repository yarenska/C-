#include "LList.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
LList<T>& mergeMix(LList<T>& x, LList<T>& y){
	Node<T>* walk1 = x.head;
	Node<T>* walk2 = y.head;
	LList<T> merge;
	int count = 0;

	while(walk1 != NULL && walk2 != NULL){
		if(count % 2 == 0){
			merge.insertToEnd(walk1->data);
			walk1 = walk1->next;
			count++;
			continue;
		}
		if(count % 2 != 0){
			merge.insertToEnd(walk2->data);
			walk2 = walk2->next;
			count++;
			continue;
		}
	}
		if(walk1 == NULL && walk2 != NULL){
			while(walk2 != NULL){
				merge.insertToEnd(walk2->data);
				walk2 = walk2->next;
			}
		}

		if(walk1 != NULL && walk2 == NULL){
			while(walk1 != NULL){
				merge.insertToEnd(walk1->data);
				walk1 = walk1->next;
			}
		}

	return merge;
}


template <class T>
LList<T>& commonElements(LList<T> &A, LList<T>& B)
{
	LList<T> common;
	if(A.head == NULL || B.head == NULL){
		cout << "No element found in common.." << endl;
		return common;
	}

	Node<T>* walkA = A.head;
	Node<T>* walkB = B.head;
	Node<T>* walkCommon = common.head;
	int found = 0;

	while(walkA != NULL){
		while(walkB != NULL){
			if(walkA->data == walkB->data){
				found = 0;
				while(walkCommon != NULL){
					if(walkA->data == walkCommon->data){
						found = 1;
						break;
					}
					walkCommon = walkCommon->next;
				}

				if(found == 0)
				{	
					common.insertToEnd(walkB->data);
					break;
				}
			}	
			walkB = walkB->next;
		}
		
		walkCommon = common.head;
		walkB = B.head;
		walkA = walkA->next;
	}
	return common;
}


template <class T>
LList<T>& add(LList<T>& n1, LList<T>& n2){
	if(n1.head == NULL && n2.head == NULL){
		cout << "Nothing to add.." << endl;
		return n1;
	}

	if(n1.head != NULL && n2.head == NULL)
		return n1;

	if(n1.head == NULL && n2.head != NULL)
		return n2;

	Node<T>* walk1 = n1.head;
	Node<T>* walk2 = n2.head;
	LList<T> result;
	int sum = 0;
	int carry = 0;
	int rem,quo;

	while(walk1 != NULL && walk2 != NULL){
		sum = walk1->data + walk2->data + carry;
		quo = sum/10;
		rem = sum%10;
		if(quo == 1)
			carry = 1;
		else
			carry = 0;

		result.insertToEnd(rem);
		walk1 = walk1->next;
		walk2 = walk2->next;
	}

	if(walk1 != NULL && walk2 == NULL){
		while(walk1 != NULL){
			result.insertToEnd(walk1->data + carry);
			carry = 0;
			walk1 = walk1->next;
		}
	}

	if(walk1 == NULL && walk2 != NULL){
		while(walk2 != NULL){
			result.insertToEnd(walk2->data + carry);
			carry = 0;
			walk2 = walk2->next;
		}
	}

	if(walk1 == NULL && walk2 == NULL)
	{
		if(carry == 1)
		{
			result.insertToEnd(carry);
		}
	}

	return result;
}


int main(){
	
	//Rearrange test:
	LList<char> l;
	l.insertToEnd('A');
	l.insertToEnd('B');
	l.insertToEnd('C');
	l.insertToEnd('D');
	l.insertToEnd('E');
	l.insertToEnd('F');
	l.insertToEnd('G');
	l.insertToEnd('H');
	l.insertToEnd('I');
	l.traverse();
	l.reArrange();
	l.traverse();

	

	//QUESTION 5 TEST:
	/*LList<int> A;
	A.insertToEnd(4);
	A.insertToEnd(1);
	A.insertToEnd(1);
	A.insertToEnd(4);
	A.insertToEnd(5);
	A.traverse();
	LList<int> B;
	B.insertToEnd(6);
	B.insertToEnd(4);
	B.insertToEnd(8);
	B.insertToEnd(4);
	B.insertToEnd(10);
	B.insertToEnd(1);
	B.insertToEnd(10);
	B.traverse();
	LList<int> common;

	common = commonElements(A,B);
	common.traverse();*/


	//QUESTION 4 TEST:
	/*LList<int> l1;
	l1.insertToEnd(8);
	l1.insertToEnd(1);
	l1.insertToEnd(5);
	l1.insertToEnd(0);

	LList<int> l2;
	l2.insertToEnd(6);
	l2.insertToEnd(7);
	l2.insertToEnd(8);
	l2.insertToEnd(9);
	
	LList<int> merge; 
	merge = mergeMix(l1,l2);
	merge.traverse();*/
	


	//QUESTION 2 TEST:
	/*LList<int> number1;
	number1.insertToEnd(4);
	number1.insertToEnd(6);

	LList<int> number2;
	number2.insertToEnd(5);
	number2.insertToEnd(5);
	number2.insertToEnd(3);

	LList<int> result = add(number1, number2);
	result.traverse();
	*/

	//QUESTION 1 TEST: 
	// Simply reading double values from the file and create a Linked List of doubles.
	/*LList<double> l1;
	char* fname = "numbers.txt";
	l1.buildFromTextFile(fname);*/
	
	system("pause");
	return 0;

}