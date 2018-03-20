// this is a function you can declare above "int main()" after including "Stack.h" and <math.h>

int convertBinaryToInt(char* binString)
	{
		Stack<char> s;
		int res = 0;
		while((*binString) != '\0'){
			s.push(*binString);
			binString++;
		}
		s.print();
		int value;
		int exp = 0;

		while(!s.isEmpty()){
			char a = s.pop();
			value = a - '0';
			if(value == 1)
				res += pow(2,exp);
			exp++;
		}
		
		return res;
}
