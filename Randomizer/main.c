/*
 * Main.c
 *
 *  Created on: May 21, 2018
 *      Author: CTN2 Swett
 */
#include "main.h"

int main()
{
	char input1[5];
	do
	{
		menu(); //display menu options
		fgets(input1, SIZE, stdin);
		flushStdIn();
		printf("You picked option: %s\n", input1);
		
		//menu selection by user will take them to the chosen function
		if(!strncmp(input1, "1\n", 3))
		{
			dice();
		}	
		else if(!strncmp(input1, "2\n", 3))
		{	
			area_circle();
		}	
		else if(!strncmp(input1, "3\n", 2))
		{
			vol_of_cube();
		}
		else if(!strncmp(input1, "4\n", 3)) 
		{	
			unique_func();
		}
		else if(!strncmp(input1, "5\n", 2))
		{
			quit_message();
			break;
		}			
		else
		{
			printf("***Invalid option! Pick from options 1-5***\n");
		}
	}
	while(1);
	
	return 0;
}
//Displays menu 
void menu()
{
	printf("\n-------------------MENU----------------------\n");
	printf("Enter 1 for dice roller \n");
	printf("Enter 2 to compute area of a circle \n");
	printf("Enter 3 to compute volume of a cube \n");
	printf("Enter 4 for currency converter \n");
	printf("Enter 5 to quit program\n");

}
//Get user input for num sides, num rolls, num dice for Dice roller randomizer
void dice()
{
	
	int i = 0;
	int j = 0;
	long numSides = 0;
	long numDice = 0;
	long numRolls = 0;
	
	printf("----------------\n");
	printf("- Dicer Roller -\n");
	printf("----------------\n");

	//Get user input for number of sides for the dice
	printf("Enter the number of sides for your dice:\n");
	numSides = get_pos_int();
	
	//Get user input for the number of dice
	printf("Enter the number of dice:\n");
	numDice = get_pos_int();
	
	//Get user input for the number of rolls
	printf("Enter the number of rolls:\n");
	numRolls = get_pos_int();
	
	srand(time(NULL));
	for(i=1; i<=numRolls; ++i)
	{
		for(j=1; j<=numDice; j++)
		{
			printf("roll:%d  dice:%d  value:%ld \n", i, j, rand() % numSides+1);
		}
	}
}

//Gets user input for the radius to then calculate the area of a circle
void area_circle()
{
	double radius = 0;
	double area = 0;
	const float pi = 3.141593;

	printf("-------------------- \n");
	printf("- Area of a Circle - \n");
	printf("-------------------- \n");

	//Get user input for radius
	printf("Enter a number for the radius of your circle: \n");
	radius = get_num();

	//Calculate area
	area = pi * radius * radius;
	printf("The area of your circle is: %lf\n\n", area);
	
	//save above results
	saveArea_to_file(area);
}

//Gets user input for the edge length to then calculate the volume of a cube
void vol_of_cube()
{
	double edge = 0;
	double volume = 0;

	printf("-------------------- \n");
	printf("- Volume of a Cube - \n");
	printf("-------------------- \n");
	
	//Get user input for the edge length
	printf("Enter the length of the cube edge: \n");
	edge = get_num();
	
	//Calculate the volume of a cube
	volume = edge * edge * edge;
	printf("The volume of your cube is: %lf\n\n", volume);

	//Save above results
	saveVol_to_file(volume);
}

//This is my unique function which calculates USD to various other currencies
void unique_func()
{	
	const float CAD = 1.32;
	const float EUR = 0.86;
	const float GBP = 0.76;
	const float CYN = 6.71;
	float user_dollar_amount = 0;

	printf("---------------------- \n");
	printf("- Currency Converter - \n");
	printf("---------------------- \n");
	
	//Get user input for US dollar amount
	printf("Enter the amount of USD to convert: \n");
	user_dollar_amount = get_num();

	//Convert USD amount
	printf("USD to CAD: %.2lf\n", user_dollar_amount * CAD);
	printf("USD to EUR: %.2lf\n", user_dollar_amount * EUR);
	printf("USD to GBP: %.2lf\n", user_dollar_amount * GBP);
	printf("USD to CYN: %.2lf\n", user_dollar_amount * CYN);

}

//This is the message that prints when the user decides to exit the program
int quit_message()
{
	printf("-------------------- \n");
	printf("- Quitting Program - \n");
	printf("-------------------- \n");
	return 0;
}
