NAME	=	so_long
LIB		=	minilibx/libmlx.a -L minilibx -lXext -lX11 -lm
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

SRC		=	*.c 
GET_NEXT_LINE = get_next_line/*c 
PRINTF 	= printf/*c 
OBJ		=	$(SRC:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) $(GET_NEXT_LINE) $(PRINTF) $(LIB) -o $(NAME)

all: $(NAME)

%.c:%.o
		@$(CC) ${CFLAGS} -o $<

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
