/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:10:17 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/06 12:23:41 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*ft_cut_time(char *str)
{
	int			i;
	char		*dst;

	i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	str = str + i;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != ':')
		i--;
	dst = ft_strnew(i);
	dst = ft_strncpy(dst, str, i);
	return (dst);
}

char				*ft_years(char *str)
{
	char		*dst;
	char		*tmp;

	dst = ft_strnew(7);
	str = str + 4;
	tmp = str + 16;
	dst = ft_strncpy(dst, str, 7);
	str = ft_strnew(4);
	str = ft_strncpy(str, tmp, 4);
	tmp = ft_strjoin(dst, " ");
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (dst);
}

t_llist				*ft_take_time(t_llist *list, char *open)
{
	time_t		now;
	char		*tmp;

	time(&now);
	open = NULL;
	while (list != NULL)
	{
		tmp = ft_strdup(ctime(&list->fd.st_mtime));
		if (now - list->fd.st_mtime > 15724800)
			list->ctime = ft_years(tmp);
		else if (list->fd.st_mtime > now)
			list->ctime = ft_strdup("Jan  1  10000");
		else
			list->ctime = ft_cut_time(tmp);
		ft_strdel(&tmp);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (list);
}

static int			ft_padding_link(t_llist *list)
{
	int			i;

	i = 0;
	while (list != NULL)
	{
		i = (ft_cmp_imax(list->fd.st_nlink) > i) ?
			ft_cmp_imax(list->fd.st_nlink) : i;
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (i);
}

t_llist				*ft_take_link(t_llist *list)
{
	int			i;
	char		*tmp;
	char		*dst;

	i = ft_padding_link(list);
	while (list->before != NULL)
		list = list->before;
	while (list != NULL)
	{
		dst = ft_uitoa((intmax_t)list->fd.st_nlink);
		tmp = ft_strnew_c(i - ft_cmp_imax(list->fd.st_nlink), ' ');
		list->link = ft_strjoin(tmp, dst);
		ft_strdel(&tmp);
		ft_strdel(&dst);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (list);
}
