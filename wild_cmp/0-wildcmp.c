#include "holberton.h"

/**
 * wildcmp - Compares two strings to see if they are identical, where
 *           the second string can contain the special character '*'.
 * @s1: The first string.
 * @s2: The second string, which may contain the wildcard character '*'.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
    // Base cases
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s2 == '*')
    {
        if (*(s2 + 1) == '\0') // If '*' is the last character in s2, it matches everything
            return (1);
        if (*s1 != '\0' && wildcmp(s1 + 1, s2)) // '*' matches one or more characters in s1
            return (1);
        return (wildcmp(s1, s2 + 1)); // '*' matches zero characters in s1
    }
    if (*s1 == *s2) // If characters match, move to the next character in both strings
        return (wildcmp(s1 + 1, s2 + 1));

    return (0); // Characters do not match
}
