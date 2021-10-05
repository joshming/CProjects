//CS2211a 2020
//Assignment 2
//Joshua Ming 
//251076262
//jming4
//October 4, 2020

#include <stdio.h>

float expCalc(float base, int exp){	
	if (exp == 0){
		return 1;
	}
	else
		if (exp >0) // deals with positive exponents
			if (exp % 2 == 1) // calculates the result if it is an odd exponent
				return  base * expCalc(base, (exp-1)/2) * expCalc(base, (exp-1)/2);
			else // otherwise calculate the result as an even exponent	
				return expCalc(base, exp/2) * expCalc(base, exp/2);
		else if (exp < 0) // deals with negative exponents; uses the reciprocal of the base as <base> parameter, and a positive exponent as the <exp> parameter
			if (exp % 2 == -1) 
				return base * expCalc(1.0/base, -1 * (exp-1)/2) * expCalc(1.0/base, -1 * (exp-1)/2);
			else
				return expCalc(1.0/base, -1 * exp/2) * expCalc(1.0/base, -1 * exp/2);
}

int main(){ 
	float base, value;
	int exp;
	do{
		printf("If you wish to exit, please enter 0. Otherwise, please input your base: ");
		scanf("%f", &base);
		if (base == 0.0f){ // check to see if the base is not 0
			return 0; // if it is zero, exit the program immediately
		}
		printf("Enter a value that you would like to raise the base to: ");
		scanf("%d", &exp);
		
		value = expCalc(base, exp);
		printf("%f raised to the %d is equal to %f. \n", base, exp, value);
	}while(1); // always continue
	
}


