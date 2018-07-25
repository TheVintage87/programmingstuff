/*
 * Functions.c
 *
 *  Created on: Jul 2, 2018
 *      Author: root
 */

#include "headerFile.h"
#define LIMIT 20

/*int Library_myFunc()
{
	printf("%s\n", "Hello World");
	return 0;
}*/

/*int menu(char **menuArr, int arrSize)
{

	int i = 0;

	printf("%d\n", arrSize);

	for(i=0; i < arrSize; i++)
	{
		printf("%s\n", menuArr[i]);
	}
	return 0;
}*/



//Gets user input using fgets and checks for errors
int userInput(char *userArr, int arrSize)
{
	userArr[arrSize] = '\0';

	if(fgets(userArr, arrSize + 3, stdin) == NULL)
	{
		printf("***error***%s\n", userArr);
		flushStdIn();
		return 1;
	}
	if(!(userArr[arrSize]  == '\n' || userArr[arrSize] == '\0'))
	{
		printf("***Input exceeds the allowed number of digits!***\n");
		flushStdIn();
		return 1;
	}
	printf("Your input: %s\n", userArr);
	flushStdIn();
	return 0;

}

//Flushes standard in 
void flushStdIn()
{
	char c = 0;
	//make stdin non-blocking
	int flags = fcntl(0, F_GETFL);
	fcntl (0, F_SETFL, O_NONBLOCK);

	//TODO - remove all characters from stdin
	
	while((c = getchar()) != EOF && c != '\n');

	//restore original flags
	fcntl (0, F_SETFL, flags);
}

/*int errorCheck()
{
	int i;
	char errArr[MAX];

	for(i = 0; i < MAX-2; i++)
	{
		b = ungetc('a', stdin);
	}

	printf("***Input is less than the buffer size***\n");
	userInput(errArr, MAX-2);

	for(i = 0; i < MAX+5; i++)
	{vv
		c = ungetc('a', stdin);
	}
	printf("***Input is more than the buffer size***\n");
	userInput(errArr, MAX+5);

	for(i = 0; i < MAX; i++)
	{
		d = ungetc('a', stdin);
	}
	printf("***Input is equal to the buffer size***\n");
	userInput(errArr, MAX+1);

	return 0;

}*/



/*
 * int convert: converts a given char* to a long
 * @param char* input: The user string to convert
 * @param/return long* userValue: the location to store converted value
 *
 * @return long * userValue: Returns an int representing error condition on the following:
 *     0- no error, normal return of long to userValue
 *     1- entered value too large, no change to userValue
 *     2-
 */

int convert(char *input, long *userValue)
{
	char *end = NULL;
	long int num = 0;

	num = strtol(input, &end, 10);
	
	if(*end != '\0' && *end != '\n')
	{
		return 1;
	}
	else if(errno == ERANGE)
	{
		errno = 0;
		return 1;
	}

	*userValue = num;
	return 0;
}

//Test Case function
int tester()
{
	int result = 0;
	long userValue = 0;
	char *input1 = "4"; //valid input, a number 1 - 5
	char *input2 = "1a"; //invalid input
	char *input3 = "9223372036854775807"; //Largest value
	char *input4 = "9223372036854775808"; //Largest value +1
	char *input5 = "-9223372036854775808"; //Smallest value
	char *input6 = "-9223372036854775809"; //Smallest value -1

	//Test for valid input
	result = convert(input1, &userValue);
	if(result == 0 && userValue == 4)
	{
		printf("Testing for VALID user input, Test is good\n");
	}
	else
	{
		printf("BAD: Invalid user input\n");
	}

	//Test for invalid input
	result = convert(input2, &userValue);
	if(result == 1)
	{
		printf("Testing for INVALID user input, Test is good\n");
	}
	else
	{
		printf("Check for invalid input is NOT GOOD\n");
	}
	//Test for largest possible input
	result = convert(input3, &userValue);
	if(result == 0 && userValue == 9223372036854775807)
	{
		printf("Testing for largest user input, Test is good\n");
	}
	else
	{
		printf("BAD: Not the largest user input\n");
	}
	//Test for largest possible input +1
	result = convert(input4, &userValue);
	if(result == 1)
	{
		printf("Testing for largest user input +1, Test is good\n");
	}
	else
	{
		printf("BAD: Does not exceed largest user input by 1\n");
	}
	//Test for smallest possible input
	result = convert(input5, &userValue);
	if(result == 0 && userValue == LONG_MIN)
	{
		printf("Testing for smallest user input, Test is good\n");
	}
	else
	{
		printf("%d\n", result);
		printf("%ld\n",	userValue);
		printf("BAD: Not the smallest user input\n");
	}
	//Test for smallest possible input -1
	result = convert(input6, &userValue);
	if(result == 1)
	{
		printf("Testing for smallest user input -1, Test is good\n");
	}
	else
	{
		printf("BAD: Does not exceed smallest user input by -1\n");
	}
	return 0;
}

//Gets positive whole number with checks to make sure there are no decimals or zero
int get_pos_int()
{
	char Input1[LIMIT_MAX] = {0};
	long pos_num = 0;
	


	while(1)
	{
		if(userInput(Input1, 2))
		{
			printf("***Not a valid integer!***\n");
			continue;
		}
		if(convert(Input1, &pos_num))
		{
			printf("***negative ghost rider try again***\n");
			continue;
		}
		if(pos_num < 1)
		{
			printf("***Cannot have a negative number or zero try again***\n");
			continue;
		}	
			break;
	}
	return pos_num;
}

//Allows user to save results from Area of a circle function to a text file
void saveArea_to_file(double area)
{
	FILE *fp;
	int save = 0;

	printf("Do you want to save your results? \n");
	printf("'1' for YES, '2' for NO\n");
	
	while(1)
	{	
		save = get_pos_int();
		if(save == 1)
		{
			fp = fopen("/root/Desktop/savedResults.txt", "a+");
			if(fp == NULL)
			{
				printf("File could not be opened\n");
			}
			else
			{
				fprintf(fp,"Area results: %f\n", area);
				if(fclose(fp) == EOF)
				{
					printf("File could not be closed\n");
				}
			}
		}	
		else if(save == 2)
		{
			break;
		}
		else
		{
			printf("You did not pick '1' or '2' Please choose again\n");
			continue;
		}

		break;
	}
		
}

//Allows user to save results from volume of a cube function to a text file
void saveVol_to_file(int volume)
{
	FILE *fp;
	int save = 0;

	printf("Do you want to save your results? \n");
	printf("'1' for YES, '2' for NO\n");
	
	while(1)
	{	
		save = get_pos_int();
		if(save == 1)
		{
			fp = fopen("/root/Desktop/savedResults.txt", "a+");
			if(fp == NULL)
			{
				printf("File could not be opened\n");
			}
			else
			{
				fprintf(fp,"Volume results: %d\n", volume);
				if(fclose(fp) == EOF)
				{
					printf("File could not be closed\n");
				}
			}
		}	
		else if(save == 2)
		{
			break;
		}
		else
		{
			printf("You did not pick '1' or '2' Please choose again\n");
			continue;
		}
		break;
	}
		
}

//Gets a number then checks to see if its less than fifteen digits and greater than zero
double get_num()
{
	char Input1[LIMIT] = {0};
	double pos_num = 0;
	

	while(1)
	{
		if(userInput(Input1, 20))
		{
			printf("***Not a valid integer!***\n");
			continue;
		}
		if(string_to_num(Input1, &pos_num))
		{
			printf("***negative ghost rider try again***\n");
			continue;
		}
		if(pos_num <= 0)
		{
			printf("***Cannot have a negative number or zero try again***\n");
			continue;
		}	
			break;
	}
	return pos_num;
}

//Converts string to double used by currency converter, vol of cube and area of a circle which are functions that can have a decimal.
int string_to_num(char *input, double *userValue)
{
	char *end = NULL;
	double num = 0;

	num = strtod(input, &end);
	
	if(*end != '\0' && *end != '\n')
	{
		return 1;
	}
	else if(errno == ERANGE)
	{
		errno = 0;
		return 1;
	}

	*userValue = num;
	return 0;
}

