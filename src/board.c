#include <stdio.h>
#include "../header/board.h"

void createBoard(board *brd) {
    (*brd).col = 0;
    (*brd).row = 1;
}

void readBoardDimensionFromFile(FILE *fp, board *brd) {
    char tempchar;
    while (tempchar != '\n') {
        fscanf(fp, "%c", &tempchar);
        if (tempchar != ' ' && tempchar != '\n') {
            (*brd).col++;
        }
    }
    printf("kolom array: %d\n", (*brd).col);

    char str[500];
    while (*fgets(str, sizeof(str), fp) != '\n') {
        (*brd).row++;
    }
    printf("baris array: %d\n", (*brd).row);

    (*brd).buffer = (char **) malloc ((*brd).row * sizeof(char*));
    for (int i = 0; i < (*brd).row; i++) {
        (*brd).buffer[i] = (char *) malloc ((*brd).col * sizeof(char));
    }
}

void readBoardBufferFromFile(FILE *fp, board *brd) {
    char tempchar;

    for (int i = 0; i < (*brd).row; i++) {
        for (int j = 0; j < (*brd).col; j++) {
            fscanf(fp, " %c", &brd->buffer[i][j]);
        }
    }

    fscanf(fp, "%c", &tempchar);
    fscanf(fp, "%c", &tempchar);
}

void printBoard(board brd) {
    for (int i = 0; i < brd.row; i++) {
        for (int j = 0; j < brd.col; j++) {
            printf("%c ", brd.buffer[i][j]);
        }
        printf("\n");
    }
}