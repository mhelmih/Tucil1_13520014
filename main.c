#include <stdio.h>
#include <stdlib.h>
#include "src/filehandler.c"


int main() {
    board brd;
    patternList ptl;

    // char filename[500];
    // printf("Input configuration file: ");
    // scanf("%s", filename);

    char *filename = "tes.txt";
    readFile(filename, &brd, &ptl);
}