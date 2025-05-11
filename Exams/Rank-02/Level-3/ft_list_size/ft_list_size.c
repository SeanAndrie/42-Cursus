#include "ft_list_size.h"

int ft_list_size(t_list *begin_list)
{
    int size;
    while (begin_list->next)
    {
        size++;
        begin_list = begin_list->next;
    }
    return(size);
}
