#include <stdio.h>
#include <stdlib.h>



int main() {
    char dir;
    int r = 0, c = 0;

    int max_r = 0, max_c = 0, min_r = 0, min_c = 0;

    char buf[10000] = {0};
    int i = 0;

    printf("cat <input> | ./first\n");

    while ((dir = getchar()) > 0) {

        switch (dir) {
            case '>':
                ++c;
                break;
            case '^':
                --r;
                break;
            case '<':
                --c;
                break;
            case 'v':
                ++r;
                break;
            default:
                continue; // ignore rest of while loop
        }

        buf[i] = dir;
        i++;

        if (c < min_c)
            min_c = c;
        else if (c > max_c)
            max_c = c;

        if (r < min_r)
            min_r = r;
        else if (r > max_r)
            max_r = r;
    }

    int j;
    c = 0 - min_c;
    r = 0 - min_r;

    char** array = malloc(sizeof(char*) * (max_r - min_r + 1));
    int b;
    for (b = 0; b < (max_r - min_r + 1); b++) {
        array[b] = calloc(max_c - min_c + 1, sizeof(char));
    }

    array[r][c] = 1;
    int total = 1;
    for (j = 0; j < i; j++) {
        switch (buf[j]) {
            case '>':
                ++c;
                break;
            case '^':
                --r;
                break;
            case '<':
                --c;
                break;
            case 'v':
                ++r;
                break;
            default:
                continue; // ignore rest of while loop
        }

        if (!array[r][c]) {
            total++;
            array[r][c] = 1;
        }


    }

    // count total, and print.
    // Keeping a tally as I add houses would be more efficent, however.
    printf("total: %d\n", total);
}
