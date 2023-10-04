#include "main.h"
#include <stdlib.h>

int word_len(char *str);
char **strtow(char *str);
int count_words(char *str);

/**
 * word_len - index marking the end of first word
 * @str: input
 * Return: index marking end of word
 */

int word_len(char *str)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != ' ');
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * count_words - counts number of wordswithin a string
 * @str: input
 * Return: number of words
 */

int count_words(char *str)
{
	int index = 0, words = 0, len = 0;

	for (index = 0; *(str + index); index++)
			len++;

			for (index = 0; index < len; index++)
			{
				if (*(str + index) != ' ')
				{
					words++;
					index += word_len(str + index);
				}
			}
			return (words);
}

/**
 * strtow - a function that splits a string into words
 * @str: input
 * Return: NULL if str == NULL or str == ""
 */

char **strtow(char *str)
{
	char **strings;
	int index = 0, words, a, letters, b;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}

			words = count_words(str);
			if (words == 0)
			return (NULL);

			for (a = 0; a < words; a++)
			{
				while (str[index] == ' ')
					index++;
				letters = word_len(str + index);
				strings[a] = malloc((letters + 1) * sizeof(char));

				if (strings[a] == NULL)
				{
					for (; a >= 0; a--)
						free(strings[a]);
				}
				for (b = 0; b < letters; b++)
					strings[a][b] = '\0';
			}
			strings[a] = NULL:
				return (strings);
}
