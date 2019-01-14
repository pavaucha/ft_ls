/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_bc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:56:43 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/31 15:18:39 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				ft_count_unicode(wint_t stock)
{
	if (stock <= 127)
		return (1);
	if (stock <= 2047)
		return (2);
	if (stock <= 65535)
		return (3);
	if (stock <= 2097151)
		return (4);
	return (-1);
}

static int		ft_bcchamp_minimum(t_flags flags, wint_t stock)
{
	int			count;
	char		sign;

	count = 0;
	flags.intwidth = flags.intwidth - ft_count_unicode(stock);
	sign = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 0)
	{
		count++;
		flags.intwidth--;
		ft_putchar(sign);
	}
	return (count);
}

int				ft_affiche_bc(wint_t stock, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
	{
		count = count + ft_putchar_unicode(stock, flags);
		count = count + ft_bcchamp_minimum(flags, stock);
	}
	else
	{
		count = count + ft_bcchamp_minimum(flags, stock);
		count = count + ft_putchar_unicode(stock, flags);
	}
	return (count);
}
