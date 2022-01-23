#include <stdio.h>
#include <stdlib.h>
#include "../header/boolean.h"
#include "../header/board.h"
#include "../header/patternList.h"

void solveHorizontally(board brd, pattern ptn, boolean *found) {
    int col;
    int row;
    int patternLength;
    int patternIdx;

    row = 0;
    *found = false;
    while (row < brd.row && !*found) {
        patternLength = ptn.length;
        col = 0;
        while (col <= brd.col - patternLength && !*found) {
            patternIdx = 0;
            while (patternIdx <= ptn.length && ptn.buffer[patternIdx] == brd.buffer[row][col+patternIdx].symbol) {
                patternIdx++;
            }

            if (patternIdx == patternLength) {
                *found = true;
                for (int i = 0; i < patternLength; i++) {
                    strcpy(brd.buffer[row][col+i].color, "DR\0");
                }
            } else {
                col++;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solveVertically(board brd, pattern ptn, boolean *found) {
    int col;
    int row;
    int patternLength;
    int patternIdx;

    col = 0;
    *found = false;
    while (col < brd.col && !*found) {
        patternLength = ptn.length;
        row = 0;
        while (row <= brd.row - patternLength && !*found) {
            patternIdx = 0;

            while (patternIdx < ptn.length && ptn.buffer[patternIdx] == brd.buffer[row+patternIdx][col].symbol) {
                patternIdx += 1;
                if (patternIdx == patternLength) {
                    break;
                }
            }

            if (patternIdx == patternLength) {
                *found = true;
                for (int i = 0; i < patternLength; i++) {
                    strcpy(brd.buffer[row+i][col].color, "DY\0");
                }
            } else {
                row += 1;
            }
        }

        if (!*found) {
            col++;
        }
    }
}

void solveDiagonallyFromLeft(board brd, pattern ptn, boolean *found) {
    int col;
    int row;
    int patternLength;
    int patternIdx;

    row = 0;
    patternLength = ptn.length;
    *found = false;
    while (row <= brd.row - patternLength && !*found) {
        col = 0;
        while (col <= brd.col - patternLength && !*found) {
            patternIdx = 0;
            while (patternIdx <= ptn.length && ptn.buffer[patternIdx] == brd.buffer[row+patternIdx][col+patternIdx].symbol) {
                patternIdx++;
                if (patternIdx == patternLength) {
                    break;
                }
            }

            if (patternIdx == patternLength) {
                *found = true;
                for (int i = 0; i < patternLength; i++) {
                    strcpy(brd.buffer[row+i][col+i].color, "DG\0");
                }
            } else {
                col++;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solveDiagonallyFromRight(board brd, pattern ptn, boolean *found) {
    int col;
    int row;
    int patternLength;
    int patternIdx;

    row = 0;
    patternLength = ptn.length;
    *found = false;
    while (row <= brd.row - patternLength && !*found) {
        col = brd.col - 1;
        while (col >= brd.col - patternLength && !*found) {
            patternIdx = 0;
            while (patternIdx <= ptn.length && ptn.buffer[patternIdx] == brd.buffer[row+patternIdx][col-patternIdx].symbol) {
                patternIdx++;
                if (patternIdx == patternLength) {
                    break;
                }
            }

            if (patternIdx == patternLength) {
                *found = true;
                for (int i = 0; i < patternLength; i++) {
                    strcpy(brd.buffer[row+i][col-i].color, "DB\0");
                }
            } else {
                col--;
            }
        }

        if (!*found) {
            row++;
        }
    }
}

void solve(board brd, pattern ptn) {
    boolean found = false;
    solveHorizontally(brd, ptn, &found);
    if (!found) {
        strrev(ptn.buffer);
        solveHorizontally(brd, ptn, &found);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveVertically(brd, ptn, &found);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveVertically(brd, ptn, &found);
    } 
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyFromLeft(brd, ptn, &found);
    } 
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyFromLeft(brd, ptn, &found);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyFromRight(brd, ptn, &found);
    }
    if (!found) {
        strrev(ptn.buffer);
        solveDiagonallyFromRight(brd, ptn, &found);
    }
    if (!found) {
        printf("%s is not found.\n", ptn.buffer);
    }
}