#ifndef BOARD_H_
#define BOARD_H_
#include <string.h>
#include <stdbool.h>
  typedef struct Board_struct
{
  int numRows; 
  int numCols;
  char **canvas;
} BoardStruct;
	BoardStruct makeBoard(int numRows, int numCols);
	void setupBoard(BoardStruct inputBoard);
	void printBoard(BoardStruct inputBoard);
#endif