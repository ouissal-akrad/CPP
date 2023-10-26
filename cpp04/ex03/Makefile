NAME		= Interface
	
CC			= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp\
			AMateria.cpp\
			Character.cpp\
			Cure.cpp\
			Ice.cpp\
			MateriaSource.cpp\

OBJ			= $(SRC:.cpp=.o)

HEADER		= AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp 

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