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
	char write;
	FILE *file;
	printf("Today's	date and time: %s\n",getDateAndTime());
	my_int = getInteger();
	if(my_int == -1)
		return 0;
	printf("number is %d \n",my_int);
	printf("Save to a file? (y/n) (default: N): ");
	scanf("%c", &write);
	if(write == 'y'){
		char fname[100];
		printf("Enter file name: ");
		scanf("%s", &fname);
		file = fopen(fname, "w");
		printf("opened");
		if(file == NULL){
			printf("ERROR!");
			fclose(file);
			exit(1);
		}
        	fprintf(file,"%d", my_int);
        	fclose(file);
		exit(0);
	}
	return 0;
}

int getInteger(){
	int i;
	char buffer[7];
	printf("Enter an Integer( 1 - 1000000 ) or type x to exit: ");
	fgets(buffer,8,stdin);
	if(buffer[0] == 'x')
		return -1;
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
