#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.c"
#include "patternList.c"


int readFile(char *filename, board *brd, patternList *ptl) {
    char path[500] = "test/";
    strcat(path, filename);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error. File Not Found.\n");
        return 0;
    }

    createBoard(brd);
    readBoardDimensionFromFile(fp, brd);
    
    createPatternList(ptl);
    readPatternListDimensionFromFile(fp, ptl);

    rewind(fp);

    readBoardBufferFromFile(fp, brd);
    printBoard(*brd);

    readPatternListBufferFromFile(fp, ptl);
    printPatternList(*ptl);
}