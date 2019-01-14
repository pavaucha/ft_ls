/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_affiche.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:03:53 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/26 10:52:49 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*ft_cut_slh(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '/' && i > 0)
		i--;
	return (str + i);
}

static char		**ft_mal_nb_doc(char *open, t_flagsls flags, char **str)
{
	DIR				*dir;
	struct dirent	*read;
	int				i;

	i = 1;
	dir = opendir(open);
	while ((read = readdir(dir)) != NULL)
	{
		if (flags.a == 0 && read->d_name[0] != '.')
			i++;
		if (flags.a == 1)
			i++;
	}
	closedir(dir);
	if (!(str = (char**)malloc(sizeof(char*) * i)))
		return (NULL);
	str[i - 1] = 0;
	return (str);
}

static char		**ft_string(char **str, t_flagsls flags, DIR *dir, char *open)
{
	int				i;
	struct dirent	*read;

	i = 0;
	while ((read = readdir(dir)) != NULL)
	{
		if (flags.a == 0 && read->d_name[0] != '.')
		{
			str[i] = ft_strdup(read->d_name);
			i++;
		}
		if (flags.a == 1)
		{
			str[i] = ft_strdup(read->d_name);
			i++;
		}
	}
	if (flags.t == 1)
		str = ft_sort_t(str, i - 1, flags, open);
	else
		str = ft_ascii(str, i - 1, flags);
	ft_strdel(&open);
	return (str);
}

void			ft_sort_affiche(char *open, t_flagsls flags)
{
	DIR				*dir;
	char			**str;
	int				i;

	str = NULL;
	if ((dir = opendir(open)) == NULL)
	{
		ft_printf("ft_ls: %s: Permission denied\n", ft_cut_slh(open));
		return ;
	}
	str = ft_mal_nb_doc(open, flags, str);
	str = ft_string(str, flags, dir, ft_strjoin(open, "/"));
	closedir(dir);
	if (flags.l == 1)
		ft_keep_l(str, open, 1);
	else
	{
		i = -1;
		while (str[++i] != 0)
		{
			ft_printf("%s\n", str[i]);
			ft_strdel(&str[i]);
		}
		free(str);
	}
}
