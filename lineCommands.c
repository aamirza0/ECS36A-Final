#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "board.h"

// Have function heaers here:
void quitProgram(BoardStruct currBoard);
void print_help();
void topRightWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol);
void topLeftWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol);
void bottomLeftWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol);
void bottomRightWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol);

void writeLine(BoardStruct currBoard, int startRow, int startColumn, int endRow, int endColumn);

void quitProgram(BoardStruct currBoard)
{
	free(currBoard.canvas);
	exit(0);
}

void print_help()
{

	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
}

// If the startRow < endRow && startCol < endCol, print a '/'. This code writes ascending to the top right of the canvas
void topRightWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol)
{
	int currRowIndex = startRow;
	int currColIndex = startCol;
	int endRowIndex = endRow + 1;
	int endColIndex = endCol + 1;
	while (currRowIndex < endRowIndex && currColIndex < endColIndex)
	{
		if (currBoard.canvas[currRowIndex][currColIndex] != '/')
		{
			if (currBoard.canvas[currRowIndex][currColIndex] != '*')
			{
				currBoard.canvas[currRowIndex][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][currColIndex] = '/';
			}
		}
		currRowIndex++;
		currColIndex++;
	}
}

//If the endpoint is to the top left of the endpoint, (startRow < endRow, startCol > endCol), This function writes to the top left
void topLeftWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol)
{
	int currRowIndex = startRow;
	int currColIndex = startCol;
	int endRowIndex = endRow;
	int endColIndex = endCol;
	while (currRowIndex < endRowIndex + 1 && currColIndex > endColIndex - 1)
	{
		if (currBoard.canvas[currRowIndex][currColIndex] != '\\')
		{
			if (currBoard.canvas[currRowIndex][currColIndex] != '*')
			{
				currBoard.canvas[currRowIndex][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][currColIndex] = '\\';
			}
		}
		currRowIndex++;
		currColIndex--;
	}
}

void bottomLeftWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol)
{
	int currRowIndex = startRow;
	int currColIndex = startCol;
	int endRowIndex = endRow;
	int endColIndex = endCol;
	while (currRowIndex >= endRowIndex && currColIndex >= endColIndex)
	{
		if (currBoard.canvas[currRowIndex][currColIndex] != '/')
		{
			if (currBoard.canvas[currRowIndex][currColIndex] != '*')
			{
				currBoard.canvas[currRowIndex][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][currColIndex] = '/';
			}
		}
		currRowIndex--;
		currColIndex--;
	}
}

//Now, if the end coordinate is to the bottom right of the start point(startRow < endRow, startCol < endCol)
void bottomRightWriter(BoardStruct currBoard, int startRow, int startCol, int endRow, int endCol)
{
	int currRowIndex = startRow;
	int currColIndex = startCol;
	int endRowIndex = endRow;
	int endColIndex = endCol + 1;
	while (currRowIndex >= endRowIndex && currColIndex < endColIndex)
	{
		if (currBoard.canvas[currRowIndex][currColIndex] != '\\')
		{
			if (currBoard.canvas[currRowIndex][currColIndex] != '*')
			{
				currBoard.canvas[currRowIndex][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][currColIndex] = '\\';
			}
		}
		currRowIndex--;
		currColIndex++;
	}
}

void rightWriter(BoardStruct currBoard, int startCol, int endCol, int rowPosition)
{
	int currColIndex = startCol;
	int endColIndex = endCol;
	while (currColIndex <= endColIndex)
	{
		if (currBoard.canvas[rowPosition][currColIndex] != '-')
		{
			if (currBoard.canvas[rowPosition][currColIndex] != '*')
			{
				currBoard.canvas[rowPosition][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[rowPosition][currColIndex] = '-';
			}
		}
			currColIndex++;
	}
}

void leftWriter(BoardStruct currBoard, int startCol, int endCol, int rowPosition)
{
	int currColIndex = startCol;
	int endColIndex = endCol;
	while (currColIndex >= endColIndex)
	{
		if (currBoard.canvas[rowPosition][currColIndex] != '-')
		{
			if (currBoard.canvas[rowPosition][currColIndex] != '*')
			{
				currBoard.canvas[rowPosition][currColIndex] = '+';
			}
			else
			{
				currBoard.canvas[rowPosition][currColIndex] = '-';
			}
		}
		currColIndex--;
	}
}

void downWriter(BoardStruct currBoard, int startRow, int endRow, int colPosition)
{
	int currRowIndex = startRow;
	int endRowIndex = endRow;
	int colPos = colPosition;
	while (currRowIndex >= endRowIndex)
	{
		if (currBoard.canvas[currRowIndex][colPos] != '|')
		{
			if (currBoard.canvas[currRowIndex][colPos] != '*')
			{
				currBoard.canvas[currRowIndex][colPos] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][colPos] = '|';
			}
		}
			currRowIndex--;
	}
}

void upWriter(BoardStruct currBoard, int startRow, int endRow, int colPosition)
{
	int currRowIndex = startRow;
	int endRowIndex = endRow;
	int colPos = colPosition;
	while (currRowIndex <= endRowIndex)
	{
		if (currBoard.canvas[currRowIndex][colPos] != '|')
		{
			if (currBoard.canvas[currRowIndex][colPos] != '*')
			{
				currBoard.canvas[currRowIndex][colPos] = '+';
			}
			else
			{
				currBoard.canvas[currRowIndex][colPos] = '|';
			}
		}
		currRowIndex++;
	}
}


void writeLine(BoardStruct currBoard, int startRow, int startColumn, int endRow, int endCol)
{
	// Declare the necessary variables here: we need to start at the first two coordinates, and end at 1+ the last two.
	
	// If the end coordinates are to the top right, we need to print a '/'
	if (startRow < endRow && startColumn < endCol)
	{
		topRightWriter(currBoard, startRow, startColumn, endRow, endCol);
	}
// Otherwise, if the end coordinates are to the top left of the starting coordinates, print a '\'
	else if (startRow < endRow && startColumn > endCol)
	{
		topLeftWriter(currBoard, startRow, startColumn, endRow, endCol);
	}
// Now define what happens if the end coords are to the bottom left of the starting coordintes
	else if (startRow > endRow && startColumn > endCol)
	{
		bottomLeftWriter(currBoard, startRow, startColumn, endRow, endCol);
	}
	//Define what happens if the end coords are to the top right of the start coords
	else if (startRow > endRow && startColumn < endCol)
	{
		bottomRightWriter(currBoard, startRow, startColumn, endRow, endCol);
	}
// 	// What if the two coords are in the same column, but in different rows?
	else if(startRow != endRow && startColumn == endCol){
		if(startRow < endRow){
			upWriter(currBoard, startRow, endRow, endCol);
		}
		else{
			downWriter(currBoard, startRow, endRow, endCol);
		}
	}
  // What if the two coords are in the same row, but different columns?
	else if(startRow == endRow && startColumn != endCol){
		if (startColumn < endCol){
			rightWriter(currBoard, startColumn, endCol, endRow);
		}
		else{
 		leftWriter(currBoard, startColumn, endCol, endRow);
		}
 }
}