#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, a1, a2, a3, min;
    int total = 0;

    printf("cat <input> | ./first\n");
    while (scanf("%dx%dx%d", &x, &y, &z) > 0) {
        a1 = x * y;
        a2 = x * z;
        a3 = y * z;

        if (a1 < a2) {
            if (a3 < a1)  min = a3;
            else        min = a1;
        } else {
            if (a3 < a2)  min = a3;
            else        min = a2;
        }
        total += 2*a1 + 2*a2 + 2*a3 + min;
    }
    printf("%d\n", total);
}
