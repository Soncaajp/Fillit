# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 12:12:12 by rhulk             #+#    #+#              #
#    Updated: 2019/07/19 12:12:28 by rhulk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= srcs/validation.c \
				  srcs/tetriminos.c \
				  srcs/map.c \
				  srcs/coordination.c \
				  srcs/main.c

OBJS = validation.o \
				  tetriminos.o \
				  map.o \
				  coordination.o \
				  main.o



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
