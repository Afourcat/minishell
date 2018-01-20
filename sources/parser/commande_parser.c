/*
** EPITECH PROJECT, 2018
** commande_parser.c
** File description:
** commande parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"
#include "utils.h"

int free_cmd(char **cmd)
{
	int i = -1;

	while (cmd[++i] != 0)
		free(cmd[i]);
	free(cmd[++i]);
	free(cmd);
	return (0);
}

static void assigne_word(int nbstr, char *str, char **word_array)
{
	int k = 0;
	int j = -1;

	while (str[++j] == ' ');
	j -= 1;
	for (int i = 0; i < nbstr; i++, k = 0) {
		while (str[++j] != '\0' && str[j] != ' ') {
			assigne_parser(str, &j, &k, word_array[i]);
		}
		word_array[i][k] = 0;
		while ((str[j] == ' ' || str[j] == '"') &&
		       (str[j + 1] == ' ' && str[j + 1] != '\0'))
			j++;
	}
}

void alloc_words(int nbstr, char *str, char **word_array, int *i)
{
	int j = 0;
	int k = 0;

	while (str[k++] == ' ');
	for (*i = 0; *i < nbstr; (*i)++) {
		j = 0;
		while (str[k] != '\0' && str[k] != ' ') {
			alloc_parser(str, &k, &j);
			k++;
		}
		word_array[*i] = my_calloc(sizeof(char) * (j + 20));
		while ((str[k] == ' ' || str[k] == '"') &&
		       (str[k + 1] == ' ' && str[k + 1] != '\0'))
			k++;
	}
}

int count_quote(char *str, int *i)
{
	while (str[++(*i)] != '\0' && str[*i] != '"');
	return (0);
}

char **command_parser(char *str, int *nb)
{
	int i = -1;
	int nbstr = 1;
	char **word_array = NULL;

	while (str[++i])
		str[i] = (str[i] == '\t') ? ' ' : str[i];
	i = -1;
	while (str[++i] == ' ');
	while (str[++i])
		if (str[i] == '"')
			count_quote(str, &i);
		else if (str[i] == ' ' && str[i + 1] != ' ' &&
			 str[i + 1] != '\0')
			nbstr++;
	word_array = my_calloc(sizeof(char*) * (nbstr + 2));
	alloc_words(nbstr, str, word_array, &i);
	word_array[i + 1] = 0;
	assigne_word(nbstr, str, word_array);
	*nb = nbstr;
	return (word_array);
}
