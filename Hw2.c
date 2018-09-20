// Author: Samuel Kebadu


#include <stdio.h>
#include <stdbool.h>
int get_input();
void display(int val);


int main(){
	int why = get_input();
	display(why);
	int temp =0;
	do{
		temp = temp + (why%10);
		why = why/10;
	}while(why > 0);
	if(temp%9 == 0)
		printf("%d is divisible by 9\n",why);
	else
		printf("%d is not divisible by 9\n",why);
	return 0;
}

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
	}while(good = false);
	return out;
}

void display(int val){
	do{
		printf("%d\n",val%10);
		val = val/10;
	}while(val > 0);
}	

