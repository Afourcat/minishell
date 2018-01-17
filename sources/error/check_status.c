/*
** EPITECH PROJECT, 2018
** check_status.c
** File description:
** check the status
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include "environment.h"
#include "str_utils.h"

int check_error(int pid, struct env_t *env)
{
	char *nb = NULL;
	int status = 0;
	int w = 0;
	
	w = waitpid(pid, &status, 0);
	if (w == -1) {
		perror("waitpid");
		exit(84);
	}
	if (WIFEXITED(status)) {
		nb = my_itoa(WEXITSTATUS(status));
		env_push_two_part(env, "?", nb);
		free(nb);
	} else if (WIFSIGNALED(status)) {
		if (WTERMSIG(status))
			write(2, "Segmentation fault\n", 20);
		else if (WCOREDUMP(status))
			write(2, "Segmentation fault\n", 20);
	}
	return (0);
}
