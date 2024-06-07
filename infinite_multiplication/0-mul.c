#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit - checks if a string is composed only of digits
 * @str: string to check
 *
 * Return: 1 if true, 0 if false
 */
int is_digit(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

/**
 * multiply - multiplies two large numbers represented as strings
 * @num1: first number
 * @num2: second number
 *
 * Return: pointer to the result
 */
char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_result = len1 + len2;
    int i, j, carry, n1, n2, sum;
    char *result = malloc(len_result + 1);

    if (!result)
        return (NULL);

    for (i = 0; i < len_result; i++)
        result[i] = '0';

    result[len_result] = '\0';

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (n1 * n2) + (result[i + j + 1] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
        if (carry > 0)
            result[i + j + 1] += carry;
    }

    // Find the first non-zero character
    for (i = 0; i < len_result; i++)
    {
        if (result[i] != '0')
            break;
    }

    if (i == len_result)
        return ("0");

    return (result + i);
}

/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if successful, 98 if failure
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    num1 = argv[1];
    num2 = argv[2];

    if (!is_digit(num1) || !is_digit(num2))
    {
        printf("Error\n");
        exit(98);
    }

    result = multiply(num1, num2);

    if (!result)
    {
        printf("Error\n");
        exit(98);
    }

    printf("%s\n", result);
    free(result - (result - num1 < 0 ? 0 : strlen(num1)));
    return (0);
}
