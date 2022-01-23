#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DR  "\x1b[31m"  // DARK RED
#define DG  "\x1b[32m"  // DARK GREEN
#define DY  "\x1b[33m"  // DARK YELLOW
#define DB  "\x1b[34m"  // DARK BLUE
#define DM  "\x1b[35m"  // DARK MAGENTA
#define DC  "\x1b[36m"  // DARK CYAN
#define BR  "\x1b[91m"  // BRIGHT RED
#define BG  "\x1b[92m"  // BRIGHT GREEN
#define BY  "\x1b[93m"  // BRIGHT YELLOW
#define BB  "\x1b[94m"  // BRIGHT BLUE
#define BM  "\x1b[95m"  // BRIGHT MAGENTA
#define BC  "\x1b[96m"  // BRIGHT CYAN
#define RE  "\x1b[0m"   // RESET

typedef struct
{
    char symbol;
    char color[3];  // WH = WHITE
} coloredChar;

typedef struct
{
    coloredChar **buffer;
    int row;
    int col;
} board;

void createBoard(board *brd);
void readBoardDimensionFromFile(FILE *fp, board *brd);
void readBoardBufferFromFile(FILE *fp, board *brd);
void printBoard(board brd);

#endif