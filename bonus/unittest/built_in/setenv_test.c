/*
** EPITECH PROJECT, 2018
** setenv_test.c
** File description:
** test functions for set env and unsetenv
*/

#include <criterion/criterion.h>
#include "environment.h"
#include "minishell.h"

Test(setenv, basic_test)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "ROGER=bartoo",	\
			   "LOLO=lalala", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
	char *set_env1[] = {"test", "LILI", "name is lolo", 0};
	my_setenv(set_env1, env);
	char *lolo = env_get_value(env, "LILI");
	char *name = env_get_value(env, "NAME");

	cr_assert_str_eq(lolo, "name is lolo",				\
			 "Should be name is lolo but it's %s\n", lolo);
	cr_assert_str_eq(name, "salut comment tu vas",			\
			 "Should be salut comment tu vas but it's %s\n", name);
}

Test(setenv, two_set)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "ROGER=bartoo",	\
			   "LOLO=lalala", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
	char *set_env1[] = {"test", "LOLO", "name is lolo", 0};
	char *set_env2[] = {"test", "POPO", "pipopipo", 0};
	char *set_env4[] = {"test", "SALAM", "Beurette a chicha", 0};
	char *set_env5[] = {"test", "EPITECH", "lililopzaoepoape", 0};
	my_setenv(set_env1, env);
        my_setenv(set_env2, env);
	my_setenv(set_env4, env);
	my_setenv(set_env5, env);
	char *epitech = env_get_value(env, "EPITECH");
	char *salam = env_get_value(env, "SALAM");

	cr_assert_str_eq(epitech, "lililopzaoepoape",			\
			 "Should be name is lolo but it's %s\n", epitech);
	cr_assert_str_eq(salam, "Beurette a chicha",			\
			 "Should be Beurette a chicha but it's %s\n", salam);
}

Test(unsetenv, basic_test)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "ROGER=bartoo",	\
			   "LOLO=lalala", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
        char *set_env1[] = {"test", "LOLO", "name is lolo", 0};
	char *set_env2[] = {"test", "POPO", "pipopipo", 0};
	char *set_env3[] = {"test", "EPITECH", "lolilkl", 0};
	char *set_env4[] = {"test", "SALAM", "Beurette a chicha", 0};
	my_setenv(set_env1, env);
        my_setenv(set_env2, env);
	my_setenv(set_env3, env);
	my_setenv(set_env4, env);
     	char *unset_1[] = {"test", "ROGER", 0};
	my_unsetenv(unset_1, env);
	char *epitech = env_get_value(env, "EPITECH");
	char *salam = env_get_value(env, "SALAM");

	cr_assert_str_eq(epitech, "lolilkl",				\
			 "Should be lolilo but it's %s\n", epitech);
	cr_assert_str_eq(salam, "Beurette a chicha",			\
			 "Should be Beurette a chicha but it's %s\n", salam);
}
