//Author: Samuel Kebadu
//G01053440

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *getDateAndTime();
int getInteger();
char *convert_to_hex();
char *convert_to_oct();
char *convert_to_bin();

int main(){
	int my_int;
	char write;
	FILE *file;
	char username[100];
	printf("Today's	date and time: %s\n",getDateAndTime());
	my_int = getInteger();
	printf("Name: ");
	scanf("%s", &username);
	if(my_int == -1)
		return 0;
	printf("Hex: %s\n",convert_to_hex(my_int));
	printf("Octal: %s\n",convert_to_oct(my_int));
	printf("binary: %s\n",convert_to_bin(my_int));
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

char *convert_to_hex(int value) {
	long int decimalNumber,quotient;
	int i=1,j,temp;
	char hexadecimalNumber[100];
	quotient = value;
	while (quotient!=0){
		temp = quotient % 16;
		//Convert integer into character
		if( temp < 10)
			temp =temp + 48;
		else
			temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	char hexreturn[i-1];
	for(j=i-1,j>0)
		hexreturn[i-j-1] = hexadecimalNumber[j];
	return hexreturn;
}

char *convert_to_oct(int value) {
	char* oct_value = (char*)malloc((((sizeof(int)*8)+2)/3)+1);
	int length = ((sizeof(int)*8)+2)/3, quo;
	oct_value[length] = '\0';
	char digit_value;
	while(length>0) {
		quo = value%8;
		digit_value = (char)(quo+48);
		oct_value[--length] = digit_value;
		value /= 8;
	}
	return oct_value;
}

char *convert_to_bin(int value) {
	char* bin_value = (char*)malloc((sizeof(int) * 8)+1);
	int length = sizeof(int) * 8;
	bin_value[length] = '\0';
	while(length>0)
	{
		bin_value[--length] = (char)((value%2)+48);
		value >>= 1;
	}
	return bin_value;
}

