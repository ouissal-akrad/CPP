NAME		= Bureaucrat
	
CC			= c++

FLAGS		= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
SRC			= main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			ShrubberyCreationForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			Intern.cpp\

OBJ			= $(SRC:.cpp=.o)

HEADER		= Bureaucrat.hpp ShrubberyCreationForm.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp

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