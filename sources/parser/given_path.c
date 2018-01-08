/*
** EPITECH PROJECT, 2017
** given_path.c
** File description:
** given path functions
*/

#include <stdlib.h>
#include "utils.h"
#include "str_utils.h"
#include "environment.h"

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
	char *prog = my_calloc(sizeof(char) * (my_strsize((char*)str)));

	while (str[++i])
		prog[i - 2] = str[i];
	prog[i + 1] = '\0';
	return (prog);
}

int transform_parser(char *cmd[], struct env_t *env)
{
	int i = -1;
	char *ret = NULL;

	while (cmd[++i] != 0) {
		if (cmd[i][0] == '~') {
			ret = change_tilde_home(cmd[i], env_get_value(env, "HOME"));
			free(cmd[i]);
			cmd[i] = my_strdup(ret);
		} else if (cmd[i][0] == '$') {
			ret = env_get_value(env, cmd[i] + 1);
			free(cmd[i]);
			cmd[i] = my_strdup(ret);
		}
	}
	return (0);
}
