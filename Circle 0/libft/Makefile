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
ARCHIVE = ar rcsc

SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	  	 ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  	 ft_isprint.c ft_itoa.c ft_memchr.c ft_split.c \
	  	 ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  	 ft_putchar_fd.c ft_putendl_fd.c ft_strjoin.c \
	  	 ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c\
	  	 ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	  	 ft_strlen.c ft_strmapi.c ft_strncmp.c \
	  	 ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	  	 ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	  	ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	  	ft_lstsize.c ft_lstnew.c ft_lstmap.c

OBJS = ${SOURCE:%.c=%.o}
BOBJS = ${BONUS:%.c=%.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${ARCHIVE} ${NAME} ${OBJS}

bonus: ${BOBJS}
	${ARCHIVE} ${NAME} ${BOBJS}

test:
	${CC} -o libft_test ${SOURCE} libft_test.c
	libft_test.exe

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