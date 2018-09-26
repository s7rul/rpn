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

int is_number(char *charnumber){
	for (int i = 0; charnumber[i] != '\0'; i++){
		if (('0' <= charnumber[i] && charnumber[i] <= '9') || (charnumber[0] == '\0')){
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int string_to_int(char *charnumber){
	int ret = 0;
	int x = 0;
	char c = charnumber[0];

	if (is_number(charnumber)){
		for (int n = 0; 1 ; n++){
			c = charnumber[n];
			if (c == '\0'){
				break;
			}
			x = c - '0';
			ret = ret * 10 + x;
		}
		return ret;
	}
	return -1;
}
