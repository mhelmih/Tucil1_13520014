#include <stdio.h>
#include <stdlib.h>
#include "src/board.c"
#include "src/patternList.c"
#include "src/fileloader.c"
#include "src/solver.c"

int main() {
    board brd;
    patternList ptl;

    // char filename[500];
    // printf("Input configuration file: ");
    // scanf("%s", filename);

    char *filename = "dari-spek.txt";
    loadFile(filename, &brd, &ptl);

    printf("\n");
    
    for (int i = 0; i < ptl.count; i++) {
        solve(brd, ptl.list[i]);
    }

    printBoard(brd);
   
}