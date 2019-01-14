/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:04:24 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:44:38 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i--;
	while (s[k] == '\n' || s[k] == '\t' || s[k] == ' ')
		k++;
	if (i == -1)
		str = ft_strnew(0);
	else
		str = ft_strsub(s, k, (i - k + 1));
	return (str);
}
