/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:39:34 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:30:04 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	long int	j;
	int			k;

	k = 1;
	i = 0;
	j = 0;
	if (str[i] == '\200')
		return (0);
	while (str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10;
		j = j + (str[i] - 48);
		i++;
	}
	return (j * k);
}
