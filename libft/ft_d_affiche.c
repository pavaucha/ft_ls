/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_affiche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:00:18 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:11:28 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_count_d(intmax_t stock)
{
	int		count;

	count = 0;
	if (stock == -9223372036854775807 - 1)
		return (19);
	else if (stock < 0)
		stock = -stock;
	while (stock > 9)
	{
		stock = stock / 10;
		count++;
	}
	return (count + 1);
}

static int		ft_d_minus(intmax_t stock, t_flags flags)
{
	int		count;

	count = 0;
	if (stock >= 0)
		count = count + ft_space(flags);
	count = count + ft_plus(flags, stock);
	if (stock < 0)
		ft_putchar('-');
	count = count + ft_precision(flags);
	ft_putnbr_max(stock);
	count = count + ft_champ_minimum(flags);
	return (count);
}

static int		ft_d_nminus(intmax_t stock, t_flags flags)
{
	int		count;

	count = 0;
	count = count + ft_champ_minimum(flags);
	if (stock >= 0)
		count = count + ft_space(flags);
	count = count + ft_plus(flags, stock);
	if (stock < 0)
		ft_putchar('-');
	count = count + ft_precision(flags);
	ft_putnbr_max(stock);
	return (count);
}

static int		ft_ch_zero(intmax_t stock, t_flags flags)
{
	int		count;

	count = 0;
	if (stock >= 0)
		count = count + ft_space(flags);
	count = count + ft_plus(flags, stock);
	if (stock < 0)
		ft_putchar('-');
	count = count + ft_champ_minimum(flags);
	count = count + ft_precision(flags);
	ft_putnbr_max(stock);
	return (count);
}

int				ft_affiche_d(intmax_t stock, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.zero == 1)
		count = ft_ch_zero(stock, flags);
	else if (flags.minus == 1)
		count = ft_d_minus(stock, flags);
	else if (flags.minus == 0)
		count = ft_d_nminus(stock, flags);
	if (stock < 0)
		count++;
	return (count + ft_count_d(stock));
}
