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
#include "stdinput.h"

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

void stringbuffer_to_inputv(char *stringbuffer, char **input){
	char wordbuffer[WORDBUFFERSIZE];
	int wcount = 0;
	int ccount = 0;
	int n, x;

	for (n = 0; stringbuffer[n] != '\0'; ++n){
		if (stringbuffer[n] == ' ' || stringbuffer[n] == '\n'){
			wordbuffer[ccount] = '\0';
			input[wcount] = (char *)malloc(sizeof(char) * (ccount + 1));

			for (x = 0; wordbuffer[x] != '\0'; ++x){
				input[wcount][x] = wordbuffer[x];
			}

			input[wcount][x] = '\0';
			++wcount;
			ccount = 0;
		} else {
			wordbuffer[ccount] = stringbuffer[n];
			++ccount;
		}
	}
}

INPUT *setstdinput(){
	INPUT *standard = (INPUT *)malloc(sizeof(INPUT));
	int wcount;
	char *stringbuffer;

	stringbuffer = (char *)malloc(sizeof(char) * STRINGBUFFERSIZE);

	get_stdinput(stringbuffer);

	wcount = wordcount(stringbuffer);
	standard->c = wcount;

	standard->v = (char **)malloc(sizeof(char *) * wcount);

	stringbuffer_to_inputv(stringbuffer, standard->v);

	free(stringbuffer);

	return standard;
}

void freeinputv(INPUT *standard){
	for (int n = 0; n < standard->c; ++n){
		free(standard->v[n]);
	}

	free(standard->v);
	free(&(standard->c));
	free(standard);
}
