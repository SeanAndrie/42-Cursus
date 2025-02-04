#!/bin/bash

echo -n "Enter Buffer Size:"
read -r size

cc -Wall -Werror -Wextra -D BUFER_SIZE="$size" gnl_test.c get_next_line.c get_next_line_utils.c && ./a.out
