/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uid_grp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:53:21 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:20:30 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_padding_grp(t_llist *list)
{
	size_t			i;

	i = 0;
	while (list != NULL)
	{
		i = (ft_strlen(list->grp) > i) ? ft_strlen(list->grp) : i;
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return ((int)i);
}

static int		ft_padding_puid(t_llist *list)
{
	size_t			i;

	i = 0;
	while (list != NULL)
	{
		i = (ft_strlen(list->uid) > i) ? ft_strlen(list->uid) : i;
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return ((int)i);
}

static t_llist	*ft_creat_uid_grp(t_llist *list,
				size_t p_uid, char *tmp, char *dst)
{
	ft_strdel(&tmp);
	ft_strdel(&dst);
	dst = ft_strdup(list->uid);
	tmp = ft_strnew_c(p_uid - ft_strlen(dst), ' ');
	if (ft_strlen(dst) < p_uid)
	{
		ft_strdel(&list->uid);
		list->uid = ft_strjoin(dst, tmp);
	}
	ft_strdel(&tmp);
	ft_strdel(&dst);
	return (list);
}

t_llist			*ft_str_uid_grp(t_llist *list)
{
	size_t			p_uid;
	size_t			p_grp;
	char			*tmp;
	char			*dst;

	p_uid = (size_t)ft_padding_puid(list);
	p_grp = (size_t)ft_padding_grp(list);
	while (list != NULL)
	{
		dst = ft_strdup(list->grp);
		tmp = ft_strnew_c(p_grp - ft_strlen(dst), ' ');
		if (ft_strlen(dst) < p_grp)
		{
			ft_strdel(&list->grp);
			list->grp = ft_strjoin(dst, tmp);
		}
		list = ft_creat_uid_grp(list, p_uid, dst, tmp);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (list);
}
