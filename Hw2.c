// Author: Samuel Kebadu
// G01053440


// importing both standard IO and standard boolean datatype
#include <stdio.h>
#include <stdbool.h>

//Declaring UDF in memory before main
int get_input();
void display(int val);

int main(){
	int input = get_input();
	int why = input;
	display(why);
	int temp =0;
	do{
		temp = temp + (why%10);
		why = why/10;
	}while(why > 0);
	if(temp%9 == 0)
		printf("%d is divisible by 9\n",input);
	else
		printf("%d is not divisible by 9\n",input);
	return 0;
}

// gets user input value
int get_input(){
	int out;
	bool good = false;
	do{
		printf("Enter a number(1-999999): ");
		scanf("%d",&out);
		if(out>=1 && out<=999999)
			good = true;
		else
			printf("number not in range, please try again.\n");
	}while(good == false);
	return out;
}

// displays each digit starting from right
void display(int val){
	do{
		printf("%d\n",val%10);
		val = val/10;
	}while(val > 0);
}	

