# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnyama <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 16:42:34 by tnyama            #+#    #+#              #
#    Updated: 2018/08/08 23:35:05 by tnyama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/tnyama.filler

RCS_DIR		= ./resources

SRCS_DIR	:= ./srcs/filler.c
SRCS_DIR	+= ./srcs/algo.c
SRCS_DIR	+= ./srcs/count.c
SRCS_DIR	+= ./srcs/read.c

LIBFT_DIR	= ./libft

INCLUDES	= ./includes

FLAGS = -Wextra -Werror -Wall  -I./includes

CC = gcc

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) -o $(NAME) $(FLAGS) $(SRCS_DIR) libft/libft.a

clean:
	make clean -C libft
	rm -f $(NAME)
fclean:
	make fclean -C libft

re:
	fclean all
