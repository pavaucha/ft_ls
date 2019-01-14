/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 09:43:51 by pavaucha          #+#    #+#             */
/*   Updated: 2018/04/24 13:48:20 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_flagsls	ft_flags_try(t_flagsls flags, char **str, int nb)
{
	int				i;
	int				j;

	i = 1;
	while (i < nb && str[i][0] == '-')
	{
		j = 1;
		flags = ft_assign(flags, str, i, j);
		if (flags.wadi == -1)
			return (flags);
		if (flags.wadi == 2 && str[i][1] == '-')
			return (flags);
		i++;
	}
	return (flags);
}

static void			ft_argument(t_flagsls flags, char **argv, int argc)
{
	int				i;

	i = 1;
	flags = ft_flags_try(flags, argv, argc);
	if (flags.wadi == -1)
		return ;
	while (i < argc && (argv[i][0] == '-' &&
			(argv[i][1] != '\0' || (argv[i][1] == '-' && argv[i][2] == '\0'))))
	{
		if (argv[i][1] == '-')
		{
			i++;
			break ;
		}
		i++;
	}
	if (flags.t == 1)
		argv = ft_sort_t(argv + i, argc - i - 1, flags, NULL);
	else
		argv = ft_ascii(argv + i, argc - i - 1, flags);
	ft_start_recursive(flags, argc - i, argv);
}

int					main(int argc, char **argv)
{
	t_flagsls		flags;
	int				j;

	j = 0;
	flags = ft_initialize_flags();
	while (j < argc && argv[j][0] != '\0')
		j++;
	if (argv[j] != NULL && argv[j][0] == '\0')
	{
		ft_printf("ft_ls: fts_open: No such file or directory\n");
		return (0);
	}
	if (argc == 1)
		ft_sort_affiche(".", flags);
	else
		ft_argument(flags, argv, argc);
	return (1);
}
