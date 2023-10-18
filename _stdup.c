#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * *_strdup - function that returns a pointer to
 * a newly allocated space in memory
 * @str: pointer to a string
 * Return: Null if string is null or insufficient memory available else pointer
 */
char *_strdup(char *str)
{
	int i;
	char *str2;
	int counter = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	counter = strlen(str);
	str2 = malloc(sizeof(char) * (counter + 1));
	if (str2 == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		str2[i] = str[i];
	}
	str2[i] = '\0';
	return (str2);
}
