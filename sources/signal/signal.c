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
#include "my_printf.h"
#include "minishell.h"

void signal_interupt(UNUSED int signum) 
{

}

void signal_quit(UNUSED int signum)
{
	my_printf("exit\n");
	exit(0);
}

void set_signal(void)
{
	signal(SIGINT, signal_interupt);
}


