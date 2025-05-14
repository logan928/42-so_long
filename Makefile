# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 21:22:46 by uwettasi          #+#    #+#              #
#    Updated: 2025/05/07 21:22:51 by uwettasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Libraries
LIBFT_DIR = ./libft
GNL_DIR = ./gnl
PRINTF_DIR	= ./printf
MLX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)


#Source fles
SRC = \
	src/so_long.c	\
	gnl/gnl_utils.c	\
	gnl/gnl.c	\
	src/map/validate_map.c	\
	src/map/validate_util.c	\
	src/map/build_map.c	\
	src/map/flood_fill.c	\
	src/map/update_utils.c	\
	src/map/render_map.c	\
	src/game/game.c	\
	src/game/image_manager.c	\
	src/game/player_moves.c	\
	src/game/game_utils.c	\
	src/game/player_utils.c


# Build directories (object files)
DIRS = \
	build	\
	build/map	\
	build/game


# Object files in build/
OBJ = $(SRC:src/%.c=build/%.o)


all: $(LIBFT) $(PRINTF) $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX)

build/%.o: src/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR) clean
	rm -rf build

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




