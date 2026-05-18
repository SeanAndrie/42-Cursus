NAME := vect2
CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98

SRCS := main.cpp vect2.cpp
OBJS := $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.cpp: %.o
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
