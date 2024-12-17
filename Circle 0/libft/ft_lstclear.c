
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *curr;
    t_list *next;

    if (!lst || !*lst || !del)
        return ;
    curr = *lst;
    while (curr)
    {
        next = curr->next;
        del(curr->content);
        free(curr);
        curr = next;
    }
    *lst = NULL;
}
