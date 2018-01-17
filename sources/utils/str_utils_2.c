/*
** EPITECH PROJECT, 2017
** str_utils_2.c
** File description:
** str utils functions
*/

#include "str_utils.h"
#include "utils.h"

int my_strsize(const char *str)
{
	int i = -1;

	while (str[++i]);
	return (i);
}

char *str_swipe(char *str, int where, int offset)
{
	int i = where;

	while (str[i + offset] != '\0') {
		str[i] = str[i + offset];
		i++;
	}
	str[i] = 0;
	return (str);
}

char *my_revstr(char *str)
{
	int i = 0;
	int size = my_strsize(str);
	
	while (i < size / 2) {
		str[i] = str[size - i];
	}
	return (str);
}

int get_int_size(int nbr)
{
	int i = 0;
	
	while ((nbr /= 10) < 0)
		i++;
	return (i);
}

char *my_itoa(int nb)
{
	int size = get_int_size(nb);
	char *str = my_calloc(sizeof(char) * (get_int_size(nb) + 1));

	for (int i = 0; i < size; i++, nb /= 10)
		str[i] = (nb % 10) + 48;
	my_revstr(str);
	return (str);
}
