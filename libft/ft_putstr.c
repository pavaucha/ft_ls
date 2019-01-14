/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:38:08 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:37:06 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
