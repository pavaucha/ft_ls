/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_bs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:31:38 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 16:52:37 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_sbchamp_minimum(t_flags flags, wchar_t *str)
{
	int		count;
	char	sign;

	count = 0;
	if (flags.intpre <= ft_strlen_unicode(str) && flags.intpre > 0)
		flags.intwidth = flags.intwidth - flags.intpre;
	else
		flags.intwidth = flags.intwidth - ft_strlen_unicode(str);
	sign = (flags.zero == 1) ? '0' : ' ';
	while (flags.intwidth > 0)
	{
		ft_putchar(sign);
		count++;
		flags.intwidth--;
	}
	return (count);
}

static int		ft_affiche_bstr(t_flags flags, wchar_t *str, int count)
{
	int		i;

	i = 0;
	if (flags.intpre > 0)
	{
		while (str[i] && flags.intpre >= ft_count_unicode((wint_t)str[i]))
		{
			count = count + ft_count_unicode((wint_t)str[i]);
			flags.intpre = flags.intpre - ft_count_unicode((wint_t)str[i]);
			ft_putchar_unicode((wint_t)str[i], flags);
			i++;
		}
	}
	else
		while (str[i])
		{
			count = count + ft_count_unicode((wint_t)str[i]);
			ft_putchar_unicode((wint_t)str[i], flags);
			i++;
		}
	return (count);
}

static int		ft_nominus(t_flags flags, int i, wchar_t *str, int count)
{
	int		j;

	j = 0;
	if (flags.intpre < 0)
	{
		count = ft_champ_minimum(flags);
		return (count);
	}
	while (i >= ft_count_unicode((wint_t)str[j]))
	{
		i = i - ft_count_unicode((wint_t)str[j]);
		j++;
	}
	if (i > 0)
		flags.intwidth = flags.intwidth + i;
	count = count + ft_sbchamp_minimum(flags, str);
	count = ft_affiche_bstr(flags, str, count);
	return (count);
}

int				ft_affiche_bs(wchar_t *str, t_flags flags)
{
	int		count;
	int		i;

	count = 0;
	i = flags.intpre;
	if (str == NULL)
		return (ft_nullstr(flags, count));
	else if (flags.minus == 1)
	{
		if (ft_affiche_bstr(flags, str, count) == 0)
			flags.intwidth = flags.intwidth + flags.intpre;
		else
			count = ft_affiche_bstr(flags, str, count);
		count = count + ft_sbchamp_minimum(flags, str);
	}
	else
		count = ft_nominus(flags, i, str, count);
	return (count);
}
