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
    // printf("patternCount: %d\n", (*ptl).count);
    // printf("maxPatternSize: %d (udah sama \\n)\n", (*ptl).maxLength);

    (*ptl).list = (pattern *) malloc ((*ptl).count * sizeof(pattern));
    if ((*ptl).list != NULL) {
        for (int i = 0; i < (*ptl).count; i++) {
            (*ptl).list[i].buffer = (char *) malloc ((*ptl).maxLength * sizeof(char));
            if ((*ptl).list[i].buffer == NULL) {
                printf("Gagal alokasi pattern list.\n");
                break;
            }
        }
    } else {
        printf("Gagal alokasi pattern list.\n");
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
            (*ptl).list[i].buffer[j-1] = '\0';
            (*ptl).list[i].length = j - 1;
            i++;
            j = 0;
        }
    } 
    (*ptl).list[i].buffer[j] = '\0';
    (*ptl).list[i].length = j;
}

void printPatternList(patternList ptl) {
    for (int i = 0; i < ptl.count; i++) {
        printf("%s\n", ptl.list[i].buffer);
    }
}

void printPattern(pattern ptn) {
    for (int i = 0; i < ptn.length; i++) {
        printf("%c", ptn.buffer[i]);
    }
}