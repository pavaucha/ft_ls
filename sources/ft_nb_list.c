/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:41:42 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:18:49 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int						ft_nb_list(t_llist *list)
{
	int			i;

	i = 1;
	if (list == NULL)
		return (0);
	while (list->next != NULL)
	{
		list = list->next;
		i++;
	}
	if (i > 1)
		i++;
	while (list->before != NULL)
		list = list->before;
	return (i);
}
