#include "../header/patternList.h"

void createPatternList(patternList *ptl) {
    (*ptl).maxLength = 0;
    (*ptl).count = 1;
}

void readPatternListDimensionFromFile(FILE *fp, patternList *ptl, boolean *isSuccess) {
    char tempchar;
    int charCount;

    /* count the number of pattern and the max length */
    charCount = 0;
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

    /* allocate the buffer */
    (*ptl).list = (pattern *) malloc ((*ptl).count * sizeof(pattern));
    if ((*ptl).list != NULL) {
        for (int i = 0; i < (*ptl).count; i++) {
            (*ptl).list[i].buffer = (char *) malloc ((*ptl).maxLength * sizeof(char));
            if ((*ptl).list[i].buffer == NULL) {
                printf("List of pattern allocation failed.\n");
                *isSuccess = false;
                break;
            }
        }
        *isSuccess = true;
    } else {
        printf("List of pattern allocation failed.\n");
        *isSuccess = false;
    }
}

void readPatternListBufferFromFile(FILE *fp, patternList *ptl) {
    char tempchar;
    int i = 0;
    int j = 0;
    while ((tempchar = fgetc(fp)) != EOF) {
        (*ptl).list[i].buffer[j] = tempchar;
        if (tempchar == '\n') {
            (*ptl).list[i].buffer[j] = '\0';
            (*ptl).list[i].length = j;
            i++;
            j = 0;
        } else {
            j++;
        }
    } 
    (*ptl).list[i].buffer[j] = '\0';
    (*ptl).list[i].length = j;

    printf("%d Pattern(s) loaded successfully.\n", (*ptl).count);
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