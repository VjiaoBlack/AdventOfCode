#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    int fl = 0;

    printf("cat <input> | ./first\n");
    while ((c = getchar()) > 0) {
        if (c == '(')
            ++fl;
        else
            --fl;
    }
    printf("%d\n", fl);
}
