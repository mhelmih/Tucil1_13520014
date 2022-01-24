/**
 * File: fileloader.c
 * 
 * Berisi prosedur untuk membaca file
 * kemudian menampung isinya ke dalam
 * ADT yang sudah dibuat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/boolean.h"
#include "../header/board.h"
#include "../header/patternList.h"

int loadFile(char *filename, board *brd, patternList *ptl) {
    char path[500] = "../test/";
    strcat(path, filename);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error. File Not Found.\n");
        printf("==================================================\n");
        return 0;
    } else {
        boolean boardSuccess, patternSuccess;

        printf("%s opened.\n", filename);
        createBoard(brd);
        readBoardDimensionFromFile(fp, brd, &boardSuccess);
        if (boardSuccess) {
            createPatternList(ptl);
            readPatternListDimensionFromFile(fp, ptl, &patternSuccess);
            if (patternSuccess) {
                rewind(fp);

                readBoardBufferFromFile(fp, brd);
                readPatternListBufferFromFile(fp, ptl);
            }
        }
        fclose(fp);
    }
    printf("==================================================\n");
}