#include "substring.h"


/**
 * is_valid_substring - Checks if a substring is valid
 * @s: The string to search
 * @words: The words to search for
 * @nb_words: The number of words to search for
 * @word_len: The length of the words
 * @start: The start index of the substring
 *
 * Return: 1 if the substring is valid, 0 otherwise
 */
int is_valid_substring(
	const char *s, char const **words, int nb_words, int word_len, int start)
{
	int *used;
	int i, j, found;

	used = (int *)calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(s + start + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * find_substring - Finds all index positions where a substring
 * @s: The string to search
 * @words: The words to search for
 * @nb_words: The number of words to search for
 * @n: A pointer to the number of substrings found
 *
 * Return: An array of indices where the substrings begin,
 * or NULL if nothing is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, substr_len, max_indices;
	int *result;
	int i;

	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	substr_len = word_len * nb_words;

	if (substr_len > s_len)
	{
		*n = 0;
		return (NULL);
	}

	max_indices = s_len - substr_len + 1;

	result = (int *)malloc(max_indices * sizeof(int));
	if (!result)
		return (NULL);

	*n = 0;

	for (i = 0; i <= s_len - substr_len; i++)
	{
		if (is_valid_substring(s, words, nb_words, word_len, i))
			result[(*n)++] = i;
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
