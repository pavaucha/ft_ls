/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:07:06 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 18:29:50 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags		ft_fflags(const char *format, t_flags flags)
{
	if (format[0] == '0' && flags.minus == 0)
		flags.zero = 1;
	if (format[0] == '#')
		flags.hash = 1;
	if (format[0] == '-')
	{
		flags.minus = 1;
		flags.zero = 0;
	}
	if (format[0] == '+')
	{
		flags.space = 0;
		flags.plus = 1;
	}
	if (flags.plus == 0 && format[0] == ' ')
		flags.space = 1;
	if (format[0] == '%')
		flags.pourc = 1;
	return (flags);
}

t_flags		ft_precha(const char *format, t_flags flags)
{
	if (format[0] > '0' && format[0] <= '9')
		flags.intwidth = ft_champ(format);
	if (format[0] == '.')
	{
		if (ft_champ(format + 1) == 0 && flags.intpre == 0)
			flags.intpre = -1;
		else
			flags.intpre = ft_champ(format + 1);
	}
	return (flags);
}

t_flags		ft_sflags(const char *format, t_flags flags)
{
	if (format[0] == 'j')
		flags.j = 1;
	if (format[0] == 'z')
		flags.z = 1;
	if (format[0] == 'l' && format[1] != 'l')
		flags.l = 1;
	if (format[0] == 'h' && format[1] != 'h')
		flags.h = 1;
	if (format[0] == 'h' && format[1] == 'h')
		flags.hh = 1;
	if (format[0] == 'l' && format[1] == 'l')
		flags.ll = 1;
	return (flags);
}

int			ft_evolution_i(const char *format)
{
	int		i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else if (format[i] > '0' && format[i] <= '9')
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	else if ((format[i] == 'h' && format[i + 1] == 'h')
			|| (format[i] == 'l' && format[i + 1] == 'l'))
		i = i + 2;
	else
		i++;
	return (i);
}

t_flags		ft_found_flags(const char *format, t_flags flags)
{
	int		i;

	i = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
			|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
			|| format[i] == 'h' || format[i] == 'l' || format[i] == 'z'
			|| (format[i] > '0' && format[i] <= '9') || format[i] == 'j')
	{
		flags = ft_fflags(format + i, flags);
		flags = ft_precha(format + i, flags);
		flags = ft_sflags(format + i, flags);
		i = i + ft_evolution_i(format + i);
	}
	return (flags);
}
