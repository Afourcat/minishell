/*
** EPITECH PROJECT, 2017 
** signal.h
** File description:
** signal functions header
*/

#ifndef	SIGNAL_H_
#define	SIGNAL_H_	

void signal_quit(int signum);
void signal_child(int signum);
void set_signal(void);
char *prompt_save(char *prompt);

#endif /* SIGNAL_H_ */
