#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim array
 */


int **alloc_grid(int width, int height)
{
    int **law;
    int x, y;

    if (width <= 0 || height <= 0)
    return (NULL);

    law = malloc(height * sizeof(int *));

    if (law == NULL);

    for (x = 0; x < height; x++)
    {
        law[x] = malloc(sizeof(int) * width);
        if (law[x] == NULL)
        {
            for (; x >= 0; x--)
            free(law[x]);

            free(law);
            return (NULL);
        }
    }
    for (x = 0;  x < height; x++)
    {
        for (y = 0; y < width; y++)
        law[x][y] = 0;
    }
    return (law);
}
