/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:43:27 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/23 14:24:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*curr;
	t_list	*next;
	int		sorted;

	if (!lst)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		curr = lst;
		while (curr->next)
		{
			next = curr->next;
			if (cmp(curr->content, next->content) > 0)
			{
				ft_memswap(&(curr->content), &(next->content));
				sorted = 0;
			}
			curr = curr->next;
		}
	}
}
