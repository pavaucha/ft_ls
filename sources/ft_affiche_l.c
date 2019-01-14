/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:47:47 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 20:56:10 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int				ft_padding_octet(t_llist *list, int i)
{
	while (list != NULL)
	{
		if (list->perm[0] != 'c' && list->perm[0] != 'b')
			i = (ft_cmp_imax(list->octet) > i) ? ft_cmp_imax(list->octet) : i;
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	return (i);
}

static int				*ft_padding_min(t_llist *list)
{
	int		*tab;

	if ((tab = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	while (list != NULL)
	{
		if (list->perm[0] == 'c' || list->perm[0] == 'b')
		{
			tab[0] = (ft_cmp_imax(list->min) > tab[0]) ?
				ft_cmp_imax(list->min) : tab[0];
			tab[1] = (ft_cmp_imax(list->maj) > tab[1]) ?
				ft_cmp_imax(list->maj) : tab[1];
		}
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	while (list->before != NULL)
		list = list->before;
	tab[1] = tab[1] + 1;
	return (tab);
}

static t_llist			*ft_b_c_octet(t_llist *list, int *tab, char *str)
{
	char		*tmp;
	char		*dst;

	tmp = ft_strnew_c(tab[1] - ft_cmp_imax(list->maj), ' ');
	dst = ft_uitoa(list->maj);
	str = ft_strjoin(tmp, dst);
	ft_strdel(&tmp);
	ft_strdel(&dst);
	tmp = ft_strjoin(str, ", ");
	ft_strdel(&str);
	dst = ft_strnew_c(tab[0] - ft_cmp_imax(list->min), ' ');
	str = ft_uitoa(list->min);
	list->str_o = ft_strjoin(dst, str);
	ft_strdel(&dst);
	ft_strdel(&str);
	dst = ft_strjoin(tmp, list->str_o);
	ft_strdel(&list->str_o);
	list->str_o = ft_strdup(dst);
	ft_strdel(&dst);
	ft_strdel(&tmp);
	return (list);
}

static t_llist			*ft_others_octet(t_llist *list, int i)
{
	char		*tmp;
	char		*dst;

	tmp = ft_strnew_c(i - ft_cmp_imax(list->octet), ' ');
	dst = ft_uitoa(list->octet);
	list->str_o = ft_strjoin(tmp, dst);
	ft_strdel(&tmp);
	ft_strdel(&dst);
	return (list);
}

t_llist					*ft_p_octet(t_llist *list, char *str)
{
	int			i;
	int			*tab;

	i = 0;
	tab = ft_padding_min(list);
	if ((tab[0] + tab[1]) > 1)
		i = tab[0] + tab[1] + 2;
	i = ft_padding_octet(list, i);
	while (list != NULL)
	{
		if (list->perm[0] == 'b' || list->perm[0] == 'c')
			list = ft_b_c_octet(list, tab, str);
		else
			list = ft_others_octet(list, i);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	if (tab != NULL)
		free(tab);
	while (list->before != NULL)
		list = list->before;
	return (list);
}
