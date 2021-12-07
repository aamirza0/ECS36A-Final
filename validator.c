#include "validator.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "commands.h"

bool isValidInput(int numArgs, char** args) {
    int numRows = 0, numCols = 0;
    sscanf(args[1], "%d", &numRows);
    sscanf(args[2], "%d", &numCols);
    if (numArgs != 3) {
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        return false;
    } else if (!isdigit(args[1][0]) && !isdigit(args[1][1])) {
        if (!isdigit(args[1][1])) {
            printf("The number of rows is not an integer.\n");
            printf("Making default board of 10 X 10.\n");
        }
        return false;
    } else if (!isdigit(args[2][0]) && !isdigit(args[ 2][1])) {
        if (!isdigit(args[2][1])) {
            printf("The number of columns is not an integer.\n");
            printf("Making default board of 10 X 10.\n");
        }
        return false;
    } else if (numRows < 1) {
        printf("The number of rows is less than 1.\n");
        printf("Making default board of 10 X 10.\n");
        return false;
    } else if (numCols < 1) {
        printf("The number of columns is less than 1.\n");
        printf("Making default board of 10 X 10.\n");
        return false;
    }
    return true;
}

bool isValidCommand(Board* board) {
    char command = (*board).command[0];
    int numArgsRead = (*board).numArgsRead;
    int numRows = (*board).numRows - 1;
    int numCols = (*board).numCols - 1;
    char c1, c2;
    char* filename = (char*)malloc(sizeof(char));
    int num1, num2, num3, num4;
    FILE* fp = NULL;
    if (command == 'q') {
        if (numArgsRead != 1) {
            printf("Unrecognized command. Type h for help.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'h') {
        if (numArgsRead != 1) {
            printf("Unrecognized command. Type h for help.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'w') {
        sscanf((*board).command, "%c %d %d %d %d", &c1, &num1, &num2, &num3, &num4);
        if (numArgsRead != 5) {
            printf("Improper draw command.\n");
            free(filename);
            return false;
        } else if ((num1 < 0 || num2 < 0 || num3 < 0 || num4 < 0) || (num1 > numRows || num2 > numCols || num3 > numRows || num4 > numCols)) {
            printf("Improper draw command.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'e') {
        sscanf((*board).command, "%c %d %d", &c1, &num1, &num2);
        if (numArgsRead != 3) {
            printf("Improper erase command.\n");
            free(filename);
            return false;
        } else if ((num1 < 0 || num2 < 0) || (num1 > numRows || num2 > numCols)) {
            printf("Improper erase command.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'r') {
        sscanf((*board).command, "%c %d %d", &c1, &num1, &num2);
        if (numArgsRead != 3) {
            printf("Improper resize command.\n");
            free(filename);
            return false;
        } else if (num1 < 1 || num2 < 1) {
            printf("Improper resize command.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'a') {
        sscanf((*board).command, "%c %c %d", &c1, &c2, &num1);
        if (numArgsRead != 3) {
            printf("Improper add command.\n");
            free(filename);
            return false;
        } else if (c2 != 'r' && c2 != 'c') {
            printf("Improper add command.\n");
            free(filename);
            return false;
        } else if (c2 == 'r' && (num1 > (numRows + 1) || num1 < 0)) {
            printf("Improper add command.\n");
            free(filename);
            return false;
        } else if (c2 == 'c' && (num1 > (numCols + 1) || num1 < 0)) {
            printf("Improper add command.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 'd') {
        sscanf((*board).command, "%c %c %d", &c1, &c2, &num1);
        if (numArgsRead != 3) {
            printf("Improper delete command.\n");
            free(filename);
            return false;
        } else if (c2 != 'r' && c2 != 'c') {
            printf("Improper delete command.\n");
            free(filename);
            return false;
        } else if (c2 == 'r' && (num1 > numRows || num1 < 0)) {
            printf("Improper delete command.\n");
            free(filename);
            return false;
        } else if (c2 == 'c' && (num1 > numCols || num1 < 0)) {
            printf("Improper delete command.\n");
            free(filename);
            return false;
        }
        free(filename);
        return true;
    } else if (command == 's') {
        sscanf((*board).command, "%c %s", &c1, filename);
        if (numArgsRead != 2) {
            printf("Improper save command.\n");
            free(filename);
            return false;
        }
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Failed to open file: %s\n", filename);
            free(filename);
            return false;
        }
        fclose(fp);
        free(filename);
        return true;
    } else if (command == 'l') {
        sscanf((*board).command, "%c %s", &c1, filename);
        if (numArgsRead != 2) {
            printf("Improper load command.\n");
            free(filename);
            return false;
        }
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Failed to open file: %s\n", filename);
            free(filename);
            return false;
        }
        fclose(fp);
        free(filename);
        return true;
    }
    free(filename);
    printf("Unrecognized command. Type h for help.\n");
    return false;
}

void runCommand(Board* board) {
    char command = (*board).command[0];
    if (command == 'q') {
        quitProgram(board);
    } else if (command == 'h') {
        print_help();
    } else if (command == 'w') {
        char c;
        int startRow, startCol, endRow, endCol;
        sscanf((*board).command, "%c %d %d %d %d", &c, &startRow, &startCol, &endRow, &endCol);
        writeToCanvas(board, startRow, startCol, endRow, endCol);
    } else if (command == 'e') {
        char c;
        int row, col;
        sscanf((*board).command, "%c %d %d", &c, &row, &col);
        erase(board, row, col);
    } else if (command == 'r') {
        char c;
        int numRows, numCols;
        sscanf((*board).command, "%c %d %d", &c, &numRows, &numCols);
        resize(board, numRows, numCols);
    } else if (command == 'a') {
        char c1, c2;
        int position;
        sscanf((*board).command, "%c %c %d", &c1, &c2, &position);
        addPosition(board, c2, position);
    } else if (command == 'd') {
        char c1, c2;
        int position;
        sscanf((*board).command, "%c %c %d", &c1, &c2, &position);
        deletePosition(board, c2, position);
    } else if (command == 's') {
        char c1;
        char* filename = (char*)malloc(sizeof(char));
        sscanf((*board).command, "%c %s", &c1, filename);
        FILE* fp = fopen(filename, "w");
        saveFile(fp, board);
        fclose(fp);
    } else if (command == 'l') {
        char c1;
        char* filename = (char*)malloc(sizeof(char));
        sscanf((*board).command, "%c %s", &c1, filename);
        FILE* fp = fopen(filename, "r");
        loadFile(fp, board);
        fclose(fp);
    }
}