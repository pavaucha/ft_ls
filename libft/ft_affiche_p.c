/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:47:53 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:08:13 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_count_p(uintmax_t stock)
{
	int		count;

	count = 0;
	while (stock > 15)
	{
		stock = stock / 16;
		count++;
	}
	return (count + 1);
}

static int		ft_pminus(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	if (c == 'X')
		ft_putstr("0X");
	else
		ft_putstr("0x");
	count = count + ft_precision(flags);
	ft_put_type(stock, c);
	count = count + ft_champ_minimum(flags);
	return (count);
}

static int		ft_pnminus(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	count = ft_champ_minimum(flags);
	if (c == 'X')
		ft_putstr("0X");
	else
		ft_putstr("0x");
	count = count + ft_precision(flags);
	ft_put_type(stock, c);
	return (count);
}

static int		ft_ch_pzero(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	if (c == 'X')
		ft_putstr("0X");
	else
		ft_putstr("0x");
	count = ft_champ_minimum(flags);
	count = count + ft_precision(flags);
	ft_put_type(stock, c);
	return (count);
}

int				ft_affiche_p(uintmax_t stock, t_flags flags, char c)
{
	int		count;

	count = 0;
	if (flags.zero == 1)
		count = ft_ch_pzero(stock, flags, c);
	else if (flags.minus == 1)
		count = ft_pminus(stock, flags, c);
	else if (flags.minus == 0)
		count = ft_pnminus(stock, flags, c);
	return (count + ft_count_p(stock) + 2);
}
