NAME		= Convert
	
CC			= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
SRC			= main.cpp\
			ScalarConverter.cpp\

OBJ			= $(SRC:.cpp=.o)

HEADER		= ScalarConverter.hpp 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean re