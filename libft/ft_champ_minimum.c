/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champ_minimum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:42:46 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 18:03:02 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_champ_minimum(t_flags flags)
{
	int		count;
	char	sign;

	count = 0;
	sign = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 0)
	{
		ft_putchar(sign);
		count++;
		flags.intwidth--;
	}
	return (count);
}
