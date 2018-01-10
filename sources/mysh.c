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
#include "environment.h"

int my_exec(char **cmd, char *prog, struct env_t *env)
{
	int status = 0;
	pid_t pid = -1;
	static pid_t is_fork = 0;

	if (env == NULL)
		return (is_fork);
	pid = fork();
	if (pid < 0)
		perror("fork ");
	else if (pid == 0) {
		signal(SIGINT, &signal_child);
		execve(prog, cmd, etsa(env));
		my_printf("test_1");
		exit(0);
	} else {
		is_fork = 1;
		waitpid(pid, &status, 0);
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
		prog = parse_dot(cmd[0]);
	if (prog == NULL)
		my_printf("%s: no program found\n", cmd[0]);
	else
		my_exec(cmd, prog, env);
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
	while (str[0] == '\0') {
		generate_prompt(env);
		free(str);
		str = get_next_line(0);
		if (str == NULL) 
			signal_quit(3);	
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
		free_cmd(cmd, nbr);
		str[0] = '\0';
	}
	return (0);
}
#endif /* TEST_MACRO */
