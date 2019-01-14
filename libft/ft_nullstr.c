/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:14:00 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 15:05:59 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_nullaffiche(t_flags flags, int count)
{
	if (flags.intpre == 0)
	{
		flags.intwidth = flags.intwidth - 6;
		count = count + 6;
	}
	count = count + ft_champ_minimum(flags);
	ft_putstr("(null)");
	return (count);
}

static int		ft_nullnminus(t_flags flags, int count, int i, char *str)
{
	if (flags.intpre != 0)
	{
		if (flags.intwidth > 0)
			count = count + ft_champ_minimum(flags);
		if (flags.intpre > 6)
		{
			flags.intpre = flags.intpre - 6;
			count = count + ft_precision(flags);
			flags.intpre = flags.intpre + 6;
		}
		while (flags.intpre > 0 && i < 6)
		{
			ft_putchar(str[i]);
			i++;
			flags.intpre--;
			count++;
		}
	}
	else
		count = count + ft_nullaffiche(flags, count);
	return (count);
}

static int		ft_nullminus(t_flags flags, int count, int i, char *str)
{
	if (flags.intpre != 0)
	{
		while (flags.intpre > 0 && i < 6)
		{
			ft_putchar(str[i]);
			i++;
			flags.intpre--;
			count++;
		}
		if (flags.intpre > 0)
			count = count + ft_precision(flags);
		if (flags.intwidth > 0)
			count = count + ft_champ_minimum(flags);
	}
	else
	{
		flags.intwidth = flags.intwidth - 6;
		count = 6;
		ft_putstr("(null)");
		count = count + ft_champ_minimum(flags);
	}
	return (count);
}

int				ft_nullstr(t_flags flags, int count)
{
	int		i;

	i = 0;
	if (flags.intpre > 0)
		flags.intwidth = flags.intwidth - flags.intpre;
	if (flags.minus == 1)
		count = ft_nullminus(flags, count, i, "(null)");
	if (flags.minus == 0)
		count = ft_nullnminus(flags, count, i, "(null)");
	return (count);
}
