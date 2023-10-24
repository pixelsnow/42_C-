# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:52:16 by vvagapov          #+#    #+#              #
#    Updated: 2023/10/24 16:53:42 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp

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