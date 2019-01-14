/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:59:49 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:06:48 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_count_other(uintmax_t stock, int base)
{
	int		count;

	count = 0;
	while (stock > (base - 1))
	{
		stock = stock / base;
		count++;
	}
	return (count + 1);
}

static int		ft_minus(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	count = count + ft_precision(flags);
	if ((c == 'o' || c == 'O') && flags.hash == 1)
		ft_putchar('0');
	ft_put_type(stock, c);
	count = count + ft_champ_minimum(flags);
	return (count);
}

static int		ft_nminus(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	count = ft_champ_minimum(flags);
	count = count + ft_precision(flags);
	if ((c == 'o' || c == 'O') && flags.hash == 1)
		ft_putchar('0');
	ft_put_type(stock, c);
	return (count);
}

int				ft_affiche(uintmax_t stock, t_flags flags, char c, int base)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count = ft_minus(stock, flags, c);
	else
		count = ft_nminus(stock, flags, c);
	if ((c == 'o' || c == 'O') && flags.hash == 1)
		count++;
	return (count + ft_count_other(stock, base));
}
