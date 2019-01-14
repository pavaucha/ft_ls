/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:47:18 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:29:14 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	if (nb <= 92682)
		i = (nb / 2) + 1;
	else
		i = 46341;
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int			ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_prime(nb) == 1)
		return (nb);
	else
		while (ft_prime(nb) != 1)
			nb++;
	return (nb);
}
