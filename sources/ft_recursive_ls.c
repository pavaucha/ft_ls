/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:42:26 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 11:57:23 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ls		*ft_stock_list(t_ls *n_list, t_ls list)
{
	char	*dst;
	char	*tmp;

	tmp = ft_strjoin(list.str, "/");
	dst = ft_strjoin(tmp, list.read->d_name);
	ft_strdel(&tmp);
	if (n_list == NULL)
		n_list = ft_list_initialize(dst, NULL, NULL);
	else
	{
		n_list->next = ft_list_initialize(dst, NULL, n_list);
		n_list = n_list->next;
	}
	ft_strdel(&dst);
	return (n_list);
}

static t_ls		*ft_go_list(t_flagsls flags, t_ls list, t_ls *n_list, char *dst)
{
	DIR		*dir;

	if ((dir = opendir(dst)) != NULL)
	{
		if (flags.a == 1)
		{
			if ((ft_recu_a(list.read->d_name)) == 1)
				n_list = ft_stock_list(n_list, list);
		}
		else if (list.read->d_name[0] != '.' && flags.a == 0)
			n_list = ft_stock_list(n_list, list);
		closedir(dir);
	}
	return (n_list);
}

static t_ls		*ft_creat_list_ls(t_flagsls flags, t_ls list, t_ls *n_list)
{
	char	*tmp;
	char	*dst;

	while ((list.read = readdir(list.dir)) != NULL)
	{
		tmp = ft_strjoin("/", list.read->d_name);
		dst = ft_strjoin(list.str, tmp);
		ft_strdel(&tmp);
		if ((lstat(dst, &list.fd) == 0) && (S_ISDIR(list.fd.st_mode)))
			n_list = ft_go_list(flags, list, n_list, dst);
		ft_strdel(&dst);
	}
	closedir(list.dir);
	while (n_list != NULL && n_list->before != NULL)
		n_list = n_list->before;
	return (n_list);
}

void			ft_recursive_ls(t_flagsls flags, t_ls list, int i)
{
	t_ls		*n_list;

	n_list = NULL;
	if (i == 1)
		ft_printf("%s:\n", list.str);
	ft_sort_affiche(list.str, flags);
	if ((list.dir = opendir(list.str)) == NULL)
	{
		ft_printf("ft_ls: %s: Permission denied\n", ft_cut_slh(list.str));
		return ;
	}
	if ((n_list = ft_creat_list_ls(flags, list, n_list)) == NULL)
		return ;
	ft_change_list(n_list, flags);
	while (n_list != NULL)
	{
		if (!(S_ISREG(n_list->fd.st_mode)))
		{
			ft_printf("\n");
			ft_recursive_ls(flags, *n_list, 1);
		}
		n_list = ft_free_list(n_list);
	}
}
