##
## Makefile for Makefile in /home/jeremy.elkaim/dante
## 
## Made by jeremy elkaim
## Login   <jeremy.elkaim@epitech.net>
## 
## Started on  Wed Apr 12 09:48:13 2017 jeremy elkaim
## Last update Sun May 14 23:49:06 2017 jeremy elkaim
##

CC		=	gcc $(CFLAGS) $(CPPFLAGS)

NAME		=	solver

NAME2		=	generator

SRC		=	astar/main.c				\

SRC3		=	breadth/src/main.c			\
			breadth/src/test.c			\
			breadth/src/get_next_line.c		\

SRC4		=	depth/main.c				\

SRC5		=	tournament/main.c			\

SRC2		=	generator/src/main.c			\
			generator/src/function.c		\
			generator/src/numb.c			\
			generator/src/parser.c			\
			generator/src/malloc_maze.c		\
			generator/src/add_imperfection.c	\

OBJ		=	$(SRC:.c=.o)

OBJ2		=	$(SRC2:.c=.o)

OBJ3		=	$(SRC3:.c=.o)

OBJ4		=	$(SRC4:.c=.o)

OBJ5		=	$(SRC5:.c=.o)

TMP		=	$(SRC:.c=.c~)

TMP3		=	$(SRC3:.c=.c~)

TMP4		=	$(SRC4:.c=.c~)

TMP5		=	$(SRC5:.c=.c~)

TMP2		=	$(SRC2:.c=.c~)

RM		=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

CPPFLAGS        =       -Igenerator/include/

all: $(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	$(CC) -o breadth/$(NAME) $(OBJ3)
	$(CC) -o depth/$(NAME) $(OBJ4)
	$(CC) -o tournament/$(NAME) $(OBJ5)
	$(CC) -o generator/$(NAME2) $(OBJ2)
	$(CC) -o astar/$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(TMP)
	$(RM) $(OBJ2) $(TMP2)
	$(RM) $(OBJ3) $(TMP3)
	$(RM) $(OBJ4) $(TMP4)
	$(RM) $(OBJ5) $(TMP5)

fclean: clean
	$(RM) astar/$(NAME)
	$(RM) breadth/$(NAME)
	$(RM) depth/$(NAME)
	$(RM) tournament/$(NAME)
	$(RM) generator/$(NAME2)

re: fclean all

.PHONY: all clean fclean re
