/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:08:15 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 16:40:26 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		d_printf(t_flags flags, va_list ap, char c)
{
	intmax_t		stock;
	int				i;

	if (c == 'D')
		flags.l = 1;
	stock = ft_size_modification(flags, ap);
	if (stock != 0)
		flags = ft_change_flags_d(stock, flags);
	if (stock == 0)
		i = ft_stock_zero(0, flags, c);
	else
		i = ft_affiche_d(stock, flags);
	return (i);
}
