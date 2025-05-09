# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 16:14:48 by uwettasi          #+#    #+#              #
#    Updated: 2025/03/13 17:13:49 by uwettasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = \
	ft_printf.c \
	ft_print_char.c\
	ft_print_digit.c\
	ft_print_str.c\
	ft_print_udigit.c\
	ft_print_ptr.c\
	ft_print_hex.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "libftprintf.a created!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< -> $@"

clean:
	@rm -f $(OBJ)
	@echo "Objects cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "Library cleaned!"

re: fclean all

.PHONY: all clean fclean re 
		
