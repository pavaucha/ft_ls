/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_zflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:07:52 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 12:12:45 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_stock_zflags(t_flags flags, char c, int count)
{
	count = count + ft_champ_minimum(flags);
	count = count + ft_space(flags);
	if (c != 'p' && c != 'o' && c != 'O')
		count = count + ft_plus(flags, 0);
	if (c == 'p')
	{
		ft_putstr("0x");
		count = count + 2;
	}
	count = count + ft_precision(flags);
	if ((c == 'o' || c == 'O') && flags.hash == 1)
	{
		ft_putchar('0');
		count++;
	}
	return (count);
}
