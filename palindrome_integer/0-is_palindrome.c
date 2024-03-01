#include "palindrome.h"

/**
 * reverse_number - Function to reverse a number
 * @n: The number to reverse
 *
 * Return: The reversed number
 */
unsigned long reverse_number(unsigned long n)
{
    unsigned long reversed = 0;

    while (n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n = n / 10;
    }

    return reversed;
}
