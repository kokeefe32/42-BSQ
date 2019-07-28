# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 13:34:36 by kaokeefe          #+#    #+#              #
#    Updated: 2019/07/28 13:36:46 by kaokeefe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = src/*.c

all:
	@gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
