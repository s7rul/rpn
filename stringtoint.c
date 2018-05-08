/*
 * =====================================================================================
 *
 *       Filename:  stringtoint.c
 *
 *    Description:  inplementations for stringtoint.h
 *
 *       Compiler:  gcc
 *
 *         Author:  Erik Serrander
 *
 * =====================================================================================
 */

#include "stringtoint.h"

int mypow(int x, int y){
	int sum = 0;

	if (y == 1){
		sum = x;
	}

	else if (y == 0){
		sum = 1;
	}

	else if (y > 1){
		sum = x;
		for (int n = 1; n < y; n++){
			sum *= x;
		}
	}

	return sum;
}

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
