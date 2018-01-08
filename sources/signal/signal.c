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

char *prompt_save(char *prompt)
{
	static char *buffer = NULL;
	
	if (prompt != NULL && buffer != NULL)
		free(buffer);
	if (prompt != NULL) {
		buffer = my_calloc(sizeof(char) * (my_strsize(prompt) + 2));
		my_strcpy(buffer, prompt);
	}
	return (buffer);
}

void signal_shell(UNUSED int signum)
{
	my_printf("\n%s", prompt_save(NULL));
}

void signal_child(UNUSED int signum) 
{
	pid_t pid = getpid();
	if(kill(pid, SIGINT) == -1)
		perror("kill ");
	exit(0);
}

void signal_quit(UNUSED int signum)
{
	my_printf("exit\n");
	exit(0);
}

void set_signal()
{
	signal(SIGINT, signal_shell);
}


