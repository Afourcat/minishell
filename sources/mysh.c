/*
** EPITECH PROJECT, 2018
** mysh.c
** File description:
** main file of the mysh program
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include "gnl.h"
#include "my_printf.h"
#include "str_utils.h"
#include "command_parser.h"
#include "minishell.h"
#include "my_signal.h"
#include "environment.h"
#include "error.h"

int my_exec(char **cmd, char *prog, struct env_t *env)
{
	pid_t pid = -1;
	int status = 0;
	
	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid == 0) {
		signal(SIGINT, &signal_child);
		execve(prog, cmd, etsa(env));
		write(2, prog, my_strsize(prog));
		write(2, ": ", 2);
		write(2, strerror(errno), my_strsize(strerror(errno)));
		write(2, ". Wrong Architecture.\n", 22);
	} else {
		if (wait(&status) == -1)
			my_perror("wait");
		check_error(status, env);
	}
	return (0);
}

static int my_sh(char *cmd[], struct env_t *env)
{
	char *prog = NULL;
	int type_cmd = given_path(cmd[0]);

	if (type_cmd == 0)
		prog = get_function(cmd[0], env);
	else if (type_cmd == 1)
		prog = my_strdup(cmd[0]);
	else
		prog = my_strdup(parse_dot(cmd[0]));
	if (prog == NULL) {
		write(2, cmd[0], my_strsize(cmd[0]));
		write(2, ": Command not found.\n", 21);
	} else if (!is_dir(prog)) {
		my_exec(cmd, prog, env);
	}
	free(prog);
	return (0);
}

static int built_in(char *cmd[], struct env_t *env)
{
	for (int i = 0; i < BUILT_IN_NB; ++i)
		if (my_strcmp(BUILT_IN_STR[i], cmd[0])) {
			BUILT_IN[i](cmd, env);
			return (0);
		}
	return (1);
}

char *get_command_line(char *str, struct env_t *env)
{
	int i = -1;
	
	while (str[0] == '\0') {
		i = -1;
		write(1, "$> ", 3);
		free(str);
		str = get_next_line(0);
		if (str == NULL)
			signal_quit(3, env);
		while ((str[++i] == ' ' || str[i] == '\t' ) &&
		       (str[i] != '\0'));
		if (str[i] == '\0')
			str[0] = '\0';
	}
	return (str);
}

#ifndef TEST_MACRO
int main(UNUSED int argc, UNUSED char *argv[], char *envp[])
{
	char *str = my_strdup("");
	int end = 0;
	char **cmd = NULL;
	int nbr = 0;
	struct env_t *env = env_create(envp);

	set_signal(env);
	while (!end)
	{
		str = get_command_line(str, env);
		cmd = command_parser(str, &nbr);
		transform_parser(cmd, env);
		if (built_in(cmd, env))
			my_sh(cmd, env);
		free_cmd(cmd);
		str[0] = '\0';
	}
	env_free(env);
	return (0);
}
#endif /* TEST_MACRO */
