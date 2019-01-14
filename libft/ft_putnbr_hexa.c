/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:57:02 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/15 13:05:35 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr_hexa(uintmax_t i, int base, char c)
{
	if (i >= base)
	{
		ft_putnbr_hexa(i / base, base, c);
		ft_putnbr_hexa(i % base, base, c);
	}
	if (i < 10)
		ft_putchar(i + '0');
	else if (i > 9 && i < 16)
	{
		if (c == 'X')
			ft_putchar(i - 10 + 'A');
		else
			ft_putchar(i - 10 + 'a');
	}
}
