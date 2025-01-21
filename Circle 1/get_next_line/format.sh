#!/bin/bash

for file in *.c; do
	if [[ -f "$file" ]]; then
		c_formatter_42 "$file"
	else
		break
	fi
done
echo "---"
norminette
echo "Formatting Complete!"
