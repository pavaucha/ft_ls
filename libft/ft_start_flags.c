/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:35:46 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/27 11:14:10 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_complete_flags(const char *format,
		char c, t_flags flags, va_list ap)
{
	if (c == 'i')
		return (d_printf(flags, ap, c));
	else if (c == 'o')
		return (o_printf(flags, ap, c));
	else if (c == 'O')
		return (o_printf(flags, ap, c));
	else if (c == 'u')
		return (u_printf(flags, ap, c));
	else if (c == 'U')
		return (u_printf(flags, ap, c));
	else if (c == 'x')
		return (x_printf(flags, ap, c));
	else if (c == 'X')
		return (x_printf(flags, ap, c));
	else if (c == 'c')
		return (c_printf(flags, ap, c));
	else if (c == 'C')
		return (c_printf(flags, ap, c));
	return (-1);
}

int				ft_start_flags(const char *format,
		char c, t_flags flags, va_list ap)
{
	if (flags.pourc == 1)
		return (ft_affiche_pourc(format, flags));
	if (c == 's')
		return (s_printf(flags, ap, c));
	else if (c == 'S')
		return (s_printf(flags, ap, c));
	else if (c == 'p')
		return (p_printf(flags, ap, c));
	else if (c == 'd')
		return (d_printf(flags, ap, c));
	else if (c == 'D')
		return (d_printf(flags, ap, c));
	return (ft_complete_flags(format, c, flags, ap));
}
