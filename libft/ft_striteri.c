/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:01:15 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:40:04 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			j;

	j = 0;
	if ((*f) == NULL)
		return ;
	if (s == NULL)
		return ;
	while (s[j])
	{
		(f)(j, (s + j));
		j++;
	}
}
