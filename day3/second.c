#include <stdio.h>
#include <stdlib.h>



int main() {
    char dir;
    int r[2] = {0};
    int c[2] = {0};

    int max_r[2] = {0};
    int max_c[2] = {0};
    int min_r[2] = {0};
    int min_c[2] = {0};

    int is_santa = 1;

    char buf[10000] = {0};
    int i = 0;

    printf("cat <input> | ./second\n");

    while ((dir = getchar()) > 0) {

        switch (dir) {
            case '>':
                ++c[is_santa];
                break;
            case '^':
                --r[is_santa];
                break;
            case '<':
                --c[is_santa];
                break;
            case 'v':
                ++r[is_santa];
                break;
            default:
                continue; // ignore rest of while loop
        }

        buf[i] = dir;
        i++;

        if (c[is_santa] < min_c[is_santa])
            min_c[is_santa] = c[is_santa];
        else if (c[is_santa] > max_c[is_santa])
            max_c[is_santa] = c[is_santa];

        if (r[is_santa] < min_r[is_santa])
            min_r[is_santa] = r[is_santa];
        else if (r[is_santa] > max_r[is_santa])
            max_r[is_santa] = r[is_santa];

        is_santa = !is_santa;
    }

    int j;


    int max_rt = max_r[1] > max_r[0] ? max_r[1] : max_r[0];
    int max_ct = max_c[1] > max_c[0] ? max_c[1] : max_c[0];
    int min_rt = min_r[1] < min_r[0] ? min_r[1] : min_r[0];
    int min_ct = min_c[1] < min_c[0] ? min_c[1] : min_c[0];


    c[is_santa] = 0 - min_ct;
    r[is_santa] = 0 - min_rt;
    c[!is_santa] = 0 - min_ct;
    r[!is_santa] = 0 - min_rt;


    int num_r = max_rt - min_rt + 1;
    int num_c = max_ct - min_ct + 1;

    char** array = malloc(sizeof(char*) * num_r);
    int b;
    for (b = 0; b < num_r; b++) {
        array[b] = calloc(num_c, sizeof(char));
    }
    is_santa = 1;
    array[r[is_santa]][c[is_santa]] = 1;
    int total = 1;
    for (j = 0; j < i; j++) {
        switch (buf[j]) {
            case '>':
                ++c[is_santa];
                break;
            case '^':
                --r[is_santa];
                break;
            case '<':
                --c[is_santa];
                break;
            case 'v':
                ++r[is_santa];
                break;
            default:
                continue; // ignore rest of while loop
        }

        if (!array[r[is_santa]][c[is_santa]]) {
            total++;
            array[r[is_santa]][c[is_santa]] = 1;
        }


        is_santa = !is_santa;
    }

    // count total, and print.
    // Keeping a tally as I add houses would be more efficent, however.
    printf("total: %d\n", total);
}
