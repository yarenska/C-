// this is a class method.

int occurOnce(){
	int count = 0;
	int countCurrent = 0;
	while(!isEmpty()){
		int data = pop();
		countCurrent = 1;
		while(!isEmpty()){
			int temp = pop();
			if(data != temp){
				push(temp);
				break;
			}
			else{
				countCurrent++;
			}
		}
		if(countCurrent == 1){
			count++;
		}
	}
	return count;
}