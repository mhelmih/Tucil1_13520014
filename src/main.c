#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.c"
#include "patternList.c"
#include "fileloader.c"
#include "solver.c"

#define BILLION  1000000000.0

int main() {
    int tempchar, count, foundCount;
    char filename[1001];
    struct timespec start, end;
    board brd;
    patternList ptl;

    printf("==================================================\n");
    printf("Input configuration file: ");
    scanf("%s", filename);
    printf("--------------------------------------------------\n");
    if (loadFile(filename, &brd, &ptl) != 0) {
        printf("Word Searched: \n");
        count = 0;
        foundCount = 0;
        clock_gettime(CLOCK_REALTIME, &start);
        for (int i = 0; i < ptl.count; i++) {
            printf("%2d. ", i+1);
            solve(brd, ptl.list[i], &count, i%12, &foundCount);
        }
        clock_gettime(CLOCK_REALTIME, &end);
        double totalTime = (end.tv_nsec - start.tv_nsec)/BILLION;

        printBoard(brd);
        printf("Pattern found (%d/%d).\n", foundCount, ptl.count);
        printf("Total time needed: %lfs.\n", totalTime);
        printf("Total comparison:  %d.\n\n", count);

        free(brd.buffer);
        free(ptl.list->buffer);
        free(ptl.list);
    }
    printf("Input any number to exit. ");
    scanf("%d", &tempchar);
}