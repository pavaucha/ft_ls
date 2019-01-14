/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_modification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:45:41 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/15 10:27:01 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

intmax_t		ft_size_modification(t_flags flags, va_list ap)
{
	if (flags.j == 1)
		return (va_arg(ap, intmax_t));
	if (flags.ll == 1)
		return ((intmax_t)va_arg(ap, long long int));
	if (flags.l == 1)
		return ((intmax_t)va_arg(ap, long int));
	if (flags.z == 1)
		return ((intmax_t)va_arg(ap, size_t));
	if (flags.hh == 1)
		return ((intmax_t)((char)va_arg(ap, int)));
	if (flags.h == 1)
		return ((intmax_t)((short int)va_arg(ap, int)));
	return ((intmax_t)va_arg(ap, int));
}
