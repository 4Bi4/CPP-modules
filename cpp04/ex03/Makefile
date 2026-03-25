NAME		=	interface

COMPILER	=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	Ice.cpp \
				main.cpp \
				Cure.cpp \
				AMateria.cpp \
				Character.cpp \
				MateriaSource.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re