NAME		=	fixed3.0

COMPILER	=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Fixed.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re