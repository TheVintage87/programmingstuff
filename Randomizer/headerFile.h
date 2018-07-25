/*
 * headerFile.h
 *
 *  Created on: Jul 2, 2018
 *      Author: root
 */

#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#define stuffSize 5
#define uInputSize 10
#define MAX 10
#define LIMIT_MAX 20
#define numSize 10

int Library_myFunc();
//int menu(char **menuArr, int arrSize);
int userInput(char *userArr, int arrSize);
void flushStdIn();
int errorCheck();
int convert(char *input, long *userValue);
int tester();
int string_to_num(char *input, double *userValue);

#endif /* HEADERFILE_H_ */
