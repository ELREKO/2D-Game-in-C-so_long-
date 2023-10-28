NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC  = 	errorhandling.c \
	main.c \
	maps_read.c \
	utiles_1.c 

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/
LIB		= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(OBJ_PATH) $(NAME)

allgdb: $(OBJ_PATH) $(NAME) -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

${NAME}:	${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

gdb: fclean allgdb

.PHONY: all clean fclean re