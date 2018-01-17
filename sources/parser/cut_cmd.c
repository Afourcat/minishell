/*
** EPITECH PROJECT, 2018
** cut_cmd.c
** File description:
** cut command
*/

#include "utils.h"

void alloc_parser(char *str, int *k, int *j)
{
	if (str[*k] == '"') {
		(*k)++;
		while (str[*k] != '\0' && str[*k] != '"') {
			(*j)++;
			(*k)++;
		}
	} else {
		(*j)++;
	}
}

void assigne_parser(char *str, int *j, int *k, char *word_array)
{
	if (str[*j] == '"') {
		(*j)++;
		while (str[*j] != '\0' && str[*j] != '"') {
			word_array[(*k)++] = str[(*j)++];
		}
	} else {
		word_array[(*k)] = str[*j];
		(*k)++;
	}
}
