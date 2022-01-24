#include "../header/board.h"


/* array of colors */
char *colors[] = { "DR\0", "DG\0", "DY\0", "DB\0", "DM\0", "DC\0", "BR\0", "BG\0", "BY\0", "BB\0", "BM\0", "BC\0" };

void createBoard(board *brd) {
    (*brd).col = 0;
    (*brd).row = 1;
}

void readBoardDimensionFromFile(FILE *fp, board *brd, boolean *isSuccess) {
    char tempchar;
    
    /* read columns */
    while (tempchar != '\n') {
        fscanf(fp, "%c", &tempchar);
        if (tempchar != ' ' && tempchar != '\n') {
            (*brd).col++;
        }
    }

    /* read rows */
    char str[500];
    while (*fgets(str, sizeof(str), fp) != '\n') {
        (*brd).row++;
    }

    /* allocate buffer */
    (*brd).buffer = (coloredChar **) malloc ((*brd).row * sizeof(coloredChar *));
    if ((*brd).buffer != NULL) {
        for (int i = 0; i < (*brd).row; i++) {
            (*brd).buffer[i] = (coloredChar *) malloc ((*brd).col * sizeof(coloredChar));
            if ((*brd).buffer[i] == NULL) {
                printf("Board allocation failed.\n");
                *isSuccess = false;
                break;
            }
        }

        /* assign all symbols to white */
        for (int i = 0; i < (*brd).row; i++) {
            for (int j = 0; j < (*brd).col; j++) {
                strcpy((*brd).buffer[i][j].color, "WH\0");
            }
        }
        *isSuccess = true;
    } else {
        printf("Board allocation failed.\n");
        *isSuccess = false;
    }
}

void readBoardBufferFromFile(FILE *fp, board *brd) {
    char tempchar;

    for (int i = 0; i < (*brd).row; i++) {
        for (int j = 0; j < (*brd).col; j++) {
            fscanf(fp, " %c", &brd->buffer[i][j]);
        }
    }

    /* to skip the extra 2 newlines */
    fscanf(fp, "%c", &tempchar);
    fscanf(fp, "%c", &tempchar);

    printf("Board %d x %d loaded successfully.\n", (*brd).row, (*brd).col);
}

void printBoard(board brd) {
    printf("\n");
    for (int i = 0; i < brd.col*2 + 3; i++) {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < brd.row; i++) {
        for (int j = 0; j < brd.col; j++) {
            if (j == 0) {
                printf("| ");
            }
            if (strcmp(brd.buffer[i][j].color, "DR") == 0) {
                printf(DR "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "DG") == 0) {
                printf(DG "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "DY") == 0) {
                printf(DY "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "DB") == 0) {
                printf(DB "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "DM") == 0) {
                printf(DM "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "DC") == 0) {
                printf(DC "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BR") == 0) {
                printf(BR "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BG") == 0) {
                printf(BG "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BY") == 0) {
                printf(BY "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BB") == 0) {
                printf(BB "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BM") == 0) {
                printf(BM "%c " RE, brd.buffer[i][j].symbol);
            } else if (strcmp(brd.buffer[i][j].color, "BC") == 0) {
                printf(BC "%c " RE, brd.buffer[i][j].symbol);
            } else {
                printf("%c ", brd.buffer[i][j].symbol);
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < brd.col*2 + 3; i++) {
        printf("=");
    }
    printf("\n\n");
}