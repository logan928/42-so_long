NAME = so_long

# Libraries
LIBFT_DIR = ./libft
GNL_DIR = ./gnl
MLX_DIR = ./minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)


#Source fles
SRC = \
	src/so_long.c	\
	gnl/gnl_utils.c	\
	gnl/gnl.c


# Build directories (object files)
DIRS = \
	build	\


# Object files in build/
OBJ = $(SRC:src/%.c=build/%.o)


all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

build/%.o: src/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf build

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




