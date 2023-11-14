# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 13:57:40 by vvagapov          #+#    #+#              #
#    Updated: 2023/11/14 16:00:17 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Replacer.cpp

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
	rm -f *.replace

re: fclean all

.PHONY: all clean fclean re