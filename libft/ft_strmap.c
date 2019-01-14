/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:04:05 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:40:58 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	if ((str = ft_memalloc(i + 1)) == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (f)(s[i]);
		i++;
	}
	return ((char *)(str));
}
