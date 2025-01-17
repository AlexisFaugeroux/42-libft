/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:13 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 17:52:49 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool ft_is_sort(void **tab, size_t length, int(*cmp)(void *, void *))
{
    size_t i;

    if (!tab || !cmp || length == 0)
        return (false);
    if (length == 1)
        return (true);
    i = 0;
    while (i < length - 1)
    {
        if (cmp(tab[i], tab[i + 1]) > 0)
            return (false);
        else if (cmp(tab[i], tab[i + 1]) < 0)
            return (false);
        i++;
    }
    return (true);
}
