/*
** EPITECH PROJECT, 2017
** setenv.c
** File description:
** built in header for setenv
*/

#include "environment.h"
#include "my_printf.h"

int cmd_len(char *cmd[])
{
	int i = -1;
	
	while (cmd[++i] != 0);
	return (i);
}

int my_setenv(char *cmd[], struct env_t *env)
{
	int size = cmd_len(cmd);

	if (size <= 2) {
		my_printf("not enough args.\n");
		return (1);
	} else {
		env_push_two_part(env, cmd[1], cmd[2]);
		return (0);
	}
}

int my_unsetenv(char *cmd[], struct env_t *env)
{
	int size = cmd_len(cmd);

	if (size <= 1) {
		my_printf("not enough args.");
		return (1);
	} else {
		if (!env_pop(env, cmd[1]))
			my_printf("not found.\n");
		return (0);
	}
	return (0);
}
