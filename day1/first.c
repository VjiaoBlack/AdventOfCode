#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    int fl = 0;

    printf("cat <input> | ./first\n");
    while ((c = getchar())) {
        if (c == '(')
            ++fl;
        else if (c == ')')
            --fl;
        else
            break;
    }
    printf("%d\n", fl);
}
