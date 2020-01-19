# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 14:25:56 by galiza            #+#    #+#              #
#    Updated: 2019/05/21 14:36:13 by mcanhand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/extra_func_1.c \
		srcs/extra_func_2.c \
		srcs/get_next_line.c \
		srcs/main.c \
		srcs/map_print.c \
		srcs/tetr_checks.c \
		srcs/tetr_solve.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS)))



all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
