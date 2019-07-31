# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 13:34:36 by kaokeefe          #+#    #+#              #
#    Updated: 2019/07/30 18:44:06 by jiwok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = src/main.c src/fill.c src/ft_atoi.c
HEADER = src/funcs.h
COMPHEADER = src/funcs.h.gch
OBJ = main.o ft_atoi.o fill.o

all: compile
	@gcc -o $(NAME) $(OBJ)

compile:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(HEADER)

clean:
	@rm -f $(OBJ) $(COMPHEADER)

fclean: clean
	@rm -f $(NAME)

re: fclean all
