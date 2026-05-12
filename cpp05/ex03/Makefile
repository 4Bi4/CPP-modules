NAME		=	ex03

COMPILER	=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	Bureaucrat.cpp \
            	AForm.cpp \
            	ShrubberyCreationForm.cpp \
            	RobotomyRequestForm.cpp \
            	PresidentialPardonForm.cpp \
            	Intern.cpp \
            	main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
