/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:17:11 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:34:28 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		a1;

	a1 = 0;
	s1 = dst;
	s2 = src;
	while (a1 < n)
	{
		s1[a1] = s2[a1];
		a1++;
	}
	return (s1);
}
