/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_del_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:25:18 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/11 10:50:54 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ls	*ft_complete_del(t_ls *list, t_flagsls flags, char **str)
{
	if (flags.a == 1)
	{
		if (flags.l == 1)
		{
			str[0] = ft_strdup(list->str);
			ft_keep_l(str, ".", 2);
		}
		else
			ft_printf("%s\n", list->str);
	}
	else if ((flags.a == 0 && list->str[0] != '.') || (list->str[0] == '.'
				&& (list->str[1] == '/' || list->str[1] == '.')))
	{
		if (flags.l == 1)
		{
			str[0] = ft_strdup(list->str);
			ft_keep_l(str, ".", 2);
		}
		else
			ft_printf("%s\n", list->str);
	}
	return (list);
}

t_ls		*ft_aff_del_file(t_ls *list, t_flagsls flags)
{
	char		**str;

	while (list != NULL)
	{
		if (stat(list->str, &list->fd) == 0 && (S_ISREG(list->fd.st_mode) == 1))
		{
			if ((str = (char**)malloc(sizeof(char*) * 2)) == NULL)
				return (NULL);
			str[1] = 0;
			str[0] = 0;
			list = ft_complete_del(list, flags, str);
			if (flags.l != 1)
				free(str);
			if (list->before == ft_del_list(list))
				return (list->before);
		}
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	return (list);
}
