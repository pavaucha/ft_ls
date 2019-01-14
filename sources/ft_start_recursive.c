/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_recursive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 10:44:27 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/06 13:49:36 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_nb_list_ls(t_ls *list)
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
	while (list->before != NULL)
		list = list->before;
	return (i);
}

static t_ls	*ft_creat_struct(t_ls *list, char **str, int nba)
{
	struct stat fd;
	int			i;

	i = 0;
	while (i < nba && str[i] != NULL)
	{
		if ((stat(str[i], &fd)) == -1)
			ft_printf("ft_ls: %s: no such file or directory\n", str[i]);
		else
		{
			if (list == NULL)
				list = ft_list_initialize(str[i], NULL, NULL);
			else
			{
				list->next = ft_list_initialize(str[i], NULL, list);
				list = list->next;
			}
		}
		i++;
	}
	return (list);
}

static void	ft_many_arguments(t_ls *list, t_flagsls flags, int i, int nba)
{
	t_ls		*list_next;

	while (list != NULL)
	{
		list_next = list->next;
		if (flags.r2 == 0)
		{
			if (nba > 1)
				ft_printf("%s:\n", list->str);
			if (list != NULL)
				ft_sort_affiche(list->str, flags);
			if (list->next != NULL)
				ft_printf("\n");
		}
		else if (list != NULL)
		{
			if (list->before != NULL)
				ft_printf("\n");
			ft_recursive_ls(flags, *list, i);
		}
		list = ft_free_list(list);
		i = 1;
	}
}

static void	ft_list_start(t_ls *list, char **str, int nba, t_flagsls flags)
{
	int			i;

	i = 0;
	list = ft_creat_struct(list, str, nba);
	if (list == NULL)
		return ;
	if (list->next != NULL || list->before != NULL)
		i = 1;
	while (list->before != NULL)
		list = list->before;
	list = ft_aff_del_file(list, flags);
	if (list != NULL)
	{
		while (list->before != NULL)
			list = list->before;
		if (nba > ft_nb_list_ls(list))
			ft_printf("\n");
		ft_many_arguments(list, flags, i, nba);
	}
}

void		ft_start_recursive(t_flagsls flags, int nba, char **str)
{
	t_ls		*list;
	int			i;

	i = 0;
	list = NULL;
	if (nba == 0)
	{
		list = ft_list_initialize(".", NULL, NULL);
		if (flags.r2 == 1)
			ft_recursive_ls(flags, *list, i);
		else
			ft_sort_affiche(".", flags);
	}
	if (nba > 0)
		ft_list_start(list, str, nba, flags);
	if (list != NULL)
	{
		while (list->before != NULL)
			list = list->before;
		while (list != NULL)
			list = ft_free_list(list);
	}
}
