/*
** EPITECH PROJECT, 2017
** setenv.c
** File description:
** built in header for setenv
*/

#include <unistd.h>
#include "environment.h"
#include "my_printf.h"
#include "minishell.h"

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
		if (size == 1)
			my_env(cmd, env);
		else
			env_push_two_part(env, cmd[1], "");
		return (0);
	} else if (size > 3) {
		write(2, "setenv: Too many arguments.\n", 31);
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
		write(2 , "unsetenv: Too few arguments.\n", 30);
		return (1);
	} else {
		if (!env_pop(env, cmd[1]))
			my_printf("not found.\n");
		return (0);
	}
	return (0);
}
