NAME		=	polymorph

COMPILER	=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	Cat.cpp \
				Dog.cpp \
				main.cpp \
				Animal.cpp \
				WrongCat.cpp \
				WrongAnimal.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re