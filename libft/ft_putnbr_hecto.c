/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:57:02 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/15 10:26:05 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr_hecto(uintmax_t i, int base)
{
	if (i >= base)
	{
		ft_putnbr_hecto(i / base, base);
		ft_putnbr_hecto(i % base, base);
	}
	if (i < base)
		ft_putchar(i + '0');
}
