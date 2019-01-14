/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:10:37 by pavaucha          #+#    #+#             */
/*   Updated: 2018/03/20 15:15:05 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void		*str;
	size_t		i;

	i = 0;
	if ((str = (void*)malloc(sizeof(void) * size)) == 0)
		return (NULL);
	while (i < size)
	{
		*(char*)(str + i) = '\0';
		i++;
	}
	return (str);
}
