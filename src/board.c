#include "../header/board.h"

void createBoard(board *brd) {
    (*brd).col = 0;
    (*brd).row = 1;
}

void readBoardDimensionFromFile(FILE *fp, board *brd) {
    char tempchar;
    while (tempchar != '\n') {
        fscanf(fp, "%c", &tempchar);
        if (tempchar != ' ' && tempchar != '\n') {
            (*brd).col++;
        }
    }

    char str[500];
    while (*fgets(str, sizeof(str), fp) != '\n') {
        (*brd).row++;
    }

    (*brd).buffer = (coloredChar **) malloc ((*brd).row * sizeof(coloredChar *));
    if ((*brd).buffer != NULL) {
        for (int i = 0; i < (*brd).row; i++) {
            (*brd).buffer[i] = (coloredChar *) malloc ((*brd).col * sizeof(coloredChar));
            if ((*brd).buffer[i] == NULL) {
                printf("Gagal alokasi board.\n");
                break;
            }
        }

        // assign all chars to white
        for (int i = 0; i < (*brd).row; i++) {
            for (int j = 0; j < (*brd).col; j++) {
                strcpy((*brd).buffer[i][j].color, "WH\0");
            }
        }
    } else {
        printf("Gagal alokasi board.\n");
    }
}

void readBoardBufferFromFile(FILE *fp, board *brd) {
    char tempchar;

    for (int i = 0; i < (*brd).row; i++) {
        for (int j = 0; j < (*brd).col; j++) {
            fscanf(fp, " %c", &brd->buffer[i][j]);
        }
    }

    fscanf(fp, "%c", &tempchar);
    fscanf(fp, "%c", &tempchar);
}

void printBoard(board brd) {
    for (int i = 0; i < brd.row; i++) {
        for (int j = 0; j < brd.col; j++) {
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
        printf("\n");
    }
    printf("\n");
}