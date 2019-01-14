/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:41:48 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 14:13:28 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ls	*ft_swap_t_r(t_ls *list,
		t_ls *begin_list, t_flagsls flags, char *tmp)
{
	if (ft_strcmp_t(list->str, list->next->str, NULL) > 0)
	{
		tmp = list->str;
		list->str = list->next->str;
		list->next->str = tmp;
		list = begin_list;
	}
	else if (ft_strcmp_t(list->str, list->next->str, NULL) == 0)
		list = ft_swap_char_list(list, begin_list, flags, tmp);
	else
		list = list->next;
	return (list);
}

t_ls		*ft_swap_t_char_list(t_ls *list,
		t_ls *begin_list, t_flagsls flags, char *tmp)
{
	if (flags.r == 1)
		list = ft_swap_t_r(list, begin_list, flags, tmp);
	else if (flags.r == 0)
	{
		if (ft_strcmp_t(list->str, list->next->str, NULL) < 0)
		{
			tmp = list->str;
			list->str = list->next->str;
			list->next->str = tmp;
			list = begin_list;
		}
		else if (ft_strcmp_t(list->str, list->next->str, NULL) == 0)
			list = ft_swap_char_list(list, begin_list, flags, tmp);
		else
			list = list->next;
	}
	return (list);
}
