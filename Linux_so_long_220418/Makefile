# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 01:08:17 by dhaliti           #+#    #+#              #
#    Updated: 2022/03/16 10:41:16 by dhaliti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS		= srcs/main.c  srcs/so_long_tests.c  srcs/clear.c srcs/so_long_keyboard.c srcs/Mac_print.c srcs/ft_mouv_guardian.c





NAME            = so_long
#NAME		= pokemon
OBJS_DIR	= objs/
PROJECT_H	= srcs/so_long.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
#MLXFLAGS = -framework OpenGL -framework AppKit
MLXFLAGS = -I /usr/X11/include -g -Lmlx_linux -lmlx_Linux -L /usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm


all: $(NAME)


#$(OBJS_DIR)%.o : %.c $(PROJECT_H)
#	@mkdir -p $(OBJS_DIR)
#	@mkdir -p $(OBJS_DIR)srcs
#	@$(CC) $(CC_FLAGS) -c $< -o $@
#	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

#$(NAME): $(OBJECTS_PREFIXED) maker
#	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ./LIBFT/libft.a \
#	./MINILIBX/libmlx.a ${MLXFLAGS}
#	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)srcs
	$(CC) $(CC_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ./libft_total/libft.a \
	./mlx_linux/libmlx.a ${MLXFLAGS}
	printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"


maker:
	make -C ./libft_total
	make -C ./mlx_linux

clean:
	make clean -C ./libft_total
	make clean -C ./mlx_linux
	rm -rf $(OBJS_DIR)
	printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	make fclean -C ./libft_total
#	@make fclean -C ./mlx_linux
	rm -f $(NAME)
	printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:		all clean fclean re maker
