//#include "Stack.h"
#include "Expression.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include "math.h"

using namespace std;

int main(){
	
	Expression exp1("A + B * (C + D ) - E / F * G + H");
	string a = exp1.convertToPostfix();
	cout << a << endl;

	system("pause");
	return 0;
}