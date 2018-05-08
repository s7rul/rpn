/* Made by Erik Serander
 * This program takes input at runtime and does apropriet calculation
 * acording to reverce polish notation*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stringtoint.h"

int is_operator(char charoperator){

	if (charoperator == '+' || charoperator == '-' || charoperator == 'x' || charoperator == '/'){
		return 1;
	}
	return 0;
}

int is_number(char *input){//returns 1 for numbers and 0 for non numbers

	int n = 0;

	while (input[n] != '\0'){
		if (char_to_int(input[n]) == 99){
			return 0;
		}
		n++;
	}

	return 1;
}

int count_numbers(char **inputv, int inputc){
	//count the amount of numbers
	
	int count = 0;

	for (int n = 1; n < inputc; n++){
		count += is_number(inputv[n]);
	}

	return count;
}

void printhelp(){
	printf("############## Help for rpn ##################\n");
	printf("Makes calculation according to reverse polish \n");
	printf("notation.\n");
	printf("\n");
	printf("Each argument should be separetade by a single\n");
	printf("[space].\n");
	printf("\n");
	return;
}

int prossesing(stackT *stack, char *argv[], int argc){
	//prossesing the stacks to get an answer
	int a = 0;
	int b = 0;

	for (int n = 0; n < argc; n++){
		if (is_number(argv[n])){
			StackPush(stack, string_to_int(argv[n]));
		}
		if (is_operator(argv[n][0])){
			a = StackPop(stack);
			b = StackPop(stack);

			switch(argv[n][0]){
				case '+':
					StackPush(stack, b + a);
					break;
				case '-':
					StackPush(stack, b - a);
					break;
				case 'x':
					StackPush(stack, b * a);
					break;
				case '/':
					StackPush(stack, b / a);
					break;
			}
		}
	}

	return StackPop(stack);
}

int main( int argc, char *argv[]){

	stackT stack;

	int result = 0;

	char **inputv;
	int inputc = 0;

	if (argc == 1){
		fprintf(stderr, "No arguments\n");
		return 1;
	}

	if (argc == 2){

		if (argv[1][0] == 'h'){
			printhelp();
			return 0;
		}
	}

	if (argc > 2){
		inputv = argv;
		inputc = argc;
	}

	StackInit(&stack, count_numbers(inputv, inputc));
	result = prossesing(&stack, inputv, inputc);

	StackDestroy(&stack);

	printf("%d\n", result);

	return 0;
}
