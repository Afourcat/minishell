/*
** EPITECH PROJECT, 2018
** built_in
** File description:
** environment test
*/

#include <criterion/criterion.h>
#include "environment.h"

Test(env_create, basic_test_env)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "ROGER=bartoo",	\
			   "LOLO=lalala", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
	char *lolo = env_get_value(env, "LOLO");

	cr_assert_str_eq(lolo, "lalala", "Should be lalala but %s\n", lolo);
}

Test(env_create, multiple_test)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "ROGER=bartoo",	\
			   "LOLO=lalala", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
	char *lolo = env_get_value(env, "LOLO");
	char *path = env_get_value(env, "PATH");
	char *name = env_get_value(env, "NAME");
	char *roger = env_get_value(env, "ROGER");

	cr_assert_str_eq(lolo, "lalala", "Should be lalala but %s\n", lolo);
	cr_assert_str_eq(path, "/bin/:/home/afourcat/bin/",		\
			 "Should be lalala but it's %s\n", path);
	cr_assert_str_eq(name, "salut comment tu vas",			\
			 "Should be lalala but it's %s\n", name);
	cr_assert_str_eq(roger, "bartoo",				\
			 "Should be lalala but it's %s\n", roger);
}

Test(env_push, basic_test)
{
	char *env_arr[] = {"NAME=salut comment tu vas", "POFF=piff",	\
			   "FOO=BAR", "PATH=/bin/:/home/afourcat/bin/", 0};
	struct env_t *env = env_create(env_arr);
	char *polo = NULL;

	env_push(env, "POLO=ralph lau");
	polo = env_get_value(env, "POLO");
	cr_assert_str_eq(polo, "ralph lau",				\
			 "Should be ralph lau but it's %s\n", polo);
}
