/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:03:03 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/31 14:53:21 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		c_printf(t_flags flags, va_list ap, char c)
{
	int			count;
	int			stock;
	wint_t		i;

	count = 0;
	if (c == 'C')
		flags.l = 1;
	if (flags.l == 1)
	{
		i = va_arg(ap, wint_t);
		count = ft_affiche_bc(i, flags);
	}
	else
	{
		stock = (char)va_arg(ap, int);
		count = ft_affiche_c(stock, flags);
	}
	return (count);
}
