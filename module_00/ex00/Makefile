NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

INC = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $^

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

.PHONY: all clean fclean re