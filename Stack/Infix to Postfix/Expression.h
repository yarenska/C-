#ifndef _EXPRESSION_
#define _EXPRESSION_
#include <iostream>
using namespace std;

class Expression{
private:
	string infix;
	string postfix;
	bool precedence(char op1, char op2);
public:
	Expression();
	Expression(string);
	~Expression();
	string getInfix();
	void showInfix();
	void showPostfix();
	string convertToPostfix();
};


#endif