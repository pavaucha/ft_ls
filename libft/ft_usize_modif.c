/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usize_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:17:50 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/15 10:28:36 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

uintmax_t		ft_usize_modif(t_flags flags, va_list ap)
{
	if (flags.j == 1)
		return (va_arg(ap, uintmax_t));
	if (flags.ll == 1)
		return ((uintmax_t)va_arg(ap, unsigned long long int));
	if (flags.l == 1)
		return ((uintmax_t)va_arg(ap, unsigned long int));
	if (flags.z == 1)
		return ((uintmax_t)va_arg(ap, ssize_t));
	if (flags.hh == 1)
		return ((uintmax_t)((unsigned char)va_arg(ap, unsigned int)));
	if (flags.h == 1)
		return ((uintmax_t)((unsigned short int)va_arg(ap, unsigned int)));
	return ((uintmax_t)va_arg(ap, unsigned int));
}
