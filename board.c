#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//This is gonna hold all of the board-based functions; it'll be responsible for printing and such

typedef struct Board_struct
{
    int numRows;
    int numCols;
    char **canvas;
} BoardStruct;

// This function initializes a Board struct and uses the 
BoardStruct makeBoard(int numRows, int numCols)
{
    BoardStruct newBoard;
    newBoard.numRows = numRows;
    newBoard.numCols = numCols;
    newBoard.canvas = (char **)malloc(numRows * sizeof(*newBoard.canvas));
    for (int rows = 0; rows < numRows; rows++)
    {
        newBoard.canvas[rows] = (char *)malloc(numCols * sizeof(*newBoard.canvas[rows]));
    }
    return newBoard;
}

// This function actually fills in the canvas within a board with asterisks. If you want, I can combine this with the makeBoard method. 
void setupBoard(BoardStruct inputBoard)
{
    int numRows = inputBoard.numRows;
    int numCols = inputBoard.numCols;
    for (int rows = 0; rows < numRows; ++rows)
    {
        for (int cols = 0; cols < numCols; ++cols)
        {
            inputBoard.canvas[rows][cols] = '*';
        }
    }
	inputBoard.canvas[0][0] = 'A';
}

// This function should take care of printing out the matrix contained within the board struct. 
void printBoard(BoardStruct inputBoard)
{
	int rowDimension = inputBoard.numRows;
	int colDimension = inputBoard.numCols;

  for (int row = rowDimension-1; row >= 0; row--)
  {
		printf("%d ", row);
    for (int col = 0; col < colDimension; col++)
    {
      printf("%c ", inputBoard.canvas[row][col]);
    }
    printf("\n");
  }
  printf("  ");
	for (int i = colDimension; i > 0; i--)
	{
		printf("%d ", colDimension- i);
	}
  printf("\n");
}