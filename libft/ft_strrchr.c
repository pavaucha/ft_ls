/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:34:18 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:43:26 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;

	a = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			a = i;
		i++;
	}
	if (a != -1)
		return ((char*)(s + a));
	if (c == '\0')
		return ((char*)(s + i));
	return (0);
}
