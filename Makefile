# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 18:33:54 by dzonda       #+#   ##    ##    #+#        #
#    Updated: 2018/07/12 13:28:12 by dzonda      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean lib

NAME = fillit

MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -lft -ltermcap
LDFLAGS = -Llibft/
RM = rm -f

SRCS_PATH = ./src/
OBJS_PATH = ./obj/
INCS_PATH = ./include/
LIB_PATH = ./libft/

SRCS_NAME =	\
			main.c \
			ft_init.c \
			ft_init_check.c \
			ft_check.c \
			ft_templates_one.c \
			ft_templates_two.c \
			ft_templates_three.c \
			ft_templates_four.c \
			ft_templates_five.c \
			ft_create_map.c \
			ft_solver.c \
			ft_print_map.c

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

all: $(NAME)

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(LDLIBS)
	@echo "\033[1;32m[ $(NAME) ] Compiled\033[0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[1m[ $@ ] Compiled\033[0m"
	@echo "\033[2A"
	@echo "\033[K"
	@echo "\033[2A"

lib:
	@make -C $(LIB_PATH)

clean:
	@$(MAKE) -C $(LIB_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIB_PATH) fclean
	@$(RM) $(NAME)
	@echo "\033[1;31m[ $(NAME) ] deleted\033[0m"

re: fclean all
