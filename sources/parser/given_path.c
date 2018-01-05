/*
** EPITECH PROJECT, 2017
** given_path.c
** File description:
** given path functions
*/

#include "utils.h"
#include "str_utils.h"
#include <stdlib.h>

int given_path(const char *str)
{
	int i = -1;

	while (str[++i]) {
		if (str[1] == '/' && str[0] == '.')
			return (2);
		else if (str[i] == '/')
			return (1);
	}
	return (0);
}

char *parse_dot(const char *str)
{
	int i = 0;
	char *prog = my_malloc(sizeof(char) * (my_strlen((char*)str)));

	while (str[++i])
		prog[i - 2] = str[i];
	prog[i + 1] = '\0';
	return (prog);
}

int transform_parser(char *cmd[], char *env[])
{
	int i = -1;
	char *ret = NULL;

	while (cmd[++i] != 0) {
		if (cmd[i][0] == '~') {
			ret = change_tilde_home(cmd[i], env);
			free(cmd[i]);
			cmd[i] = ret;
		}
	}
	return (0);
}
