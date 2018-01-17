/*
** EPITECH PROJECT, 2018
** parser_test
** File description:
** parser unit test
*/

#include <criterion/criterion.h>
#include "command_parser.h"

Test(command_parser, basic_command_test)
{
	char *command = "ls -l -a -R /dev/";
	int nb = 0;
	char **cmd = command_parser(command, &nb);

	cr_assert_str_eq(cmd[0], "ls", "should be ls but it's %s", cmd[0]);
	free_cmd(cmd);
}

Test(command_parser, basic_test_2)
{
	char *command = "cp folder/ /dev/null";
	int nb = 0;
	char **cmd = command_parser(command, &nb);

	cr_assert_str_eq(cmd[0], "cp", "Should be cp but it's %s", cmd[0]);
	cr_assert_str_eq(cmd[1], "folder/", \
			 "Should be folder/ but it's %s", cmd[1]);
	cr_assert_str_eq(cmd[2], "/dev/null", \
			 "Should be /dev/null but it's %s", cmd[2]);
	free_cmd(cmd);
}

Test(command_parser, nb_cmd)
{
	char *command = "cp folder/ /dev/null allo ze zzzzz aaazezae";
	int nb = 0;
	char **cmd = command_parser(command, &nb);

	cr_assert_eq(nb, 7, "Should be 7 and it's %d", nb);
	free_cmd(cmd);	
}


Test(command_parser, multiple_space)
{
	char *command = "cp   folder/ /dev/null";
	int nb = 0;
	char **cmd = command_parser(command, &nb);

	cr_assert_str_eq(cmd[0], "cp", "Should be cp but it's %s", cmd[0]);
	cr_assert_str_eq(cmd[1], "folder/", \
			 "Should be folder/ but it's %s", cmd[1]);
	cr_assert_str_eq(cmd[2], "/dev/null", \
			 "Should be /dev/null but it's %s", cmd[2]);
	free_cmd(cmd);
}
