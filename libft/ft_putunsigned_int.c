/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:14:46 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/17 12:03:01 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putunsigned_int(uintmax_t i)
{
	if (i >= 10)
	{
		ft_putunsigned_int(i / 10);
		ft_putunsigned_int(i % 10);
	}
	if (i < 10)
		ft_putchar(i + '0');
}
