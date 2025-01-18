/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:43:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/18 18:58:13 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    ft_lstsort(t_list **head, int (*cmp)(void *, void *))
{
    t_list *curr;
    t_list *next;
    t_list *prev;

    if (head == NULL || *head == NULL)
        return;
    curr = *head;
    prev = NULL;
    while (curr->next != NULL)
    {
        next = curr->next;
        if (cmp(curr->content, next->content) > 0)
        {
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
            if (curr == *head)
                *head = next;
            curr = *head;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

