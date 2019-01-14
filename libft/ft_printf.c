/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:19:12 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 14:26:11 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_champ(const char *format)
{
	int			i;
	long		count;

	count = 0;
	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		count = count * 10 + (format[i] - '0');
		i++;
	}
	return ((int)count);
}

t_flags		ft_initialise_struct(t_flags flags)
{
	flags.pourc = 0;
	flags.hash = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.intpre = 0;
	flags.intwidth = 0;
	flags.hh = 0;
	flags.h = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.j = 0;
	flags.z = 0;
	return (flags);
}

t_flags		ft_stock_flags(const char *format)
{
	t_flags		flags;

	flags = ft_initialise_struct(flags);
	flags = ft_found_flags(format, flags);
	return (flags);
}

int			ft_count_i(const char *format)
{
	int			i;

	i = 0;
	while (format[i] != 's' && format[i] != 'S' && format[i] != 'p'
		&& format[i] != 'd' && format[i] != 'D' && format[i] != 'i'
		&& format[i] != 'o' && format[i] != 'O' && format[i] != 'u'
		&& format[i] != 'U' && format[i] != 'x' && format[i] != 'X'
		&& format[i] != 'c' && format[i] != 'C' && format[i] != '\0'
		&& format[i] != '%')
		if (format[i] == 'z' || format[i] == 'j' || format[i] == 'l'
				|| format[i] == 'h' || format[i] == ' ' || format[i] == '-'
				|| format[i] == '+' || (format[i] >= '0' && format[i] <= '9')
				|| format[i] == '.' || format[i] == '#')
			i++;
		else
			return (i);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count[2];
	t_flags		flags;

	if (format == NULL)
		return (0);
	count[0] = 0;
	count[1] = 0;
	va_start(ap, format);
	while (format[count[1]])
	{
		if (format[count[1]] != '%')
		{
			count[0]++;
			ft_putchar(format[count[1]]);
			count[1]++;
		}
		if (format[count[1]] == '%')
			ft_start_printf(flags, format, ap, count);
	}
	va_end(ap);
	return (count[0]);
}
