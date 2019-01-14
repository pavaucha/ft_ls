/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:10:05 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:33:49 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;
	size_t				i;

	i = 0;
	s1 = dst;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char)(c))
			return (s1 + ++i);
		i++;
	}
	return (NULL);
}
