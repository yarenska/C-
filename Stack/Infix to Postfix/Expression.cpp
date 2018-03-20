#include "Expression.h"
#include "Stack.h"

Expression::Expression(){}

Expression::Expression(string infix){
	this->infix = infix;
}

Expression::~Expression()
{
}

string Expression::getInfix(){
	return infix;
}
void Expression::showInfix(){
	for(int i = 0; i < infix.length(); i++){
		cout << infix.at(i);
	}
}

void Expression::showPostfix(){
	for(int i = 0; i < postfix.length(); i++){
		cout << postfix.at(i);
	}	
}

string Expression::convertToPostfix(){
	Stack<char> stack;

	for(int i = 0; i < infix.length(); i++){
		if(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/'){
			while(!stack.isEmpty() && stack.peek() != '(' && precedence(stack.peek(),infix.at(i)))
			{
				postfix += stack.peek();
				postfix += ' ';
				stack.pop();
			}
			stack.push(infix.at(i));
		}
		else if(infix.at(i) == '('){
			stack.push(infix.at(i));
		}
		else if(infix.at(i) == ')'){
			char a = stack.peek();
			while(!stack.isEmpty() && (a != '(')){
				postfix += stack.peek();
				postfix += ' ';
				stack.pop();
				a = stack.peek();
			}
			stack.pop();
		}
		else if(infix.at(i) == ' '){
			continue;
		}
		else{
			postfix += infix.at(i);
			postfix += ' ';
		}
	}

	while(!stack.isEmpty()){
		postfix += stack.pop();
		postfix += ' ';
	}

	return postfix;
	
}

bool Expression::precedence(char op1, char op2){
	if((op1 == '*' && op2 == '+') || (op1 == '*' && op2 == '-') || (op1 == '*' && op2 == '*') || (op1 == '*' && op2 == '/') ||
		(op1 == '/' && op2 == '+') || (op1 == '/' && op2 == '-') || (op1 == '/' && op2 == '/') || (op1 == '/' && op2 == '*') ||
		(op1 == '+' && op2 == '+') || (op1 == '+' && op2 == '-') || (op1 == '-' && op2 == '-') || (op1 == '-' && op2 == '+'))
		return true;
	return false;
}
