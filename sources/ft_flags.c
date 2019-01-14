/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:44:44 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/12 16:05:47 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flagsls			ft_initialize_flags(void)
{
	t_flagsls		flags;

	flags.l = 0;
	flags.r = 0;
	flags.r2 = 0;
	flags.a = 0;
	flags.t = 0;
	flags.wadi = 1;
	return (flags);
}

static t_flagsls	ft_complete_flags(char *str, t_flagsls flags, int j)
{
	if (str[j] == 'l')
		flags.l = 1;
	if (str[j] == 'r')
		flags.r = 1;
	if (str[j] == 'R')
		flags.r2 = 1;
	if (str[j] == 'a')
		flags.a = 1;
	if (str[j] == 't')
		flags.t = 1;
	return (flags);
}

t_flagsls			ft_assign(t_flagsls flags, char **str, int i, int j)
{
	while (str[i][j] == 'l' || str[i][j] == 'r'
			|| str[i][j] == 'R' || str[i][j] == 'a' || str[i][j] == 't')
	{
		flags = ft_complete_flags(str[i], flags, j);
		j++;
	}
	if (str[i][j] != '\0' || (str[i][1] == '\0' && str[i][0] == '-')
			|| (str[i][0] == '-' && str[i][1] == '-' && str[i][2] == '\0'))
	{
		if ((str[i][1] == '\0' && str[i][0] == '-')
				|| (str[i][0] == '-' && str[i][1] == '-' && str[i][2] == '\0'))
		{
			flags.wadi = 2;
			return (flags);
		}
		ft_printf("ft_ls: illegal option -- %c\n", str[i][j]);
		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
		flags.wadi = -1;
	}
	return (flags);
}
