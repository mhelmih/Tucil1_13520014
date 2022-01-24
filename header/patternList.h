#ifndef PATTERNLIST_H
#define PATTERNLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

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
void readPatternListDimensionFromFile(FILE *fp, patternList *ptl, boolean *isSuccess);
void readPatternListBufferFromFile(FILE *fp, patternList *ptl);
void printPatternList(patternList ptl);
void printPattern(pattern ptn);

#endif