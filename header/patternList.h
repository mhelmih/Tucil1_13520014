#ifndef PATTERNLIST_H
#define PATTERNLIST_H

#include <stdlib.h>

typedef struct
{
    char *buffer;
    int length;
} pattern;

typedef struct
{
    int count;
    int maxLength;
    pattern *list;
} patternList;

void createPatternList(patternList *ptl);
void readPatternListDimensionFromFile(FILE *fp, patternList *ptl);
void readPatternListBufferFromFile(FILE *fp, patternList *ptl);
void printPatternList(patternList ptl);

#endif