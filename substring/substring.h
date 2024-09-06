    #ifndef __SUBSTRING_H__
#define __SUBSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_valid_substring(
	const char *s, char const **words, int nb_words, int word_len, int start);

#endif /* __SUBSTRING_H__ */
