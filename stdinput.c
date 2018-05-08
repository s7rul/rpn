/*
 * =====================================================================================
 *
 *       Filename:  stdinput.c
 *
 *    Description:  To set input to stdin
 *
 *       Compiler:  gcc
 *
 *         Author:  Erik Serrander
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define STRINGBUFFERSIZE 10000
#define WORDBUFFERSIZE 100

int get_stdinput(char *stringbuffer){
	long n;
	int c;

	for (n = 0; (c = getchar()) != EOF; n++){
		stringbuffer[n] = c;
	}

	stringbuffer[n] = '\0';

	return 0;
}

int wordcount(char *stringbuffer){
	int wcount = 0;

	for (int n = 0; stringbuffer[n] != '\0'; ++n){
		if (stringbuffer[n] == ' ' || stringbuffer[n] == '\n'){
			++wcount;
		}
	}

	return wcount;
}

void stringbuffer_to_inputv(char *stringbuffer, char **inputv){
	char wordbuffer[WORDBUFFERSIZE];
	int wcount = 0;
	int ccount = 0;
	int n, x;

	for (n = 0; stringbuffer[n] != '\0'; ++n){
		if (stringbuffer[n] == ' ' || stringbuffer[n] == '\n'){
			wordbuffer[ccount] = '\0';
			inputv[wcount] = malloc(sizeof(char) * (ccount + 1));

			for (x = 0; wordbuffer[x] != '\0'; ++x){
				inputv[wcount][x] = wordbuffer[x];
			}

			inputv[wcount][x] = '\0';
			++wcount;
			ccount = 0;
		} else {
			wordbuffer[ccount] = stringbuffer[n];
			++ccount;
		}

		printf("first element: %s\n", inputv[0]);
	}
}

int setstdinput(char **inputv){
	int wcount;
	char stringbuffer[STRINGBUFFERSIZE];

	get_stdinput(stringbuffer);

	wcount = wordcount(stringbuffer);

	inputv = malloc(sizeof(char) * wcount);

	stringbuffer_to_inputv(stringbuffer, inputv);

	return wcount;
}

void freeinputv(char **inputv, int inputc){
	for (int n = 0; n < inputc; ++n){
		free(inputv[n]);
	}

	free(inputv);
}
