#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, minp, vol;
    int total = 0;

    printf("cat <input> | ./first\n");
    while (scanf("%dx%dx%d", &x, &y, &z) > 0) {
        vol = x * y * z;

        if (z >= x && z >= y) {
            minp = 2 * x + 2 * y;
        } else if (x >= z && x >= y) {
            minp = 2 * z + 2 * y;
        } else {
            minp = 2 * z + 2 * x;
        }

        total += minp + vol;
    }
    printf("%d\n", total);
}
