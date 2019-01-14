/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:37:55 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 13:56:50 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls				*ft_swap_char_list(t_ls *list,
		t_ls *begin_list, t_flagsls flags, char *tmp)
{
	if (flags.r == 1)
	{
		if (ft_strcmp(list->str, list->next->str) < 0)
		{
			tmp = list->str;
			list->str = list->next->str;
			list->next->str = tmp;
			list = begin_list;
		}
		else
			list = list->next;
	}
	else if (flags.r == 0)
	{
		if (ft_strcmp(list->str, list->next->str) > 0)
		{
			tmp = list->str;
			list->str = list->next->str;
			list->next->str = tmp;
			list = begin_list;
		}
		else
			list = list->next;
	}
	return (list);
}

void				ft_change_list(t_ls *list, t_flagsls flags)
{
	t_ls			*begin_list;
	char			*tmp;

	tmp = NULL;
	begin_list = list;
	if (list == NULL || list->next == NULL)
		return ;
	while (list != NULL)
	{
		if (flags.t == 0)
			list = ft_swap_char_list(list, begin_list, flags, tmp);
		else
			list = ft_swap_t_char_list(list, begin_list, flags, tmp);
		if (list->next == NULL)
			break ;
	}
	list = begin_list;
}

int					ft_swap(char **str, int i, char *tmp, t_flagsls flags)
{
	if (flags.r == 1)
	{
		if (ft_strcmp(str[i], str[i + 1]) < 0)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	else
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (i);
}

char				**ft_ascii(char **str, int nb, t_flagsls flags)
{
	int				i;
	char			*tmp;

	tmp = NULL;
	i = 0;
	while (i < nb)
		i = ft_swap(str, i, tmp, flags);
	return (str);
}
