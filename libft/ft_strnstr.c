/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:59:23 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:42:46 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	k = 0;
	i = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (needle[j] == haystack[i] && needle[j] != '\0' && j != len)
		{
			j++;
			i++;
		}
		if (i > len)
			return (0);
		if (needle[j] == '\0')
			return ((char*)(haystack + k));
		i = k;
		i++;
	}
	return (0);
}
