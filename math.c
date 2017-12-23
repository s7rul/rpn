/*this file contains all the basic math functions*/

#include <stdio.h>

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
