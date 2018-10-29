//Author: Samuel Kebadu
//G01053440

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *getDateAndTime();
int getInteger();

int main(){
	int my_int;
	printf("Today's	date and time: %s\n",getDateAndTime());
	my_int = getInteger();
	printf("number is %d \n",my_int);
}

int getInteger(){
	int i;
	char buffer[7];
	printf("Enter an Integer( 1 - 1000000 ) or type x to exit: ");
	fgets(buffer,8,stdin);
	i = atoi(buffer);
	return i;
}

char *getDateAndTime()
{
	time_t	t;
	time(&t);
	printf("time(): %ld\n", (long)t);
	return	ctime(&t);
}
