/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:28:11 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 13:48:51 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_return_t(struct stat fd, struct stat fd2)
{
	if (fd2.st_mtime > fd.st_mtime)
		return (-1);
	if (fd2.st_mtime < fd.st_mtime)
		return (1);
	if (fd2.st_mtime == fd.st_mtime)
		return (0);
	return (0);
}

int			ft_strcmp_t(char *str, char *dst, char *open)
{
	char		*tmp;
	time_t		now;
	struct stat	fd;
	struct stat	fd2;

	time(&now);
	if (open == NULL)
	{
		lstat(str, &fd);
		lstat(dst, &fd2);
	}
	else
	{
		tmp = ft_strjoin(open, str);
		lstat(tmp, &fd);
		ft_strdel(&tmp);
		tmp = ft_strjoin(open, dst);
		lstat(tmp, &fd2);
		ft_strdel(&tmp);
	}
	return (ft_return_t(fd, fd2));
}

static int	ft_swap(char **str, char *tmp, int i)
{
	tmp = str[i];
	str[i] = str[i + 1];
	str[i + 1] = tmp;
	return (0);
}

static int	ft_swap_t(char **str, int i, t_flagsls flags, char *open)
{
	char		*tmp;

	tmp = NULL;
	if (flags.r == 0)
	{
		if (ft_strcmp_t(str[i], str[i + 1], open) < 0)
			i = ft_swap(str, tmp, i);
		else if ((ft_strcmp_t(str[i], str[i + 1], open) == 0)
				&& (ft_strcmp(str[i], str[i + 1]) > 0))
			i = ft_swap(str, tmp, i);
		else
			i++;
	}
	else
	{
		if (ft_strcmp_t(str[i], str[i + 1], open) > 0)
			i = ft_swap(str, tmp, i);
		else if ((ft_strcmp_t(str[i], str[i + 1], open) == 0)
				&& (ft_strcmp(str[i], str[i + 1]) < 0))
			i = ft_swap(str, tmp, i);
		else
			i++;
	}
	return (i);
}

char		**ft_sort_t(char **str, int nb, t_flagsls flags, char *open)
{
	int			i;

	i = 0;
	while (i < nb)
		i = ft_swap_t(str, i, flags, open);
	return (str);
}
