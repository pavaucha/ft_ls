/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:16:02 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 12:12:36 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_minus_stock(int stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	if (c != 'p' && c != 'o' && c != 'O')
		count = ft_plus(flags, 0);
	if (c == 'p')
	{
		ft_putstr("0x");
		count = count + 2;
	}
	count = count + ft_precision(flags);
	ft_putchar('0');
	count++;
	count = count + ft_champ_minimum(flags);
	return (count);
}

static int		ft_nminus_stock(int stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	count = ft_champ_minimum(flags);
	count = count + ft_space(flags);
	if (c != 'p' && c != 'o' && c != 'O')
		count = count + ft_plus(flags, 0);
	if (c == 'p')
	{
		ft_putstr("0x");
		count = count + 2;
	}
	count = count + ft_precision(flags);
	count++;
	ft_putchar('0');
	return (count);
}

static int		ft_affiche_flags(t_flags flags, char c, int count)
{
	if (flags.minus == 1)
	{
		count = count + ft_space(flags);
		if (c != 'p' && c != 'o' && c != 'O')
			count = count + ft_plus(flags, 0);
		if (c == 'p')
		{
			ft_putstr("0x");
			count = count + 2;
		}
		count = count + ft_precision(flags);
		count = count + ft_champ_minimum(flags);
		if ((c == 'o' || c == 'O') && flags.hash == 1)
		{
			ft_putchar('0');
			count++;
		}
	}
	else
		count = ft_stock_zflags(flags, c, count);
	return (count);
}

static int		ft_zero(t_flags flags, char c)
{
	int		count;

	count = 0;
	count = count + ft_space(flags);
	if (c != 'p' && c != 'o' && c != 'O')
		count = count + ft_plus(flags, 0);
	if (c == 'p')
	{
		ft_putstr("0x");
		count = count + 2;
	}
	count = count + ft_champ_minimum(flags);
	count = count + ft_precision(flags);
	count++;
	ft_putchar('0');
	return (count);
}

int				ft_stock_zero(int stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	flags = ft_change_zflags(flags, c);
	if (flags.zero == 1)
		count = ft_zero(flags, c);
	else if (flags.intpre == -1)
		count = ft_affiche_flags(flags, c, count);
	else if (flags.minus == 1)
		count = ft_minus_stock(stock, flags, c);
	else
		count = ft_nminus_stock(stock, flags, c);
	return (count);
}
