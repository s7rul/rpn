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

int is_number(char *string){
	for (int i = 0; string[i] != '\0'; i++){
		if (0 <= char_to_int(string[i]) <= 9){
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int string_to_int(char *string){
	int ret = 0;
	int x = 0;
	char c = string[0];

	if (is_number(string)){
		for (int n = 0; 1 ; n++){
			c = string[n];
			if (c == '\0'){
				break;
			}
			printf("c före %d\n", c);
			x = c - '0';
			printf("x %d\n", x);
			ret = ret * 10 + x;
			printf("ret: %d\n", ret);
		}
		return ret;
	}
	return -1;
}
