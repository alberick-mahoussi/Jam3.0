##
## EPITECH PROJECT, 2023
## Jam3.0
## File description:
## Makefile
##

NAME =	light

SRC =	$(shell echo source/*.cpp)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
		g++ -o $(NAME) $(SRC) $(CXXFLAGS)

clean:
		rm -f $(OBJ)

fclean:         clean
		
		rm -f src/*.o
		rm -f $(NAME)

re:             fclean all

.PHONY:         all clean fclean re