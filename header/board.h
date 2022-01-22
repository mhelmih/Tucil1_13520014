#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>

typedef struct
{
    char **buffer;
    int row;
    int col;
} board;

void createBoard(board *brd);
void readBoardDimensionFromFile(FILE *fp, board *brd);
void readBoardBufferFromFile(FILE *fp, board *brd);
void printBoard(board brd);

#endif