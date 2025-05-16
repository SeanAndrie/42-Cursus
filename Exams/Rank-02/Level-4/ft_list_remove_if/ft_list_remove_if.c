#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list **curr = begin_list;
    
    while (*curr)
    {
        t_list *entry = *curr;
        if (!cmp(entry->data, data_ref))
            *curr = entry->next, free(entry);
        else
            curr = &entry->next; 
    }
}
