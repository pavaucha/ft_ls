/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:49:00 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/31 13:38:55 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		s_printf(t_flags flags, va_list ap, char c)
{
	int		count;
	char	*str;
	wchar_t	*lstr;

	count = 0;
	if (c == 'S')
		flags.l = 1;
	if (flags.l == 1)
	{
		lstr = va_arg(ap, wchar_t*);
		count = ft_affiche_bs(lstr, flags);
	}
	else
	{
		str = va_arg(ap, char*);
		count = ft_affiche_s(str, flags);
	}
	return (count);
}
