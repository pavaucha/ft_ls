/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:53:22 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:44:07 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	if ((haystack[i] == needle[i]) && haystack[i] == '\0')
		return ((char*)(haystack));
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i] && needle[j] != '\0')
		{
			j++;
			i++;
		}
		if (needle[j] != '\0')
			i = k;
		if (needle[j] == '\0')
			return ((char*)(haystack + k));
		i++;
		k++;
	}
	return (0);
}
