/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:33:48 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 20:56:46 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_cmp_imax(intmax_t nb)
{
	int		i;

	i = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 10)
		i++;
	return (i);
}

char		*ft_uitoa(intmax_t nb)
{
	char	*str;
	int		i;

	i = ft_cmp_imax(nb);
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (nb < 10)
		str[i] = nb + '0';
	return (str);
}
