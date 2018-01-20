/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** environement print function
*/

#include <my_printf.h>
#include <stdlib.h>
#include "environment.h"
#include "minishell.h"

int my_env(UNUSED char *cmd[], struct env_t *env)
{
	int i = -1;
	char **str = etsa(env);

	while (str[++i] != 0x0) {
		my_printf("%s\n", str[i]);
		free(str[i]);
	}
	free(str[i]);
	free(str);
	return (0);
}
