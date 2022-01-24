#include <stdio.h>
#include <stdlib.h>
#include "../header/boolean.h"
#include "../header/board.h"
#include "../header/patternList.h"

void addColor(board *brd, int patternLength, int row, int col, int color, int mode) {
    int i, rowDirection, colDirection;
    int horizontal[] = { 1, 0, 1,  1 };
    int vertical[]   = { 0, 1, 1, -1 };

    rowDirection = row;
    colDirection = col;
    for (i = 0; i < patternLength; i++) {
        strcpy((*brd).buffer[rowDirection][colDirection].color, colors[color]);

        rowDirection += vertical[mode];
        colDirection += horizontal[mode];
    }
}

void solveHorizontally(board brd, pattern ptn, boolean *found, int *count, int color) {
    int col;
    int row;
    int patternIdx;
    
    row = 0;
    *found = false;
    while (row < brd.row && !*found) {
        ptn.length = ptn.length;
        col = 0;
        while (col <= brd.col - ptn.length && !*found) {
            patternIdx = 0;
            if (ptn.buffer[patternIdx] != brd.buffer[row][col+patternIdx].symbol) {
                *count += 1;
            }
            while (patternIdx < ptn.length && ptn.buffer[patternIdx] == brd.buffer[row][col+patternIdx].symbol) {
                patternIdx += 1;
                *count += 1;
            }

            if (patternIdx == ptn.length) {
                *found = true;
                addColor(&brd, ptn.length, row, col, color, 1);
            } else {
                col++;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solveVertically(board brd, pattern ptn, boolean *found, int *count, int color) {
    int col;
    int row;
    int patternIdx;

    col = 0;
    *found = false;
    while (col < brd.col && !*found) {
        row = 0;
        while (row <= brd.row - ptn.length && !*found) {
            patternIdx = 0;

            if (ptn.buffer[patternIdx] != brd.buffer[row+patternIdx][col].symbol) {
                *count += 1;
            }
            while (patternIdx < ptn.length && ptn.buffer[patternIdx] == brd.buffer[row+patternIdx][col].symbol) {
                patternIdx += 1;
                *count += 1;
            }

            if (patternIdx == ptn.length) {
                *found = true;
                addColor(&brd, ptn.length, row, col, color, 2);
            } else {
                row += 1;
            }
        }

        if (!*found) {
            col++;
        }
    }
}

void solveDiagonallyLeft2Bottom(board brd, pattern ptn, boolean *found, int *count, int color) {
    int col;
    int row;
    int patternIdx;

    row = 0;
    ptn.length = ptn.length;
    *found = false;
    while (row <= brd.row - ptn.length && !*found) {
        col = 0;
        while (col <= brd.col - ptn.length && !*found) {
            patternIdx = 0;
            if (ptn.buffer[patternIdx] != brd.buffer[row+patternIdx][col+patternIdx].symbol) {
                *count += 1;
            }
            while (patternIdx < ptn.length && ptn.buffer[patternIdx] == brd.buffer[row+patternIdx][col+patternIdx].symbol) {
                patternIdx += 1;
                *count += 1;
            }

            if (patternIdx == ptn.length) {
                *found = true;
                addColor(&brd, ptn.length, row, col, color, 3);
            } else {
                col++;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solveDiagonallyLeft2Top(board brd, pattern ptn, boolean *found, int *count, int color) {
    int col, i;
    int row;
    int patternIdx;

    row = ptn.length - 1;
    *found = false;
    while (row < brd.row && !*found) {
        col = 0;
        while (col < brd.col - ptn.length + 1 && !*found) {
            patternIdx = 0;
            if (ptn.buffer[patternIdx] != brd.buffer[row-patternIdx][col+patternIdx].symbol) {
                *count += 1;
            } else {
                while (patternIdx < ptn.length && ptn.buffer[patternIdx] == brd.buffer[row-patternIdx][col+patternIdx].symbol) {
                    patternIdx += 1;
                    *count += 1;
                }
            }
            
            if (patternIdx == ptn.length) {
                *found = true;
                addColor(&brd, ptn.length, row, col, color, 4);
            } else {
                col++;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solve(board brd, pattern ptn, int *totalCount, int color, int *foundCount) {
    boolean found = false;
    int count = 0;

    solveHorizontally(brd, ptn, &found, &count, color);
    if (!found) {
        strrev(ptn.buffer);
        solveHorizontally(brd, ptn, &found, &count, color);
        strrev(ptn.buffer);
    }
    if (!found) {
        solveVertically(brd, ptn, &found, &count, color);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveVertically(brd, ptn, &found, &count, color);
        strrev(ptn.buffer);
    } 
    if (!found) {
        solveDiagonallyLeft2Bottom(brd, ptn, &found, &count, color);
    } 
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyLeft2Bottom(brd, ptn, &found, &count, color);
        strrev(ptn.buffer);
    }
    if (!found) {
        solveDiagonallyLeft2Top(brd, ptn, &found, &count, color);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyLeft2Top(brd, ptn, &found, &count, color);
        strrev(ptn.buffer);
    }

    if (!found) {
        printf("%s not found. ", ptn.buffer);
    } else {
        printf("%s found. ", ptn.buffer);
        *foundCount += 1; 
    }
    printf("%d Comparisons.\n", count);
    *totalCount += count;
}