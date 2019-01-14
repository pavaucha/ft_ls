/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:35:37 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/10 13:15:19 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_llist				*ft_list_l_initialize(char *str,
		t_llist *next, t_llist *before)
{
	t_llist		*list;

	if (!(list = malloc(sizeof(t_llist))))
		return (NULL);
	list->next = next;
	list->before = before;
	list->str = ft_strdup(str);
	list->perm[11] = '\0';
	list->perm[10] = ' ';
	return (list);
}

t_ls				*ft_list_initialize(char *str, t_ls *next, t_ls *before)
{
	t_ls		*list;

	if (!(list = (t_ls*)malloc(sizeof(t_ls))))
		return (NULL);
	list->next = next;
	list->before = before;
	list->str = ft_strdup(str);
	return (list);
}
