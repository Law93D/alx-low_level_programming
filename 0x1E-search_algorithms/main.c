#include <stdio.h>
#include "search_algos.h"

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value = 5;
    int index = 0;

    printf("Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    index = jump_search(array, size, value);
    if (index != -1) {
        printf("Value %d found at index: %d\n", value, index);
    } else {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}
