#include <stdio.h>
#include <math.h>

/**
 * main - finds and  prints the largest prime factor of the number
 * 612852475143
 * followed by a new line
 * Return: Always 0 (Success)
 */

int main(void)
{

	long long num = 612852475143;
        long long largestPrimeFactor = 2;

        while (num > largestPrimeFactor)
       	{
        if (num % largestPrimeFactor == 0)
       	{
            num /= largestPrimeFactor;
        } else {
            largestPrimeFactor++;
        }
        }

        printf("The largest prime factor is: %lld\n", largestPrimeFactor);

        return 0;
}
