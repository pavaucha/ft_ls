/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:25:26 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:33:13 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*temp;
	t_list		*start;

	if (lst == NULL)
		return (NULL);
	new = (f)(lst);
	start = new;
	temp = new;
	lst = lst->next;
	while (lst)
	{
		new = (f)(lst);
		temp->next = new;
		temp = new;
		lst = lst->next;
	}
	temp->next = NULL;
	new = start;
	return (new);
}
