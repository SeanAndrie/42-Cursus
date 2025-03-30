# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 14:16:54 by sgadinga          #+#    #+#              #
#    Updated: 2025/03/27 22:51:42 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft/includes -Iincludes

SRC_DIR = src
BNS_DIR = bonus
OBJ_DIR = obj

SRCS = $(addprefix $(SRC_DIR)/, \
		 main.c node_ops.c map_ops.c rotations.c \
		 stack_init.c stack_valid.c stack_utils.c stack_ops.c\
		 ps_init.c ps_algo.c ps_utils.c \
		 normalize.c other_utils.c debug.c \
		 action_ops.c action_optim.c analyse_dist.c)
BSRCS = $(addprefix $(BNS_DIR)/, checker.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BOBJS = $(BSRCS:$(BNS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: libft $(NAME)

bonus: libft $(BNS_NAME)

libft:
	@make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

$(BNS_NAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNS_NAME) $(BOBJS) -Llibft -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BNS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re libft