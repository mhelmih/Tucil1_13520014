#include <stdio.h>
#include "../header/patternList.h"

void createPatternList(patternList *ptl) {
    (*ptl).maxLength = 0;
    (*ptl).count = 1;
}

void readPatternListDimensionFromFile(FILE *fp, patternList *ptl) {
    char tempchar;
    int charCount = 0;
    while ((tempchar = fgetc(fp)) != EOF) {
        if (tempchar == '\n' && charCount > (*ptl).maxLength) {
            (*ptl).maxLength = charCount;
        }
        if (tempchar == '\n') {
            charCount = 1;
            (*ptl).count++;
        } else {
            charCount++;
        }
    }
    printf("patternCount: %d\n", (*ptl).count);
    printf("maxPatternSize: %d (udah sama \\n)\n", (*ptl).maxLength);

    (*ptl).list = (pattern *) malloc ((*ptl).count * sizeof(pattern));
    for (int i = 0; i < (*ptl).count; i++) {
        (*ptl).list[i].buffer = (char *) malloc ((*ptl).maxLength * sizeof(char));
    }
}

void readPatternListBufferFromFile(FILE *fp, patternList *ptl) {
    char tempchar;
    int i = 0;
    int j = 0;
    while ((tempchar = fgetc(fp)) != EOF) {
        (*ptl).list[i].buffer[j] = tempchar;
        j++;
        if (tempchar == '\n') {
            (*ptl).list[i].length = j - 1;
            i++;
            j = 0;
        }
    } 
    (*ptl).list[i].buffer[j] = '\n';
    (*ptl).list[i].length = j - 1;
}

void printPatternList(patternList ptl) {
    for (int i = 0; i < ptl.count; i++) {
        for (int j = 0; j < ptl.maxLength; j++) {
            printf("%c", ptl.list[i].buffer[j]);
            if (ptl.list[i].buffer[j] == '\n') {
                printf("length: %d\n", ptl.list[i].length);
                break;
            }
        }
    }
}