NAME		= ScavTrap
	
CC			= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\

OBJ			= $(SRC:.cpp=.o)

HEADER		= ClapTrap.hpp ScavTrap.hpp

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