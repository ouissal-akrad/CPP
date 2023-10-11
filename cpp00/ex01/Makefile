NAME		= PhoneBook
	
CC			= c++

FLAGS		= -Wall -Wextra -Werror

SRC			= main.cpp\
			PhoneBook.cpp\
			Contact.cpp\

OBJ			= $(SRC:.cpp=.o)

HEADER		= Contact.hpp PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ)  -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all