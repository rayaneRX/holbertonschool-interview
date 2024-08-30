#include "regex.h"


/**
 * regex_match - checks whether a given pattern matches a given string
 *
 * @str: the string to check
 * @pattern: the pattern to match
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	char const *s = str;
	char const *p = pattern;

	if (*s == '\0' && *p == '\0')
		return (1);

	if (*p == '\0')
		return (0);

	if (*(p + 1) != '*')
	{
		if (*s == *p || (*p == '.' && *s != '\0'))
			return (regex_match(s + 1, p + 1));
		else
			return (0);
	}

	while (*s == *p || (*p == '.' && *s != '\0'))
	{
		if (regex_match(s, p + 2))
			return (1);
		s++;
	}

	return (regex_match(s, p + 2));
}