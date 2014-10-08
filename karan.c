#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** storage;



int isCharacter(char first) {
    return first > 64 && first < 91 || first > 96 && first < 123;
}

void extrapwords(FILE *dictionary){
    char line[10000];
    fgets(line, sizeof(line), dictionary);

    storage = malloc(sizeof(char*)*10000);
    int first = (int) line[0], mode, start = 0, current = 0;
    if (isCharacter(first)) {
        mode = 1;
    } else {
        mode = 0;
    }
    for(int x = 0;x<80000;x++) {
        if (line[x] == '\0') {
            break;
        }
        if (mode) {
            if (!isCharacter(line[x])) {
                mode = 0;
                storage[current] = (char *) malloc(sizeof(char) * (x - start));
                strncpy(storage[current], line + start, x - start);
                current++;
            }
        } else {
            if (isCharacter(line[x])) {
                start = x;
                mode = 1;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("invalid input\n");
        return 1;
    }

    FILE *dictionary = fopen(argv[1], "r");
    FILE *datafile = fopen(argv[2], "r");

    extrapwords(dictionary);
    extrapwords(datafile);

    printf("hello\n");



















    return 0;
}
