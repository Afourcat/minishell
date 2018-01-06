##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=	..

SRC_DIR	=	.

CC	=	gcc

NAME	=	mysh

REAL	=	$(ROOT)/release

SRC	=	$(SRC_DIR)/mysh.c			\
		$(SRC_DIR)/built_in/cd.c		\
		$(SRC_DIR)/built_in/env.c		\
		$(SRC_DIR)/built_in/exit.c		\
		$(SRC_DIR)/parser/commande_parser.c	\
		$(SRC_DIR)/parser/get_path.c		\
		$(SRC_DIR)/parser/given_path.c		\
		$(SRC_DIR)/utils/str_utils.c		\
		$(SRC_DIR)/utils/utils.c		\
		$(SRC_DIR)/signal/signal.c

WARN	=	-W -Wall -Wextra

CFLAGS	=	-I $(ROOT)/include $(WARN)

LDFLAGS	=	-L $(ROOT)/library -l myprintf -l gnl

LIB	?=	1

DEB	?=      0

G	=	-g

OBJ	=	$(patsubst %.c, $(REAL)/%.o, $(SRC))

ifeq ($(DEB), 1)
	CFLAGS += $(G)
endif

MACRO	?=	NORMAL

#COLOR

GREEN	=	\e[1;32m

WHITE	=	\e[0m

ORANGE	=	\e[1;33m

RED	=	\e[1;35m

all:	$(NAME)

$(NAME):	echo_build $(REAL)/$(NAME)
		@cp $(REAL)/$(NAME) $(ROOT)
		@printf "$(GREEN)Dup $(NAME) into root directory.$(WHITE)\n"


$(REAL)/$(NAME):	buildrepo $(OBJ)
			@printf "$(GREEN)Compile sources.$(WHITE)\n"
			@$(CC) -o $(REAL)/$(NAME) $(OBJ) $(LDFLAGS) -D $(MACRO)
			@printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(REAL)/%.o:	$(SRC_DIR)/%.c
		@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	@rm -rf $(OBJ)
	@printf "$(ORANGE)removing object files.$(WHITE)\n"

fclean:	clean
	@rm -f $(REAL)/$(NAME)
	@rm -f $(ROOT)/$(NAME)
	@printf "$(ORANGE)removing binary file.$(WHITE)\n"

buildrepo:
		$(call make-repo)

re:	fclean
	@make --no-print-directory all 

echo_build:	echo_debug
		@printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_debug:
		@if [ $(DEB) == 1 ]; then\
			printf "$(RED)debug mode initialized.$(WHITE)\n";\
		fi

.PHONY: clean fclean debug all re echo_build echo_debug buildrepo

define make-repo
	@for dir in $(dir $(OBJ)); \
	do 			  \
		mkdir -p $$dir;	  \
	done
endef
