/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:45:12 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/26 10:45:59 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_llist		*ft_take_uid_grp(t_llist *list)
{
	struct group	*grp;
	struct passwd	*pwd;

	while (list != NULL)
	{
		if ((grp = getgrgid(list->fd.st_gid)) != NULL)
			list->grp = ft_strdup(grp->gr_name);
		else
			list->grp = ft_uitoa(list->fd.st_gid);
		if ((pwd = getpwuid(list->fd.st_uid)) != NULL)
			list->uid = ft_strdup(pwd->pw_name);
		else
			list->uid = ft_uitoa(list->fd.st_uid);
		list->octet = list->fd.st_size;
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (list);
}

static t_llist		*ft_perm_x(t_llist *list)
{
	list->perm[1] = (S_IRUSR & list->fd.st_mode) ? 'r' : '-';
	list->perm[2] = (S_IWUSR & list->fd.st_mode) ? 'w' : '-';
	list->perm[3] = (S_IXUSR & list->fd.st_mode) ? 'x' : '-';
	list->perm[4] = (S_IRGRP & list->fd.st_mode) ? 'r' : '-';
	list->perm[5] = (S_IWGRP & list->fd.st_mode) ? 'w' : '-';
	list->perm[6] = (S_IXGRP & list->fd.st_mode) ? 'x' : '-';
	list->perm[7] = (S_IROTH & list->fd.st_mode) ? 'r' : '-';
	list->perm[8] = (S_IWOTH & list->fd.st_mode) ? 'w' : '-';
	list->perm[9] = (S_IXOTH & list->fd.st_mode) ? 'x' : '-';
	if (list->perm[9] == 'x' && ((S_ISVTX & list->fd.st_mode)))
		list->perm[9] = 't';
	else if (list->perm[9] == '-' && ((S_ISVTX & list->fd.st_mode)))
		list->perm[9] = 'T';
	if (list->perm[3] == 'x' && ((S_ISUID & list->fd.st_mode)))
		list->perm[3] = 's';
	else if (list->perm[3] == '-' && ((S_ISUID & list->fd.st_mode)))
		list->perm[3] = 'S';
	if (list->perm[6] == 'x' && ((S_ISGID & list->fd.st_mode)))
		list->perm[6] = 's';
	else if (list->perm[6] == 'x' && ((S_ISGID & list->fd.st_mode)))
		list->perm[6] = 'S';
	return (list);
}

static t_llist		*ft_take_perm(t_llist *list, char *open)
{
	char		*dst;
	char		*tmp;

	while (list != NULL)
	{
		dst = ft_strjoin(open, "/");
		tmp = ft_strjoin(dst, list->str);
		lstat(tmp, &list->fd);
		list->perm[0] = (S_ISLNK(list->fd.st_mode)) ? 'l' : '-';
		list->perm[0] = (S_ISDIR(list->fd.st_mode)) ? 'd' : list->perm[0];
		list->perm[0] = (S_ISSOCK(list->fd.st_mode)) ? 's' : list->perm[0];
		list->perm[0] = (S_ISCHR(list->fd.st_mode)) ? 'c' : list->perm[0];
		list->perm[0] = (S_ISBLK(list->fd.st_mode)) ? 'b' : list->perm[0];
		list->perm[0] = (S_ISFIFO(list->fd.st_mode)) ? 'p' : list->perm[0];
		list = ft_perm_x(list);
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

static t_llist		*ft_check_list(t_llist *list, char **str, char *open)
{
	int				i;
	char			*tmp;
	char			*dst;
	struct stat		fd;

	i = 1;
	while (str[i] != 0)
	{
		dst = ft_strjoin(open, "/");
		tmp = ft_strjoin(dst, str[i]);
		if (lstat(tmp, &fd) != -1)
		{
			list->next = ft_list_l_initialize(str[i], NULL, list);
			list = list->next;
		}
		ft_strdel(&str[i]);
		ft_strdel(&tmp);
		ft_strdel(&dst);
		i++;
	}
	return (list);
}

void				ft_keep_l(char **str, char *open, int f)
{
	t_llist			*list;

	if (str[0] == 0)
	{
		ft_strdel(&str[0]);
		free(str);
		return ;
	}
	list = ft_list_l_initialize(str[0], NULL, NULL);
	list = ft_check_list(list, str, open);
	ft_strdel(&str[0]);
	free(str);
	while (list->before != NULL)
		list = list->before;
	list = ft_take_perm(list, open);
	list = ft_take_uid_grp(list);
	list = ft_take_time(list, open);
	list = ft_take_link(list);
	ft_padding_str(list, open, f);
}
