/* Made by Erik Serander
 * This program takes input at runtime and does apropriet calculation
 * acording to reverce polish notation*/

//functions declared in math.c
int mypow(int x,int y);

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int char_to_int(char charnumber){

	int result = 99;

	switch (charnumber){
		case '0':
			result = 0;
			break;
		case '1':
			result = 1;
			break;
		case '2':
			result = 2;
			break;
		case '3':
			result = 3;
			break;
		case '4':
			result = 4;
			break;
		case '5':
			result = 5;
			break;
		case '6':
			result = 6;
			break;
		case '7':
			result = 7;
			break;
		case '8':
			result = 8;
			break;
		case '9':
			result = 9;
			break;
	}
	return result;
}
int leght_of_number(char *charnumber){

	char scanner = ' ';
	int n = 0;

	while (scanner != '\0'){
		scanner = charnumber[n];
		n++;
	}

	return n - 1;
}

int string_to_int(char *charnumber){
	//input char and returns int
	int n;
	int y;
	int output = 0;

	n = leght_of_number(charnumber) - 1;

	for (int pos = 0; pos <= n; pos++){
		y = n - pos;
		output += mypow(10, y) * char_to_int(charnumber[pos]); 
	}
	return output;
}

int is_number(char* input){//returns 1 for numbers and 0 for non numbers

	int n = 0;

	while (input[n] != '\0'){
		if (char_to_int(input[n]) == 99){
			return 0;
		}
		n++;
	}

	return 1;
}

int count_numbers(char *argv[], int argc){
	//count the amount of numbers
	
	int count = 0;

	for (int n = 1; n < argc; n++){
		count += is_number(argv[n]);
	}

	return count;
}

void printhelp(){
	printf("############## Help for rpn ##################\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return;
}

int main( int argc, char *argv[]){

	stackT numberstack;

	printf("number of arguments: %d\n", argc);
	printf("number (string): %s\n", argv[1]);

	if (argv[1][0] == 'h'){
		printhelp();
	}

	else {
		printf("first number: %d\nnumber count: %d\n",string_to_int(argv[1]), count_numbers(argv, argc));
		StackInit(&numberstack, count_numbers(argv, argc));
		StackPush(&numberstack, 1);
		printf("%d\n", StackPop(&numberstack));
		StackDestroy(&numberstack);
	}

	return 0;
}
