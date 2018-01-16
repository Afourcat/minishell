##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for the test
##

#/------------------COLOR---------------------\#

GREEN   =       \e[1;32m

WHITE   =       \e[0m

ORANGE  =       \e[1;33m

RED	=	\e[1;35m

BLUE	=	\e[1;34m

#\------------------COLOR----------------------/#

ROOT		=	../..

OBJ_DIR		=	$(ROOT)/release

SRC_DIR		=	$(ROOT)/sources

REAL   	 	=       $(ROOT)/release

TEST_SRC	=	parser_test/parser.c	\
			built_in/env.c		\
			built_in/setenv_test.c

SRC     	=       $(SRC_DIR)/mysh.c                       \
			$(SRC_DIR)/built_in/cd.c                \
	                $(SRC_DIR)/built_in/env.c               \
	                $(SRC_DIR)/built_in/exit.c              \
	                $(SRC_DIR)/built_in/setenv.c            \
	                $(SRC_DIR)/parser/commande_parser.c     \
	                $(SRC_DIR)/parser/get_path.c            \
			$(SRC_DIR)/parser/cut_cmd.c		\
	                $(SRC_DIR)/parser/given_path.c          \
	                $(SRC_DIR)/utils/str_utils.c            \
		        $(SRC_DIR)/utils/str_utils_2.c          \
	                $(SRC_DIR)/utils/utils.c                \
		        $(SRC_DIR)/signal/signal.c              \
	                $(SRC_DIR)/environment/environment.c    \
		        $(SRC_DIR)/environment/environment_2.c  \
	                $(SRC_DIR)/environment/PS1/cpy_prompt.c	

OBJS_TEST	=	$(TEST_SRC:.c=.o)

OBJS_SRC	=	$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC))

OBJS		=	$(OBJS_SRC) $(OBJS_TEST)

CC		=	gcc

MACRO		=	-D TEST_MACRO

CFLAGS		=	-g -I $(ROOT)/include --coverage $(MACRO)

LDFLAGS		=	-L $(ROOT)/library -l myprintf -l gnl -l criterion

NAME		=	test

V		?=	@

all:		$(NAME)	exec

$(NAME):	$(OBJS)
		$(V)$(CC) -o $@ $(DEF) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(REAL)/%.o:    $(SRC_DIR)/%.c
		$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
		$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

exec:
		$(V)printf "\n\t$(GREEN)Executing all test !\n$(WHITE)"
		$(V)printf "\t"
		$(V)./test

clean:
		$(V)printf "$(ORANGE)Removing .gcno files.$(WHITE)\n"
		$(V)rm -f $(addsuffix .gcno, $(basename $(OBJS)))
		$(V)printf "$(ORANGE)Removing .gcda files.$(WHITE)\n"
		$(V)rm -f $(addsuffix .gcda, $(basename $(OBJS)))
		$(V)printf "$(ORANGE)Removing objects files.$(WHITE)\n"
		$(V)rm -f $(OBJS)

fclean:		clean
		$(V)printf "$(RED)Removing binary $(NAME).$(WHITE)\n"
		$(V)rm -f $(NAME)

re:	fclean
	$(V)make --no-print-directory all

.PHONY:	re  clean  fclean  all  exec

.SILENT: $(OBJS)
