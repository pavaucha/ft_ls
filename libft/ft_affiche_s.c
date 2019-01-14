/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:40:57 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 12:44:28 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				ft_strlen_unicode(wchar_t *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((int)str[i] <= 127)
			count++;
		else if ((int)str[i] <= 2047)
			count = count + 2;
		else if ((int)str[i] <= 65535)
			count = count + 3;
		else if ((int)str[i] <= 2097151)
			count = count + 4;
		i++;
	}
	return (count);
}

static int		ft_schamp_minimum(t_flags flags, char *str)
{
	int		count;
	char	sign;

	count = 0;
	if (flags.intpre <= ft_strlen(str) && flags.intpre > 0)
		flags.intwidth = flags.intwidth - flags.intpre;
	else
		flags.intwidth = flags.intwidth - ft_strlen(str);
	sign = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 0)
	{
		ft_putchar(sign);
		count++;
		flags.intwidth--;
	}
	return (count);
}

static int		ft_affiche_str(t_flags flags, char *str, int count)
{
	int		i;

	i = 0;
	if (flags.intpre > 1)
	{
		while (str[i] && flags.intpre > 0)
		{
			count++;
			ft_putchar(str[i]);
			flags.intpre--;
			i++;
		}
	}
	else
		while (str[i])
		{
			count++;
			ft_putchar(str[i]);
			i++;
		}
	return (count);
}

int				ft_affiche_s(char *str, t_flags flags)
{
	int		count;

	count = 0;
	if (str == NULL)
		return (ft_nullstr(flags, count));
	else if (flags.minus == 1)
	{
		count = ft_affiche_str(flags, str, count);
		count = count + ft_schamp_minimum(flags, str);
	}
	else
	{
		if (flags.intpre < 0)
			return (ft_champ_minimum(flags));
		count = count + ft_schamp_minimum(flags, str);
		count = ft_affiche_str(flags, str, count);
	}
	return (count);
}
