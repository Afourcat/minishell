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
	if (my_exec(NULL, NULL, NULL)) {
		write(1, "\n", 1);
		generate_prompt(get_set_env(NULL));
	} else {
		write(1, "\n", 1);
	}
}

void signal_child(UNUSED int signum) 
{
	my_printf("LOLO");
	pid_t pid = getpid();
	if(kill(pid, SIGINT) == 0)
		perror("kill ");
	exit(0);
}

void signal_quit(UNUSED int signum)
{
	my_printf("exit\n");
	exit(0);
}

void set_signal(struct env_t *env)
{
	get_set_env(env);
	signal(SIGINT, &signal_shell);
}


