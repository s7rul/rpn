/*this file contains all the basic math functions*/

#include <stdio.h>

int add(int x, int y){
	return x + y;
}

int sub(int x, int y){
	return x - y;
}

int mult(int x, int y){
	return x * y;
}

int div(int x, int y){
	return x / y;
}

int pow(int x, int y){
	int sum = 0;

	if (y == 1){
		return x;
	}

	if (y == 0){
		return 1;
	}

	for (int n = 1; n < y; n++){
		sum = sum * x;
	}

	return sum;
}
