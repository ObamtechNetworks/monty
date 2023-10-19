#include "monty.h"
/**
 * trim_whitespace - trims leading or trailing whitespaces
 * @str: the string to trim
 * Return: nothing
 */
void trim_whitespace(char *str)
{
	char *end = NULL;

	/* trime leading whitespace*/
	while (isspace(*str))
		str++;

	/*if the string is empty return*/
	if (*str == '\0')
		return;

	/* trim trailing whitespace*/
	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
		end--;

	/*Null terminate the trimmed string*/
	*(end + 1) = '\0';
}
