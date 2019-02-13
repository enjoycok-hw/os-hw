#include <stdio.h>
#include <stdlib.h>

static int char_count = 0;
static int word_count = 0;
static int line_count = 0;

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc == 1) {
        fp = stdin;
    }
    else if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else {
        return 0;
    }

    countword(fp);

    fclose(fp);
    printf("%d\t%d\t%d\n", line_count, word_count, char_count);

    return 0;
}

int countword(FILE* fp) {
    if (fp == NULL || feof(fp)) return 0;

    int word = 0;
    char c;
    while ((c = getc(fp)) != EOF) {
        char_count++;
        if (c == '\n') {
            if (word) {
                word_count++;
            }
            line_count++;
            word = 0;
        }
        else if (c == ' ' || c == '\t') {
            if (word) {
                word_count++;
            }
            word = 0;
        }
        else {
            word = 1;
        }
   }

    if (word) {
        word_count++;
    }
}