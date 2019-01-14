/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:53:20 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 16:40:53 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		o_printf(t_flags flags, va_list ap, char c)
{
	uintmax_t		stock;
	int				i;

	if (c == 'O')
		flags.l = 1;
	stock = ft_usize_modif(flags, ap);
	if (stock != 0)
		flags = ft_change_flags(c, stock, flags, 8);
	if (stock == 0)
		i = ft_stock_zero(0, flags, c);
	else
		i = ft_affiche(stock, flags, c, 8);
	return (i);
}
