/*
** EPITECH PROJECT, 2018
** commande_parser.c
** File description:
** commande parser
*/

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int free_cmd(char **cmd, int nbr)
{
	for (int i = 0; i < nbr + 1; ++i)
		free(cmd[i]);
	free(cmd);
	return (0);
}

static void assigne_word(int nbstr, char *str, char **word_array)
{
	int k = 0;
	int j = -1;
	
	for (int i = 0; i < nbstr; i++, k = 0) {
		while (str[++j] != ' ' && str[j] != '\0')
			word_array[i][k++] = str[j];
		word_array[i][k + 1] = 0;
		while (str[j] == ' ' && str[j + 1] == ' ')
			j++;
		printf("%s\n", word_array[i]);
	}
}

void alloc_words(int nbstr, char *str, char **word_array, int *i)
{
	int j = 0;
	int k = -1;
	
	for (*i = 0; *i < nbstr; ++(*i), j = 0) {
		while (str[++k] != ' ' && str[k] != '\0')
			j++;
		word_array[*i] = my_calloc(sizeof(char) * (j + 2));
		while (str[k] == ' ' && str[k + 1] == ' ')
			k++;
	}	
}

char **command_parser(char *str, int *nb)
{
	int i = -1;
	int nbstr = 1;
	char **word_array = NULL;
	
	while (str[++i])
		if (str[i] == ' ' && str[i + 1] != ' ')
			nbstr++;
	word_array = my_calloc(sizeof(char*) * (nbstr + 2));
	alloc_words(nbstr, str, word_array, &i);
	word_array[i + 1] = my_calloc(sizeof(char) * 2);
	word_array[i + 1][0] = 0;
	assigne_word(nbstr, str, word_array);
	*nb = nbstr;
	return (word_array);
}
