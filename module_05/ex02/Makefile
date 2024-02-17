NAME = bureaucrat

CC = c++ -std=c++11

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp

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
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re