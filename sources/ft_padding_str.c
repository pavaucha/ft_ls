/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:56:00 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 20:57:46 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void				ft_complete_str(t_llist *list, char *open)
{
	char		buf[2048];
	char		*tmp;
	char		*dst;

	while (list != NULL)
	{
		ft_printf("%s ", list->perm);
		ft_printf("%s ", list->link);
		ft_printf("%s  ", list->uid);
		ft_printf("%s  ", list->grp);
		ft_printf("%s ", list->str_o);
		ft_printf("%s ", list->ctime);
		ft_printf("%s", list->str);
		if (list->perm[0] == 'l')
		{
			tmp = ft_strjoin("/", list->str);
			dst = ft_strjoin(open, tmp);
			readlink(dst, buf, sizeof(buf) - 1);
			ft_printf(" -> %s", &buf[0]);
			ft_strdel(&tmp);
			ft_strdel(&dst);
		}
		ft_printf("\n");
		list = ft_free_llist(list);
	}
}

static t_llist			*ft_maj_min(t_llist *list)
{
	while (list != NULL)
	{
		if (list->perm[0] == 'c' || list->perm[0] == 'b')
		{
			list->maj = (intmax_t)major(list->fd.st_rdev);
			list->min = (intmax_t)minor(list->fd.st_rdev);
		}
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (list);
}

void					ft_padding_str(t_llist *list, char *open, int f)
{
	char		*str;
	struct stat	fd;

	str = NULL;
	list = ft_str_uid_grp(list);
	list = ft_maj_min(list);
	list = ft_p_octet(list, str);
	if ((lstat(open, &fd) == 0) && (S_ISDIR(fd.st_mode) == 1) && f != 2)
		list = ft_block_octet(list, open);
	ft_complete_str(list, open);
}
