# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 18:12:49 by sgadinga          #+#    #+#              #
#    Updated: 2024/12/18 19:53:49 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS), Windows_NT)
	NAME = libft.lib
else
	NAME = libft.a
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs

ALL_C_FILES = ${wildcard *.c}
EXCLUDE = ft_lstnew.c ft_lstlast.c ft_lstmap.c ft_lstadd_back.c \
          ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
          ft_lstsize.c test_libft.c

SOURCE = ${filter-out ${EXCLUDE}, ${ALL_C_FILES}}
BONUS = ${filter-out test_libft.c, ${EXCLUDE}}

OBJS = ${SOURCE:%.c=%.o}
BOBJS = ${BONUS:%.c=%.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME} bonus

${NAME}: ${OBJS}
	${ARCHIVE} ${NAME} ${OBJS}

bonus: ${BOBJS}
	${ARCHIVE} ${NAME} ${BOBJS}

test: 
	${CC} -o test_libft ${SOURCE} test_libft.c
	test_libft.exe

clean:
ifeq (${OS}, Windows_NT)
	del /Q *.o
else
	rm -f *.o
endif

fclean: clean
ifeq (${OS}, Windows_NT)
	del /Q ${NAME}
else
	rm -f ${NAME}
endif
	
res: fclean all

.PHONY: clean fclean res all bonus ${NAME}