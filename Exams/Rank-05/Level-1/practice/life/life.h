#ifndef LIFE_H
# define LIFE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_board{
    int width;
    int height;
    char **grid;
}               t_board;

typedef struct s_pen{
    int x;
    int y;
    bool draw;
}               t_pen;

typedef struct s_range {
    int start;
    int end;
}               t_range;

static void board_free(t_board *b) {
    if (!b)
        return ;
    if (b->grid)
        free(b->grid);
    free(b);
}

#endif
