/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:47:45 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:32:00 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_size_n(int n)
{
	size_t		i;
	long int	m;

	m = n;
	i = 0;
	if (m < 0)
	{
		m = -m;
		i++;
	}
	while (m > 9)
	{
		m = (m / 10);
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long int	temp;
	char		*str;
	size_t		i;

	temp = n;
	i = ft_size_n(n);
	if ((str = ft_strnew(i + 1)) == 0)
		return (0);
	str[i + 1] = '\0';
	if (temp < 0)
	{
		str[0] = '-';
		temp = -temp;
	}
	while (temp > 9)
	{
		str[i] = ((temp % 10) + '0');
		temp = (temp / 10);
		i--;
	}
	str[i] = (temp + '0');
	return (str);
}
