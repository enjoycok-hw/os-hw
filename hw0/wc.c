#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc == 0) {
        fp = stdin;
    }
    else if (argc == 1) {
        fp = argv[1]
    }

    return 0;
}
