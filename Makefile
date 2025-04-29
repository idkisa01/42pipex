# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:13:59 by isabegar          #+#    #+#              #
#    Updated: 2025/04/24 21:12:02 by isabegar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
SRCS = srcs/pipex.c srcs/utils.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objs/%.o: srcs/%.c | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs:
	mkdir -p objs

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

