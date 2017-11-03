/* Made by Erik Serander
 * This program takes input at runtime and does apropriet calculation
 * acording to reverce polish notation*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chartoint(char charnumber){

	int result = 0;

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
int leghtofnumber(char *charnumber){

	char scanner = ' ';
	int n = 0;

	while (scanner != '\0'){
		scanner = charnumber[n];
		n++;
	}

	return n - 1;
}

int stringtoint(char *charnumber){
	//input char and returns int
	int n;
	int y;
	int output = 0;

	n = leghtofnumber(charnumber) - 1;

	for (int pos = 0; pos <= n; pos++){
		y = n - pos;
		output += pow(10, y) * chartoint(charnumber[pos]); 
	}
	return output;
}

int countnumbers(char *argv[], int argc){
	//count the amount of numbers
	return 0;
}

int stackinit(char *argv[]){
	//takes input and makes apropriate size stack
	return 0;
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

	printf("number of arguments: %d\n", argc);
	printf("number (string): %s\n", argv[1]);

	if (argv[1][0] == 'h'){
		printhelp();
	}
	else {
		printf("number: %d\n",stringtoint(argv[1]));
	}

	return 0;
}
