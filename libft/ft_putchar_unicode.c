/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:06:29 by pavaucha          #+#    #+#             */
/*   Updated: 2018/02/06 14:56:18 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_putchar_unicode_bis(t_flags flags, wint_t stock)
{
	ft_putchar((stock >> 18) + 0xF0);
	ft_putchar(((stock >> 12) & 0x3F) + 0x80);
	ft_putchar(((stock >> 6) & 0x3F) + 0x80);
	ft_putchar((stock & 0x3F) + 0x80);
	return (4);
}

int				ft_putchar_unicode(wint_t stock, t_flags flags)
{
	if (stock <= 127)
	{
		ft_putchar(stock);
		return (1);
	}
	else if (stock > 127 && stock <= 2047)
	{
		ft_putchar((stock >> 6) + 0xC0);
		ft_putchar((stock & 0x3F) + 0x80);
		return (2);
	}
	else if (stock > 2047 && stock <= 65535)
	{
		ft_putchar((stock >> 12) + 0xE0);
		ft_putchar(((stock >> 6) & 0x3F) + 0x80);
		ft_putchar((stock & 0x3F) + 0x80);
		return (3);
	}
	else if (stock > 65535 && stock <= 2097151)
		ft_putchar_unicode_bis(flags, stock);
	return (-1);
}
