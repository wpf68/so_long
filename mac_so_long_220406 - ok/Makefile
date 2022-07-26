
#  *********************************************************
#  *******************   Version Mac  **********************
#  *********************************************************

NAME		= so_long
SRC		= srcs/main.c \
			srcs/so_long_tests.c \
			srcs/clear.c \
		 	srcs/so_long_keyboard.c \
		   	srcs/Mac_print.c \
			srcs/ft_mouv_guardian.c


OBJ		= $(SRC:.c=.o)
PROJECT_H	= srcs/so_long.h
CC		= gcc
FLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(OBJ) maker
	$(CC) $(FLAGS) -lmlx ${MLXFLAGS} $(SRC) -o $(NAME) ./libft_total/libft.a

%.o: %.c
	$(CC) -c $(FLAGS) -Imlx $< -o $@

maker:
	make -C ./libft_total

run: all
	./$(NAME) map0.ber

clean:
	make clean -C ./libft_total
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft_total
	rm -rf $(NAME)

re: fclean all 

.PHONY:		all clean fclean re run
