#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/board.h"
#include "../header/patternList.h"

int loadFile(char *filename, board *brd, patternList *ptl) {
    char path[500] = "test/";
    strcat(path, filename);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error. File Not Found.\n");
        printf("==================================================\n");
        return 0;
    } else {
        printf("%s opened.\n", filename);
    }

    createBoard(brd);
    readBoardDimensionFromFile(fp, brd);
    
    createPatternList(ptl);
    readPatternListDimensionFromFile(fp, ptl);

    rewind(fp);

    readBoardBufferFromFile(fp, brd);
    printf("Board %d x %d loaded successfully.\n", (*brd).row, (*brd).col);

    readPatternListBufferFromFile(fp, ptl);
    printf("%d Pattern(s) loaded successfully.\n", (*ptl).count);

    fclose(fp);
    printf("==================================================\n");
}