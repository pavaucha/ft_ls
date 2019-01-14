/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:58:17 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:39:53 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t		i;

	i = 0;
	if ((*f) == NULL)
		return ;
	if (s == NULL)
		return ;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
