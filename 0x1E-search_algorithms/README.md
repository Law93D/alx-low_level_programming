# Search Algorithms

This repository contains various search algorithms implemented in C programming language. Search algorithms are used to find the presence and/or location of an element within a data structure such as an array or a linked list.

## List of Algorithms

1. **Linear Search**: Searches for a target value by checking each element of the array sequentially.
2. **Binary Search**: Searches for a target value in a sorted array by repeatedly dividing the search interval in half.
3. **Jump Search**: Searches for a target value in a sorted array by jumping ahead by fixed steps and then performing linear search.
4. **Jump List**: Searches for a target value in a singly linked list with an additional jump pointer.
5. **Linear Skip**: Searches for a target value in a sorted singly linked list with an additional express lane for faster skipping.
6. **Advanced Binary Search**: A modified version of binary search that finds the first occurrence of a target value in a sorted array.
7. **Interpolation Search**: An improved version of binary search for uniformly distributed arrays.
8. **Exponential Search**: A search algorithm that works on sorted arrays by doubling the index size on each iteration.

## Usage

Each algorithm is implemented as a separate function in the `search_algos.h` header file. To use these algorithms, include the header file in your C program and call the desired function with appropriate arguments.

For example:

```c
#include <stdio.h>
#include "search_algos.h"

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size = sizeof(array) / sizeof(array[0]);
    int target = 7;
    
    int result = binary_search(array, size, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}
