# include "life.h"

static t_board* board_create(const int w, const int h) {
    if (w == 0 || h == 0)
        return NULL;
    t_board *b = malloc(sizeof(t_board));
    if (!b)
        return NULL;
    b->width = w;
    b->height = h;
    b->grid = calloc(1, (sizeof(char *) * h) + (sizeof(char) * w * h));
    if (!b->grid) {
        free(b);
        return NULL;
    }
    char *data = (char *)(b->grid + h);
    for (int i = 0; i < h; i++)
        b->grid[i] = data + (i * w);
    return b;
}

static bool board_draw(t_board *b) {
    char cmd;
    t_pen p = {0};

    if (!b || !b->grid)
        return false;
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'x')
            p.draw ^= 1;
        else if (cmd == 'w' && p.y > 0)
            p.y--;
        else if (cmd == 's' && p.y < b->height - 1)
            p.y++;
        else if (cmd == 'd' && p.x < b->width - 1)
            p.x++;
        else if (cmd == 'a' && p.x > 0)
            p.x--;

        if (p.draw)
            b->grid[p.y][p.x] = 1;
    }
    return true;
}

static void board_print(t_board *b) {
    for (int i = 0; i < b->height; i++) {
        for (int j = 0; j < b->width; j++)
            putchar((b->grid[i][j]) ? 'O' : ' ');
        putchar('\n');
    }
}

static t_range create_range(const int n, const int max) {
    t_range r;

    r.start = ((n - 1) < 0) ? 0 : n - 1;
    r.end = ((n + 1) >= max) ? max : n + 2;
    return r;
}

static int count_neighbors(t_board *b, const int y, const int x) {
    int n = 0;
    t_range y_r;
    t_range x_r;

    y_r = create_range(y, b->height);
    x_r = create_range(x, b->width);
    for (int i = y_r.start; i < y_r.end; i++) {
        for (int j = x_r.start; j < x_r.end; j++) {
            if (b->grid[i][j] && !(y == i && x == j))
                n++;
        }
    }
    return n;
}

static t_board *life_step(t_board *b)
{
    t_board *new = board_create(b->width, b->height);
    if (!new)
        return NULL;
    for (int i = 0; i < b->height; i++) {
        for (int j = 0; j < b->width; j++) {
            int n = count_neighbors(b, i, j);
            bool alive = (b->grid[i][j]);
            if (alive && (n == 2 || n == 3))
                new->grid[i][j] = 1;
            else if (!alive && n == 3)
                new->grid[i][j] = 1;
        }
    }
    return new;
}

int main(int ac, char **av) {
    if (ac != 4)
        return 1;

    t_board *b = board_create(atoi(av[1]), atoi(av[2]));
    if (!b)
        return 1;

    board_draw(b);
    for (int i = 0; i < atoi(av[3]); i++) {
        t_board *new = life_step(b);
        board_free(b);
        if (!new)
            return 1;
        b = new;
    }
    board_print(b);
    board_free(b);
    return 0;
}
