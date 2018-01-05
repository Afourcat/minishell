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
#include "gnl.h"
#include "my_printf.h"
#include "str_utils.h"
#include "command_parser.h"
#include "minishell.h"
#include "my_signal.h"

static int my_exec(char **cmd, char *prog, char *env[])
{
	int statue = 0;
	pid_t pid = 0;
	
	pid = fork();
	if (pid < 0)
		perror("fork ");
	else if (pid == 0)
		execve(prog, cmd, env);
	else
		waitpid(pid, &statue, 0);
	return (0);
}

static int my_sh(char *cmd[], char *envp[])
{
	char *prog = NULL;
	int type_cmd = given_path(cmd[0]);

	if (type_cmd == 0)
		prog = get_function(cmd[0], envp);
	else if (type_cmd == 1)
		prog = my_strdup(cmd[0]);
	else 
		prog = parse_dot(cmd[0]);
	if (prog == NULL)
		my_printf("%s: no program found\n", cmd[0]);
	else
		my_exec(cmd, prog, envp);
	return (0);
}

static int built_in(char *cmd[], char *env[])
{	
	for (int i = 0; i < BUILT_IN_NB; ++i)
		if (my_strcmp(BUILT_IN_STR[i], cmd[0])) {
			BUILT_IN[i](cmd, env);
			return (0);
		}
	return (1);
}

int main(UNUSED int argc, UNUSED char *argv[], char *envp[])
{
	char *str;
	int end = 0;
	char **cmd = NULL;
	int nbr = 0;
	
	set_signal();
	while (!end)
	{
		my_printf("$> ");
		str = get_next_line(0);
		if (str == NULL) 
			signal_quit(3);
		cmd = command_parser(str, &nbr);
		transform_parser(cmd, envp);
		if (built_in(cmd, envp))
			my_sh(cmd, envp);
		free_cmd(cmd, nbr);
	}
	return (0);
}
