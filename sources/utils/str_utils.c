/*
** EPITECH PROJECT, 2018
** str_utils.c
** File description:
** str functions
*/

#include "str_utils.h"
#include "utils.h"

int my_strcmp(const char* dest, const char* str)
{
	int i = -1;
	int j = -1;
	
	while ((dest[++i] == str[++j]) && str[j] != '\0' && dest[i] != '\0');
	if (dest[i] == '\0' && str[j] == '\0')
		return (1);
	else 
		return (0);
}

char *my_strdup(const char *str)
{
	int i = -1;
	char *new_str = my_malloc(sizeof(char) * (my_strlen((char*)str) + 1));

	while (str[++i])
		new_str[i] = str[i];
	new_str[i + 1] = '\0';
	return (new_str);
}

char *my_strcat(char *dest, char *str)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++)
		;
	if (str[0] == '/' && dest[i - 1] == '/')
		return (dest);
	for (j = 0; str[j] != '\0'; j++)
		dest[i+j] = str[j];
	dest[i + j] = 0;
	return (dest);
}

char *my_strcpy(char *dest, char *str)
{
	int i = 0;

	while (str[i]) {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

