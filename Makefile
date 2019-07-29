# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 13:34:36 by kaokeefe          #+#    #+#              #
#    Updated: 2019/07/28 16:55:45 by jiwok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = src/*c
HEADER = src/funcs.h
OBJ = *o

all: compile
	@gcc -o $(NAME) $(OBJ)

compile:
	@gcc -c -Wall -Werror -Wextra $(SRC) $(HEADER)

clean:
	@rm -f *.o funcs.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all
