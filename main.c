/* Made by Erik Serander
 * This program takes input at runtime and does apropriet calculation
 * acording to reverce polish notation*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double chartoint(char charnumber){

	switch (charnumber){
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
	}
	return 99;
}
int leghtofnumber(char *charnumber){

	char scanner;
	int n = 0;

	printf("while function");

	while (scanner != '\0'){
		printf("charnumber: %c\n", charnumber[n]);
		scanner = charnumber[n];
		n++;
	}

	return n - 1;
}

double stringtoint(char *charnumber){
	//input char and returns int
	int n;
	double y;
	double output = 0;

	n = leghtofnumber(charnumber);

	printf("leaght of number: %d\n", n);

	for (int pos = 0; pos < n; pos++){
		y = n - pos;
		printf("%d", y);
		output =+ pow(10, y) * chartoint(charnumber[pos]); 
	}
	return output;
}

int countnumbers(char *argv[], int argc){
	//count the amount of numbers
}

int stackinit(char *argv[]){
	//takes input and makes apropriate size stack
	
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
