#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void varNotIntFunction(char* varName, int* numRows, int* numCols){
		printf("The number of %s is not an integer.\n", varName);
		printf("Making default board of 10 X 10.\n");
}

/* This function should take in argv and argc for validating the input we get. If the 
input entered is valid, numRows and numCols are set to what the user inputted.
Otherwise, something else happens depending on the type of error. It's a bit of a mess,
but it should serve for now. */

bool commLineInputValidation(char **commLineInputs, int numArgs, int *numRows, int *numCols)
{
	// This function validates the input recieved in the command lines; 2 positive integers
	if (numArgs != 3)
	{
		printf("Wrong number of command line arguments entered.\n");
		printf("Usage: ./paint.out [num_rows num_cols]\n");
		printf("Making default board of 10 X 10.\n");
		*numRows = 10;
		*numCols = 10;
		return false;
	}
	// This else if case checks to make sure that the num rows entered is actually a positive int
	else if (atoi(commLineInputs[1]) <= 0) {
		if (atoi(commLineInputs[1]) < 0) {
			printf("The number of rows is less than 1.\n");
			printf("Making default board of 10 X 10.\n");
		}
		else {
			varNotIntFunction("rows", numRows, numCols);
		}
		*numRows = 10;
		*numCols = 10;
		return false;
	} 
	// This else if case checks the user's entry for columns to make sure that it's a positive integer
	else if (atoi(commLineInputs[2]) <= 0) {
			if (atoi(commLineInputs[2]) < 0) {
			printf("The number of columns is less than 1.\n");
			printf("Making default board of 10 X 10.\n");
		}	else {
		varNotIntFunction("columns", numRows, numCols);
		}
		*numRows = 10;
		*numCols = 10;
		return false;
	}
	return true;
}
