all:
	gcc -Wall -Wextra -Werror srcs/main.c srcs/parser/input.c -I incl/ -lm -o nn
