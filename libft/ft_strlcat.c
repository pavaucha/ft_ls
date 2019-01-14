/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:36:56 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:40:29 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;
	size_t	max;

	k = 0;
	j = 0;
	max = 0;
	while (dst[max])
		max++;
	while (src[k])
		k++;
	if (size < (max + 1))
		return (k + size);
	else
	{
		while ((j < (size - max - 1)) && src[j])
		{
			dst[max + j] = src[j];
			j++;
		}
		dst[max + j] = '\0';
		return (k + max);
	}
}
