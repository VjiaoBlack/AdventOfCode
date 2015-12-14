#include <stdio.h>
#include <stdlib.h>



typedef struct col_t {
    int pos;
    struct col_t *next;
    struct col_t *prev;
} col_t;

typedef struct row_t {
    int pos;
    struct row_t *next;
    struct row_t *prev;
    col_t* elements;
} row_t;

col_t* new_col() {
    col_t* col = malloc(sizeof(col_t));

    col->pos = 0;
    col->next = NULL;
    col->prev = NULL;

    return col;
}

row_t* new_row() {
    row_t* row = malloc(sizeof(row_t));

    row->pos = 0;
    row->next = NULL;
    row->prev = NULL;
    row->elements = new_col();
    row->elements->pos = 0;

    return row;
}

void add_house(row_t* base, int r, int c) { // inserts double linked list nodes
    row_t* nr = base;
    row_t* holdr;
    if (r < nr->pos) {
        while (r < nr->pos && nr->prev) {
            nr = nr->prev;
        }
        if (nr->pos != r) {
            holdr = nr->prev;
            nr->prev = new_row();
            nr->prev->pos = r;
            nr->prev->elements->pos = c;
            if (holdr) {
                holdr->next = nr->prev;
                nr->prev->prev = holdr;
            }
            nr = nr->prev;
            return;
        }
    } else if (r > nr->pos) {
        while (r > nr->pos && nr->next) {
            nr = nr->next;
        }
        if (nr->pos != r) {
            holdr = nr->next;
            nr->next = new_row();
            nr->next->pos = r;
            nr->next->elements->pos = c;
            if (holdr) {
                holdr->prev = nr->next;
                nr->next->next = holdr;
            }
            nr = nr->next;
            return;
        }
    }

    col_t* nc = nr->elements;
    col_t* holdc;
    if (c < nc->pos) {
        while (c < nc->pos && nc->prev) {
            nc = nc->prev;
        }
        if (nc->pos != c) {
            holdc = nc->prev;
            nc->prev = new_col();
            nc->prev->pos = c;
            if (holdc) {
                holdc->next = nc->prev;
                nc->prev->prev = holdc;
            }
            nc = nc->prev;
        }
    } else if (c > nc->pos) {
        while (c > nc->pos && nc->next) {
            nc = nc->next;
        }
        if (nc->pos != c) {
            holdc = nc->next;
            nc->next = new_col();
            nc->next->pos = c;
            if (holdc) {
                holdc->prev = nc->next;
                nc->next->next = holdc;
            }
            nc = nc->next;
        }
    }
}

int houses_in_row(row_t* row) {
    int num = 1;
    col_t* len = row->elements;     printf("  cur: %d, %d\n", row->pos, len->pos);
    while ((len = len->prev)) {
        ++num;                      printf("  pre: %d, %d\n", row->pos, len->pos);
    }

    len = row->elements;
    while ((len = len->next)) {
        ++num;                      printf("  pst: %d, %d\n", row->pos, len->pos);
    }
    return num;
}

int houses_in_base(row_t* base) {
                                    printf("base:\n");
    int num = houses_in_row(base);
    row_t* len = base;
    while ((len = len->prev)) {
                                    printf("pre: %d\n", len->pos);
        num += houses_in_row(len);
    }

    len = base;
    while ((len = len->next)) {
                                    printf("post: %d\n", len->pos);
        num += houses_in_row(len);
    }
    return num;
}





int main() {
    char dir;
    int total = 0;
    int r = 0, c = 0;
    row_t* base = new_row(); // at 0, 0

    printf("cat <input> | ./first\n");

    add_house(base, 0, 0);
                                    printf("0: %d, %d\n", r, c);

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

        printf("%c: %d, %d\n", dir, r, c);

        add_house(base, r, c);
    }

    // count total, and print.
    // Keeping a tally as I add houses would be more efficent, however.
    printf("total: %d\n", houses_in_base(base));
}
