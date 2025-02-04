#!/bin/bash

for file in *.c; do
	if [[ -e "$file" && -f "$file" ]]; then
		c_formatter_42 "$file"
	fi
done
echo "Formatting Complete!"
echo "---"
norminette
