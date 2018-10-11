# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnyama <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/02 20:47:15 by tnyama            #+#    #+#              #
#    Updated: 2018/09/04 14:58:15 by tnyama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../prog/checker
SOURCES = checker.c doop.c push.c rotate.c swap.c utils.c
INCLUDES = ../libft/libft.a

$(NAME):
	make -C ../libft
	gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
