#include <stdio.h>
int main(){
	int number;
	printf("enter an integer: ");
	scanf("%d", &number);
	
	//Is this number negative?
	if(number < 0)
		printf("%d is negative.\n", number);
	else if(number > 0)
		printf("%d is positive.\n", number);
	else
		printf("%d is 0.", number);
	return 0;
}

