NAME	= megaphone
	
CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): 
	@ $(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean re