/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:22:26 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:19:59 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_strnew_c(int size, char c)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = c;
	str[size] = '\0';
	return (str);
}
