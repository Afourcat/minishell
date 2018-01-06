/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** environnement function
*/

#include <my_printf.h>
#include "environment.h"

int my_env(__attribute__ ((unused)) char *cmd[], struct env_t *env)
{
	int i = 0;
	char **str = etsa(env);

	while (str[++i] != 0x0)
		my_printf("%s\n", str[i]);
	return (0);
}
