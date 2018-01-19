/*
** EPITECH PROJECT, 2017
** signal.c
** File description:
** signal functions for sighandler
*/

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "str_utils.h"
#include "utils.h"
#include "errno.h"
#include "my_printf.h"
#include "minishell.h"
#include "environment.h"

struct env_t *get_set_env(struct env_t *env)
{
	static struct env_t *saved_pointer = NULL;

	if (env != NULL) {
		saved_pointer = env;
		return (NULL);
	} else {
		return (saved_pointer);
	}
}

void signal_shell(UNUSED int signum)
{
		write(1, "\n$> ", 4);
}

void signal_child(UNUSED int signum) 
{
	pid_t pid = getpid();
	if(kill(pid, SIGINT) == 0)
		perror("kill ");
	exit(0);
}

void signal_quit(UNUSED int signum, struct env_t *env)
{
	if (isatty(0))
		my_printf("exit\n");
	env_free(env);
	exit(0);
}

void set_signal(struct env_t *env)
{
	get_set_env(env);
	signal(SIGINT, &signal_shell);
}


