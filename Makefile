CC		:= gcc
CFLAGS	:= -std=c11 -pedantic -Wall -Werror -Wextra
SRC		:= ./second_part/10.c
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

check_valgrind: $(SRC)
		@clear
		@echo -------------------MEMORY_LEAKS-------------------
		$(CC) -g $(SRC) $(CFLAGS) -o $(TEST)
		CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST)

check_leaks: $(SRC)
		@echo -------------------MEMORY_LEAKS-------------------
		$(CC) -g $(SRC) $(CFLAGS) -o $(TEST)
		CK_FORK=no leaks --atExit -- ./$(TEST)

clean:
		rm -rf $(OBJ) $(TEST)
		rm -rf $(TEST)
re:
		$(MAKE) clean
		$(MAKE) all
