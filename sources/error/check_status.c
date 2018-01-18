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
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	if (status == 11 || status == 139) {
		write(2, "Segmentation fault\n", 20);
		nb = my_itoa(WEXITSTATUS(status));
		env_push_two_part(env, "?", nb);
		free(nb);
	} else if (status == 8 || status == 136) {
		write(2, "Floating exception\n", 19);
		nb = my_itoa(WEXITSTATUS(status));
		env_push_two_part(env, "?", nb);
		free(nb);
	}
        // 11 139
	//8 136
	/*
	if (WIFEXITED(status)) {
		
	} else if (WIFSIGNALED(status)) {
		if (WTERMSIG(status))
		write(2, "Segmentation fault\n", 20);
		else if (WCOREDUMP(status))
			write(2, "Segmentation fault\n", 20);
	}
	*/
	return (0);
}

void my_perror(const char *str)
{
	char *error = strerror(errno);

	write(2, str, my_strsize(str));
	write(2, ": ", 2);
	write(2, error, my_strsize(error));
	write(2,".\n", 2);     
}

int is_dir(char *prog)
{
	struct stat stats;
	
	if (stat(prog, &stats) != -1) {
		if (S_ISDIR(stats.st_mode)) {
			write(2, prog, my_strsize(prog));
			write(2, ": Permission denied.\n", 21);
			return (1);
		}
	}
	return (0);
}
