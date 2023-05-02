CC		:= gcc
CFLAGS	:= -std=c11 -pedantic -Wall -Werror -Wextra
SRC		:= main.c functions.c
OBJ		:= $(SRC:.c=.o)
TEST	:= test

.PHONY: all test clean re

all: test

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
test: $(NAME)
		@clear
		$(CC) $< $(SRC) -o $(TEST)
		./$(TEST)
clean:
		rm -rf $(OBJ) $(TEST)
		rm -rf $(TEST)
re:
		$(MAKE) clean
		$(MAKE) all
