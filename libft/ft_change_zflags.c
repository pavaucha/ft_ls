/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_zflags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:29:59 by pavaucha          #+#    #+#             */
/*   Updated: 2018/01/30 18:39:00 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags		ft_change_zflags(t_flags flags, char c)
{
	if (flags.intpre > 0)
		flags.zero = 0;
	if (flags.intpre > 0)
		flags.intpre--;
	if (flags.intwidth > 0)
		flags.intwidth = flags.intwidth - flags.intpre - 1;
	if (flags.plus == 1 && c != 'p' && (c != 'o' || c != 'O'))
		flags.intwidth--;
	if (flags.space == 1)
		flags.intwidth--;
	if (c == 'p')
		flags.intwidth = flags.intwidth - 2;
	return (flags);
}
