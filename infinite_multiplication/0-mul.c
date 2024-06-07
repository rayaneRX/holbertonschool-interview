#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * print_error_and_exit - Print "Error" and exit with status 98
 *
 * Return: void
*/
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}


/**
 * is_digit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}


/**
 * validate_arguments - Validate the arguments
 * @argc: The number of arguments
 * @argv: The arguments
 *
 * Return: void
*/
void validate_arguments(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		print_error_and_exit();
	}
	for (i = 1; i < 3; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!is_digit(argv[i][j]))
			{
				print_error_and_exit();
			}
		}
	}
}


/**
 * multiply - Multiply two numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: void
*/
void multiply(char *num1, char *num2)
{
	int len1, len2, i, j, mul, sum;
	int *result;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = (int *)calloc(len1 + len2, sizeof(int));
	if (result == NULL)
	{
		print_error_and_exit();
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
	{
		i++;
	}
	if (i == len1 + len2)
	{
		printf("0\n");
	}
	else
	{
		for (; i < len1 + len2; i++)
		{
			printf("%d", result[i]);
		}
		printf("\n");
	}
	free(result);
}


/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The arguments
 *
 * Return: 0 on success, 98 on failure
*/
int main(int argc, char *argv[])
{
	validate_arguments(argc, argv);
	multiply(argv[1], argv[2]);
	return (0);
}
