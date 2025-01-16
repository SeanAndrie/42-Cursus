# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 18:46:27 by sgadinga          #+#    #+#              #
#    Updated: 2025/01/15 14:31:23 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ_DIR = obj
SRC = ft_printf.c ft_format_parsers.c ft_format_spec.c ft_format_utils.c ft_print_char.c ft_print_dec_int.c \
      ft_print_hex.c ft_print_str.c ft_print_uint.c
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
