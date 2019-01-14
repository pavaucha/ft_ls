/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_pourc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:07:13 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 11:09:00 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_nominus(const char *format, t_flags flags, int i, int count)
{
	char		c;

	c = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 1)
	{
		count++;
		ft_putchar(c);
		flags.intwidth--;
	}
	ft_putchar(format[i]);
	count++;
	return (count);
}

static int	ft_minus(const char *format, t_flags flags, int i, int count)
{
	char		c;

	ft_putchar(format[i]);
	count++;
	while (flags.intwidth > 1)
	{
		count++;
		ft_putchar(' ');
		flags.intwidth--;
	}
	return (count);
}

int			ft_affiche_pourc(const char *format, t_flags flags)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (format[i] == 's' || format[i] == 'S' || format[i] == 'p'
		|| format[i] == 'd' || format[i] == 'D' || format[i] == 'i'
		|| format[i] == 'o' || format[i] == 'O' || format[i] == 'u'
		|| format[i] == 'U' || format[i] == 'x' || format[i] == 'X'
		|| format[i] == 'c' || format[i] == 'C' || format[i] == 'z'
		|| format[i] == 'j' || format[i] == 'l' || format[i] == 'h'
		|| format[i] == ' ' || format[i] == '-' || format[i] == '+'
		|| (format[i] >= '0' && format[i] <= '9') || format[i] == '.'
		|| format[i] == '#')
		i++;
	if (flags.minus == 0 && format[i] != '\0')
		count = ft_nominus(format, flags, i, count);
	else if (format[i] != '\0' && flags.minus == 1)
		count = ft_minus(format, flags, i, count);
	return (count);
}
