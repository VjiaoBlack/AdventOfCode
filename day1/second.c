#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    int fl = 0;
    int num = 1;

    printf("cat <input> | ./second\n");
    while ((c = getchar())) {
        if (c == '(') {
            ++fl;
        } else {
            --fl;
            if (fl < 0) {
                break;
            }
        }
        ++num;
    }

    printf("%d\n", num);
}
