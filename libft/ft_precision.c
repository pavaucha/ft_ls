/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:38:02 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 14:28:22 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_space(t_flags flags)
{
	if (flags.space == 1)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		ft_plus(t_flags flags, intmax_t stock)
{
	if (flags.plus == 1 && stock >= 0)
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}

int		ft_precision(t_flags flags)
{
	int		count;

	count = 0;
	while (flags.intpre > 0)
	{
		ft_putchar('0');
		count++;
		flags.intpre--;
	}
	return (count);
}
