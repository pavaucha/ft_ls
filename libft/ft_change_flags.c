/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:48:02 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:29:46 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static t_flags	ft_place(t_flags flags, char c)
{
	if (c == 'o' || c == 'O')
	{
		flags.intwidth--;
		flags.intpre = (flags.intpre > 0) ?
			flags.intpre = flags.intpre - 1 : flags.intpre;
	}
	else
		flags.intwidth = flags.intwidth - 2;
	return (flags);
}

t_flags			ft_change_flags(char c, uintmax_t stock,
		t_flags flags, int base)
{
	int		count;

	count = 1;
	if (flags.intpre != 0)
		flags.zero = 0;
	while (stock > (base - 1))
	{
		stock = stock / base;
		count++;
	}
	if (count >= flags.intpre)
		flags.intwidth = flags.intwidth - flags.space - flags.plus - count;
	else if (count < flags.intpre)
		flags.intwidth = flags.intwidth - flags.space - flags.plus
			- flags.intpre;
	if (flags.intpre > 0)
		flags.intpre = flags.intpre - count;
	if (c == 'p' || ((c == 'x' || c == 'X' ||
					c == 'o' || c == 'O') && flags.hash == 1))
		flags = ft_place(flags, c);
	return (flags);
}

t_flags			ft_change_flags_d(intmax_t stock, t_flags flags)
{
	int		count;

	count = (stock < 0) ? 2 : 1;
	if (flags.intpre != 0)
		flags.zero = 0;
	while (stock > 9 || stock < -9)
	{
		stock = stock / 10;
		count++;
	}
	if (count >= flags.intpre)
		flags.intwidth = (stock > 0) ? flags.intwidth - flags.space - flags.plus
			- count : flags.intwidth - flags.space - count;
	else if (count < flags.intpre)
		flags.intwidth = (stock > 0) ? flags.intwidth
			- flags.space - flags.plus - flags.intpre
			: flags.intwidth - flags.space - flags.intpre;
	if (flags.intpre >= count && stock < 0)
		flags.intwidth--;
	if (stock < 0)
		count--;
	if (flags.intpre > 0)
		flags.intpre = flags.intpre - count;
	return (flags);
}
