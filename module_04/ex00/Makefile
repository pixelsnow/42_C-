# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:27:10 by vvagapov          #+#    #+#              #
#    Updated: 2023/11/14 20:11:32 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:%.cpp=%.o)

INC = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.cpp
	$(CC) -c $(FLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re