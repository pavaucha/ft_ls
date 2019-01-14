/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 04:41:03 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:18:19 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_llist	*ft_free_next(t_llist *list, t_llist *l_del)
{
	list = list->next;
	ft_strdel(&l_del->str);
	ft_strdel(&l_del->str_o);
	ft_strdel(&l_del->uid);
	ft_strdel(&l_del->grp);
	ft_strdel(&l_del->ctime);
	ft_strdel(&l_del->link);
	free(l_del);
	l_del = NULL;
	return (list);
}

t_llist			*ft_free_llist(t_llist *list)
{
	t_llist		*l_del;

	l_del = list;
	if (list->next != NULL)
		return (ft_free_next(list, l_del));
	else
	{
		ft_strdel(&list->str);
		ft_strdel(&list->str_o);
		ft_strdel(&list->uid);
		ft_strdel(&list->grp);
		ft_strdel(&list->ctime);
		ft_strdel(&list->link);
		free(list);
		list = NULL;
	}
	return (list);
}

t_ls			*ft_free_list(t_ls *list)
{
	t_ls	*l_del;

	l_del = list;
	if (list->next != NULL)
	{
		list = list->next;
		ft_strdel(&l_del->str);
		l_del->before = NULL;
		l_del->next = NULL;
		free(l_del);
		l_del = NULL;
		return (list);
	}
	else
	{
		ft_strdel(&list->str);
		list->before = NULL;
		free(list);
		list = NULL;
	}
	return (list);
}
