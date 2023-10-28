# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 20:50:09 by vvagapov          #+#    #+#              #
#    Updated: 2023/10/28 20:50:12 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:%.cpp=%.o)

INC = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re