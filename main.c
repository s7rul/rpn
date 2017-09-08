/* This program takes input at runtime and does apropriet calculation
 * acording to reverce polish notation*/

#include <stdio.h>
#include <stdlib.h>

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

	printf("%d", argc);
	printf("%s", argv[1]);

	if (argv[1][0] == 'h'){
		printhelp();
	}

	return 0;
}
