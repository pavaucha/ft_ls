/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:00:14 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:17:51 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	t_ls		*ft_complete_del(t_ls *list,
		t_ls *list_next, t_ls *list_before)
{
	if (list_before == NULL && list_next != NULL)
	{
		list_next->before = NULL;
		free(list);
		list = NULL;
		list = list_next;
	}
	if (list_before != NULL && list_next == NULL)
	{
		list_before->next = NULL;
		free(list);
		list = NULL;
		list = list_before;
	}
	return (list);
}

t_ls				*ft_del_list(t_ls *list)
{
	t_ls	*list_next;
	t_ls	*list_before;

	list_next = list->next;
	list_before = list->before;
	ft_strdel(&list->str);
	if (list_before != NULL && list_next != NULL)
	{
		list_before->next = list_next;
		list_next->before = list_before;
		free(list);
		list = NULL;
		list = list_next;
	}
	list = ft_complete_del(list, list_next, list_before);
	if (list_before == NULL && list_next == NULL)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	return (list);
}
