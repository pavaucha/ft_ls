/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_octet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:26:54 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/05 16:17:42 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_llist		*ft_block_octet(t_llist *list, char *open)
{
	intmax_t		block;
	char			*tmp;
	char			*dst;

	block = 0;
	while (list != NULL)
	{
		tmp = ft_strjoin(open, "/");
		dst = ft_strjoin(tmp, list->str);
		lstat(dst, &list->fd);
		block = block + list->fd.st_blocks;
		ft_strdel(&tmp);
		ft_strdel(&dst);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	ft_printf("total %jd\n", block);
	while (list->before != NULL)
		list = list->before;
	return (list);
}
