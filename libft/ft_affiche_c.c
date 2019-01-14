/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:21:46 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:05:53 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_cchamp_minimum(t_flags flags, int stock)
{
	int		count;
	char	sign;

	count = 0;
	flags.intwidth = flags.intwidth - 1;
	sign = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 0)
	{
		count++;
		flags.intwidth--;
		ft_putchar(sign);
	}
	return (count);
}

int				ft_affiche_c(int stock, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
	{
		ft_putchar(stock);
		count++;
		count = count + ft_cchamp_minimum(flags, stock);
	}
	else
	{
		count = count + ft_cchamp_minimum(flags, stock);
		ft_putchar(stock);
		count++;
	}
	return (count);
}
