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
#include "str_utils.h"

int cmd_len(char *cmd[])
{
	int i = -1;
	
	while (cmd[++i] != 0);
	return (i);
}

static int is_setable(char *cmd)
{
	int i = -1;
	char *char_error = "setenv: Variable name must"	\
		" contain alphanumeric characters.\n";
	char *number_error = "setenv: Variable name must"	\
		" begin with a letter.\n";
	
	if (!(cmd[0] >= 'A' && cmd[0] <= 'Z') &&
	    !(cmd[0] >= 'a' && cmd[0] <= 'z')) {
		write(2, number_error, my_strsize(number_error));
		return (0);
	}
	while (cmd[++i]) {
		if (!(cmd[i] >= '0' && cmd[i] <= '9') &&
		    !(cmd[i] >= 'A' && cmd[i] <= 'Z') &&
		    !(cmd[i] >= 'a' && cmd[i] <= 'z') &&
		    !(cmd[i] == '_')) {
			write(2, char_error, my_strsize(char_error));
			return (0);
		}
	}
	return (1);
}

int my_setenv(char *cmd[], struct env_t *env)
{
	int size = cmd_len(cmd);

	if (size > 1 && !is_setable(cmd[1]))
		return (-1);
	if (size <= 2) {
		if (size == 1) {
			my_env(cmd, env);
		} else {
			env_pop(env, cmd[1]);
			env_push_two_part(env, cmd[1], "");
		}
	} else if (size > 3) {
		write(2, "setenv: Too many arguments.\n", 29);
		return (1);
	} else {
		if (env_get_value(env, cmd[1]) != NULL)
			env_pop(env, cmd[1]);
		env_push_two_part(env, cmd[1], cmd[2]);
	}
	return (0);
}

int my_unsetenv(char *cmd[], struct env_t *env)
{
	int size = cmd_len(cmd);
	int i = -1;

	if (size <= 1) {
		write(2 , "unsetenv: Too few arguments.\n", 30);
		return (1);
	}
	while (cmd[++i])
		env_pop(env, cmd[i]);
	return (0);
}
