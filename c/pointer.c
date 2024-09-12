#include <stdio.h>
#include <stdlib.h>

int foo(int **ptr) {
    int value = 10;
    *ptr = (int *)malloc(value);  

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    **ptr = value; 
    return 0;
}

int main() {
    int *ptr = NULL;
    if (0 != foo(&ptr)) {
        return -1;
    }

    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr);
    }

    return 0;
}
