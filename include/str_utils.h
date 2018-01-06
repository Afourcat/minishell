/*
** EPITECH PROJECT, 2017
** str_utils.h
** File description:
** str utils
*/

#ifndef STR_UTILS_H_
#define STR_UTILS_H_

int my_strcmp(const char* dest, const char *str);
int my_strlen(char* str);
char *my_strcat(char *dest, char *str);
char *my_strcpy(char *dest, char *str);
char *my_strdup(const char *str);
char *change_tilde_home(char *str, char *home);

#endif /* STR_UTILS_H */
