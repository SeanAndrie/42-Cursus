#!/bin/bash

apply_formatting() {
    for file in *."$1"; do
        [[ -f "$file" ]] && c_formatter_42 "$file"
    done
}

apply_formatting c
apply_formatting h

echo "---"
norminette
