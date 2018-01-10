/*
** EPITECH PROJECT, 2017 
** signal.h
** File description:
** signal functions header
*/

#ifndef	SIGNAL_H_
#define	SIGNAL_H_	

#include "environment.h"

void signal_quit(int signum);
void signal_child(int signum);
void set_signal(struct env_t *env);
char *prompt_save(char *prompt);

#endif /* SIGNAL_H_ */
