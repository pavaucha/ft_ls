/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:53:34 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 16:41:17 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		u_printf(t_flags flags, va_list ap, char c)
{
	uintmax_t		stock;
	int				i;

	if (c == 'U')
		flags.l = 1;
	stock = ft_usize_modif(flags, ap);
	if (stock != 0)
		flags = ft_change_flags(c, stock, flags, 10);
	if (stock == 0)
		i = ft_stock_zero(0, flags, c);
	else
		i = ft_affiche(stock, flags, c, 10);
	return (i);
}
