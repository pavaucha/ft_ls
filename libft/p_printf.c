/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:40:20 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 16:41:03 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		p_printf(t_flags flags, va_list ap, char c)
{
	uintmax_t		stock;
	int				i;

	stock = (uintmax_t)va_arg(ap, uintptr_t);
	if (stock != 0)
		flags = ft_change_flags(c, stock, flags, 16);
	if (stock == 0)
		i = ft_stock_zero(0, flags, c);
	else
		i = ft_affiche_p(stock, flags, c);
	return (i);
}
