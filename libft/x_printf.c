/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:53:47 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/31 11:52:30 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			x_printf(t_flags flags, va_list ap, char c)
{
	uintmax_t	stock;
	int			i;

	stock = ft_usize_modif(flags, ap);
	if (stock != 0)
		flags = ft_change_flags(c, stock, flags, 16);
	if (stock == 0)
		i = ft_stock_zero(0, flags, c);
	else
	{
		if (flags.hash == 1)
			i = ft_affiche_p(stock, flags, c);
		else
			i = ft_affiche(stock, flags, c, 16);
	}
	return (i);
}
