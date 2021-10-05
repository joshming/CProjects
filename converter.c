//CS2211a 2020
//Assignment 2
//Joshua Ming 
//251076262
//jming4
//October 4, 2020

#include <stdio.h>
#define DISTANCE_CONVERSION_L 0.621371
#define DISTANCE_CONVERSION_S 0.393701
#define LIQUID_CONVERSION 0.264172
float largeDistanceConversion(){
	char direction;
	float Km, M, result;
	do{
		printf("Please enter a 'K' if you wish to convert from Km to Miles, or an 'M' for the other way: ");
		scanf(" %c", &direction);

		if (direction == 'K'){ 
			printf("Please enter the number of kilometres you would like to convert: ");
			scanf("%f", &Km);
			result = Km * DISTANCE_CONVERSION_L;
			break; // exit this loop iteration and evaluate the continue while clause
		}
		if (direction == 'M'){
			printf("Please enter the number of miles you would like to convert: "); 
			scanf("%f", &M); 
			result = M / DISTANCE_CONVERSION_L; 
			break;
		}
		else 
			continue; 
	}while(direction != 'K' || direction != 'M'); //repeat the do while loop as long as K or M has not been inputted by the user

	if (direction == 'K'){
		printf("%f kilometre(s) is equivalent to %f mile(s). \n", Km, result);
	}
	else 
		printf("%f mile(s) is equivalent to %f kilometre(s). \n", M, result);

}

float liquidConversion(){
	char direction;
	float L, G, result;
	do{
		printf("Please enter a 'L' if you wish to convert from litres to gallons, or an 'G' for the other way: ");
		scanf(" %c", &direction);

		if (direction == 'L'){ 
			printf("Please enter the number of litres you would like to convert: ");
			scanf("%f", &L);
			result = L * LIQUID_CONVERSION;
			break;
		}
		if (direction == 'G'){
			printf("Please enter the number of gallons you would like to convert: "); 
			scanf("%f", &G); 
			result = G / LIQUID_CONVERSION; 
			break;
		}
		else 
			continue; 
	}while(direction != 'G' || direction != 'L'); //repeat the do while loop as long as G or L has not been inputted by the user

	if (direction == 'L'){
		printf("%f litre is equivalent to %f gallon. \n", L, result);
	}
	else 
		printf("%f gallons is equivalent to %f litre. \n", G, result);
}

float smallDistanceConversion(){
	char direction;
	float C, I, result;
	do{
		printf("Please enter a 'C' if you wish to convert from centimetres to inches, or an 'I' for the other way: ");
		scanf(" %c", &direction);

		if (direction == 'C'){ 
			printf("Please enter the number of centimetres you would like to convert: ");
			scanf("%f", &C);
			result = C * DISTANCE_CONVERSION_S;
			break;
		}
		if (direction == 'I'){
			printf("Please enter the number of inches you would like to convert: "); 
			scanf("%f", &I); 
			result = I / DISTANCE_CONVERSION_S; 
			break;
		}
		else 
			continue; 
	}while(direction != 'I' || direction != 'C'); //repeat the do while loop as long as C or M has not been inputted by the user

	if (direction == 'C'){
		printf("%f centimetre(s) is equivalent to %f inches. \n", C, result);
	}
	else 
		printf("%f inches is equivalent to %f centimetre(s). \n", I, result);
}

float temperatureConversion(){
	char direction;
	float C, F, result;
	do{
		printf("Please enter a 'C' if you wish to convert from Celsius to Fahrenheit, or an 'F' for the other way: ");
		scanf(" %c", &direction);

		if (direction == 'C'){ 
			printf("Please enter the temperature in Celsius you would like to convert: ");
			scanf("%f", &C);
			result = (C * 9/5) + 32;
			break;
		}
		if (direction == 'F'){
			printf("Please enter the temperature in Fahrenheit you would like to convert: "); 
			scanf("%f", &F); 
			result = (F - 32) * 5/9; 
			break;
		}
		else 
			continue; 
	}while(direction != 'C' || direction != 'F'); //repeat the do while loop as long as F or C has not been inputted by the user

	if (direction == 'C'){
		printf("%f Celsius is equivalent to %f Fahrenheit. \n", C, result);
	}
	else 
		printf("%f Fahrenheit is equivalent to %f Celsius. \n", F, result);
}


int main(){
	char c = '0';
	while(c != '5' && c != EOF){
		
		printf("Choose what you want to do:\n 1 for kilometres to miles\n 2 for litres to gallons\n 3 for centimetres to inches\n 4 for Celsius to Fahrenheit\n 5 to quit.\n Enter Number: ");
		scanf(" %c", &c);
		if (c == '1')
			largeDistanceConversion();
		else if (c == '2')
			liquidConversion();
		else if (c == '3')
			smallDistanceConversion();
		else if (c == '4') 
			temperatureConversion();
		else if (c == '5')
			return(0);
		else 
		      continue;
	
	}	
}
