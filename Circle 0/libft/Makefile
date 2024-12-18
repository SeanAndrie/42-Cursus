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

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

C = -c

LFLAGS = ar rcs

SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c \
		 ft_strlcpy.c ft_strlcat.c ft_memset.c ft_memcpy.c \
		 ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c \
		 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		 ft_putnbr_fd.c ft_bzero.c ft_itoa.c ft_strchr.c ft_strrchr.c \
		 ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_split.c ft_strmapi.c ft_atoi.c \

BSOURCE = ft_lstnew.c ft_lstlast.c ft_lstmap.c ft_lstadd_back.c \
		ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstsize.c \

OBJS = ${SOURCE:%.c=%.o}

BOBJS = ${BSOURCE:%.c=%.o}

all: ${NAME}

${NAME}: ${NAME} ${OBJS} ${SOURCE}
	     ${CC} ${CFLAGS} ${C} ${SOURCE}
	     ${LFLAGS} ${NAME} ${OBJS}

bonus: ${NAME} ${BOBJS} ${BSOURCE}
	   ${CC} ${CFLAGS} ${C} ${BSOURCE}
	   ${LFLAGS} ${NAME} ${BOBJS}

clean: 
	rm -f *.o

fclean: clean
	rm -f ${NAME}

res: fclean all