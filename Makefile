# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 10:18:44 by fmontes           #+#    #+#              #
#    Updated: 2024/03/18 10:37:05 by fmontes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBMLX = ../minilibx-linux/libmlx_Linux.a
SRC = check_map.c exit_game.c ft_split.c moves.c read_map.c so_long.c start_game.c start_img.c start_map.c start_moves.c
FLAGSMLX = -Lmlx -lXext -lX11
GNL = ./gnl/*.c
CFLAGS = -Wall -Werror -Wextra
CC  = cc
RM = rm -rf

PRINTF_DIR = ft_printf

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(PRINTF_DIR)
	@ $(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBMLX) $(FLAGSMLX) ft_printf/libftprintf.a -o $(NAME)
	@echo Compilation Finish

clean: 
	@make clean -C $(PRINTF_DIR)
	${RM} ${OBJ}

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	${RM} $(NAME)

re: fclean all


