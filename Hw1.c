//Author: Samuel Kebadu

//importing Standard IO library
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
		printf("%d is 0.\n", number);
	//Is this number even or odd?
	if(number%2 == 0)
		printf("%d is also even.\n", number);
	else
		printf("%d is also odd.\n", number);
	return 0;
}

