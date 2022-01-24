#include <stdio.h>
#include <stdlib.h>
#include "../header/boolean.h"
#include "../header/board.h"
#include "../header/patternList.h"

void addColor(board *brd, int patternLength, int row, int col, int color, int direction) {
    int i, rowDirection, colDirection;
    int horizontal[] = { 1, -1, 0,  0, 1, -1, -1,  1 };
    int vertical[]   = { 0,  0, 1, -1, 1, -1,  1, -1 };

    rowDirection = row;
    colDirection = col;
    for (i = 0; i < patternLength; i++) {
        strcpy((*brd).buffer[rowDirection][colDirection].color, colors[color]);

        rowDirection += vertical[direction];
        colDirection += horizontal[direction];
    }
}

void search(board brd, pattern ptn, int *count, int row, int col, boolean *found, int color) {
    int i, j, rowDirection, colDirection;
    int horizontal[] = { 1, -1, 0,  0, 1, -1, -1,  1 };
    int vertical[]   = { 0,  0, 1, -1, 1, -1,  1, -1 };
    
    *found = false;
    if (brd.buffer[row][col].symbol == ptn.buffer[0]) {
        *count += 1;
        i = 0;
        while (i < 8 && !*found) {
            rowDirection = row + vertical[i];
            colDirection = col + horizontal[i];
            j = 1;
            while (j < ptn.length && 0 <= rowDirection && rowDirection < brd.row && 0 <= colDirection && colDirection < brd.col) {
                if (ptn.buffer[j] == brd.buffer[rowDirection][colDirection].symbol) {
                    *count += 1;
                    rowDirection += vertical[i];
                    colDirection += horizontal[i];
                    j++;
                } else {
                    *count += 1;
                    break;
                }
            }
            
            if (j == ptn.length) {
                *found = true;
                addColor(&brd, ptn.length, row, col, color, i);
            } else {
                i++;
            }
        }
    } else {
        *count += 1;
    }
}

void solve(board brd, pattern ptn, int *totalCount, int color, int *foundCount) {
    boolean found;
    int i, j, count;
    
    found = false;
    count = 0;
    i = 0;
    while (i < brd.row && !found) {
        j = 0;
        while (j < brd.col && !found) {
            search(brd, ptn, &count, i, j, &found, color);
            j++;
        }
        i++;
    }

    *totalCount += count;
    if (found) {
        printf("%s found. %d Comparison(s).\n", ptn.buffer, count);
        *foundCount += 1;
    } else {
        printf("%s not found. %d Comparison(s).\n", ptn.buffer, count);
    }
} 