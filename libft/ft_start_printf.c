/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:50:01 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 14:41:15 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_start_printf(t_flags flags, const char *format,
		va_list ap, int count[2])
{
	int		j;
	int		i;

	count[1]++;
	j = count[1];
	count[1] = count[1] + ft_count_i(format + count[1]);
	i = count[1];
	if (format[i] != 's' && format[i] != 'S' && format[i] != 'p'
			&& format[i] != 'd' && format[i] != 'D' && format[i] != 'i'
			&& format[i] != 'o' && format[i] != 'O' && format[i] != 'u'
			&& format[i] != 'U' && format[i] != 'x' && format[i] != 'X'
			&& format[i] != 'c' && format[i] != 'C')
	{
		count[0] = count[0] + ft_affiche_pourc(format + j,
				ft_stock_flags(format + j));
		format[i] != '\0' ? i++ : i;
	}
	else
	{
		count[0] = count[0] + ft_start_flags(format + j, (format + j
				+ ft_count_i(format + j))[0], ft_stock_flags(format + j), ap);
		format[i] != '\0' ? i++ : i;
	}
	count[1] = i;
}
