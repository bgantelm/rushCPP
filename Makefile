NAME = ft_retro

FLAG =  -Wall -Wextra -Werror -c

LIB = -lncurses

INC = -I ./includes
SRC = src/data.cpp \
	  src/main.cpp \
	  src/screen.cpp \
	  src/actions.cpp \
	  src/Utils.cpp \
		src/Player.cpp \
	  src/Vessel.cpp \
	  src/Enemy.cpp \
	  src/Object.cpp

SRC0 = data.o \
	  main.o \
	  screen.o \
	  actions.o \
	  Utils.o \
	  Player.o \
	  Vessel.o \
	  Enemy.o \
	  Object.o

all: $(NAME)

$(NAME):
	clang++ $(FLAG) $(SRC) $(INC)
	clang++ -o $(NAME) $(SRC0) $(SRC02) $(LIB)

clean:
	rm -f $(SRC0)

fclean: clean
	rm -f $(NAME)

re: fclean all
