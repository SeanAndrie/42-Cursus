# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 16:19:12 by sgadinga          #+#    #+#              #
#    Updated: 2025/04/11 13:53:01 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc 
CFLAGS = -Wall -Werror -Wextra -Ilibft/includes -Iincludes

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, \
		 pipex.c pipex_utils.c path_utils.c cmd_ops.c exec.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: libft $(NAME)

libft: 
	@make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft