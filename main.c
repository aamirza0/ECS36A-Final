#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "board.h"
#include "inputHandling.h"


int main(int argc, char **argv) {
	// Take in the input from the command line and assign it to the variables for the canvas' dimensions, if valid. 
	int numRows = 0;
	int numCols = 0;
	int isInputValid = commLineInputValidation(argv, argc, &numRows, &numCols);
	if(isInputValid){
		numRows = atoi(argv[1]);
		numCols = atoi(argv[2]);
	}
	BoardStruct newBoard = makeBoard(numRows, numCols);
	setupBoard(newBoard);
	printBoard(newBoard);
  return 0;

}