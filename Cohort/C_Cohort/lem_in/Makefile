# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnyama <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 02:47:58 by tnyama            #+#    #+#              #
#    Updated: 2018/09/21 02:48:26 by tnyama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRC		=	srcs/main.c srcs/parser.c srcs/ft_error.c srcs/add_room.c\
			srcs/is_valid.c srcs/find_room.c srcs/set_weights.c srcs/algo.c

OBJ		=	$(SRC:.c=.o)

%.o:%.c
			@echo " - Creating $<..."
			@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

CFLAGS	=	-Wall -Wextra -Werror -Ofast 

INC		=	-Iincludes -Ilibft

LIB		=	-L ./libft -lft

CC		= 	gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

clean:
	@echo " - Cleaning object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
