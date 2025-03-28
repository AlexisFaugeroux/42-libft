/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:14:07 by afaugero          #+#    #+#             */
/*   Updated: 2025/03/12 12:04:02 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(char const *nptr)
{
	int			i;
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(*(nptr + i)) && *(nptr + i))
	{
		nb = (nb * 10) + *(nptr + i) - '0';
		i++;
	}
	return ((long)(sign * nb));
}
