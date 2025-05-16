#include "test.h"

t_list *create_node(int data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void    append_node(t_list **head, t_list *node)
{
    t_list *last;
    
    if (!node)
        return ;
    if (!*head)
    {
        *head = node;
        return ;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = node;
}

void    free_list(t_list *head)
{
    t_list *next;

    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
    free(head);
}

t_list *create_list(int *tab, int size)
{
    int i = 0;
    t_list *node;
    t_list *head = NULL;
    
    if (size == 0)
        return (NULL);
    while (i < size)
    {
        node = create_node(tab[i]);
        if (!node)
            return (free_list(head), NULL);
        append_node(&head, node);
        i++;
    }
    return (head);
}

void    print_list(t_list *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
        if (head)
            printf(" -> ");
    }
    printf("\n");
}

void ft_swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int ascending(int a, int b)
{
    return (a <= b);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    if (!lst || !lst->next)
        return (NULL);
    int swapped = 1;
    t_list *curr, *bubble = NULL;
    while (swapped)
    {
        curr = lst, swapped = 0;
        while (curr->next != bubble)
        {
            if (!cmp(curr->data, curr->next->data))
                ft_swap(&curr->data, &curr->next->data), swapped = 1;
            curr = curr->next;
        }
        bubble = curr;
    }
    lst = curr;
    return (lst);
}

void    print_int_array(int *tab, unsigned int size)
{
    unsigned int i = 0;
    while (i < size)
        printf("%d ", tab[i++]);
}

void sort_int_tab(int *tab, unsigned int size)
{
    if (!tab || size == 0)
        return ;
    int swapped = 0;
    unsigned int i = 0;
    while (i < size - 1)
    {
        unsigned int j = 0;
        swapped = 0;
        while (j < (size - i - 1))
        {
            if (tab[j] > tab[j + 1])
                ft_swap(&tab[j], &tab[j + 1]), swapped = 1;
            j++;
        }
        if (!swapped)
            break;
        i++;
    }
}

#include <stdio.h>

int main(void)
{
    t_list *head;
    int tab[] = {0, 2, 4, 1, 5};
    head = create_list(tab, 5);
    if (!head)
        return (1);
    sort_list(head, ascending);
    sort_int_tab(tab, (unsigned int)5);
    print_list(head);
    print_int_array(tab, (unsigned int)5);

    return (0);
}
