/**
 * File: solver.c
 * 
 * Berisi prosedur untuk menyelesaikan
 * persoalan dengan algoritma brute force
 */

#include <stdio.h>
#include <stdlib.h>
#include "../header/boolean.h"
#include "../header/board.h"
#include "../header/patternList.h"

int horizontal[] = { 1, -1, 0,  0, 1, -1, -1,  1 };
int vertical[]   = { 0,  0, 1, -1, 1, -1,  1, -1 };
/**
 * Jika i adalah indeks pada array horizontal dan vertikal, maka
 * i = 0 -> horizontal ke kiri
 * i = 1 -> horizontal ke kanan
 * i = 2 -> vertikal ke bawah
 * i = 3 -> vertikal ke atas
 * i = 4 -> diagonal ke kanan bawah
 * i = 5 -> diagonal ke kiri atas
 * i = 6 -> diagonal ke kiri bawah
 * i = 7 -> diagonal ke kanan atas
 */

void addColor(board *brd, int patternLength, int row, int col, int color, int direction) {
    int i, rowDirection, colDirection;

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

void solve(board brd, pattern ptn, int *totalCount, int color, int *foundCount, int maxLength) {
    boolean found;
    int i, j, count, length;
    
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

    char *status[] = { "not found", "found" };
    *totalCount += count;
    if (maxLength > 13) {
        printf("%-*s %-9s", maxLength, ptn.buffer, status[found]);
    } else {
        printf("%-13s %-9s", ptn.buffer, status[found]);
    }
    *foundCount += 1;
    printf(" %13d\n", count);
} 