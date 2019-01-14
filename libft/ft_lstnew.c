/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:37:13 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:33:24 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if ((new->content = malloc(content_size)) == 0)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		new->content_size = content_size;
		new->content = ft_memcpy(new->content, content, content_size);
		new->next = NULL;
	}
	return (new);
}
