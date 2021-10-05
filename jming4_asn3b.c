/*
CS2211a 2020
Assignment 03
Joshua Ming
251076262
jming4
October 17, 2020
 */
#include <stdio.h>

// You are prompted to enter a value. The value you enter is the number of outputs you will receive.
// the  output is greater than 0 iff the number inputer <numOutputs> is at least 2
// the total value is only increased when <adder> is assigned 1. Multiple of the same outputs will occur.
int main(){ 
	int total, divider, numOutputs, adder;
	while(1){
		total = 0;
		printf("Input? ");
		scanf("%d", &numOutputs);
		if (numOutputs == 0){
			break;
		}
		for (int e = 1; e <= numOutputs; e++){
			adder = 0;
			for (divider = 2; divider <= e; divider++)
				if (e % divider == 0)
					adder ++;
				if (adder == 1)
					total = total + e;
		printf("The final total is: %d\n", total);
		}
	}
	return 0;
}
