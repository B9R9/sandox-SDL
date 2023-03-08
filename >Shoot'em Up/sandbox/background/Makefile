#COMPILATION
CC      := gcc
CFLAGS  := -Wall -Werror -Wextra

#CLEAN & FCLEAN
RM_DIR  := rm -rf
RM      := rm -f

#INCLUDES
INCL   := -I ./include/

#C_FILES
SRC_DIR := ./srcs/
C_FILES    :=		main.c		\
					sdl_init.c	\
					utils.c		\

#OBJECTS
OBJ_DIR := ./obj/
OBJ     := $(addprefix $(OBJ_DIR), $(C_FILES:%.c=%.o))

#LIBRAIRIES
LIB := $(shell sdl2-config --cflags --libs) -lSDL2_image

NAME := exec

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) ./srcs/*.c $(LIB) $(INCL)

clean:
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all


