/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:00:42 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/15 12:52:25 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_put_type(uintmax_t stock, char c)
{
	if (c == 'p')
		ft_putnbr_hexa(stock, 16, c);
	if (c == 'o' || c == 'O')
		ft_putnbr_hecto(stock, 8);
	if (c == 'u' || c == 'U')
		ft_putunsigned_int(stock);
	if (c == 'x' || c == 'X')
		ft_putnbr_hexa(stock, 16, c);
}
