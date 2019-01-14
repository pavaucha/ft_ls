/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:34:56 by pavaucha          #+#    #+#             */
/*   Updated: 2017/12/04 13:43:55 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_count_words(char *str, char c)
{
	size_t	i;
	size_t	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i - 1] != c)
			word++;
	}
	return (word);
}

static size_t		ft_count_letters(char *str, char c, size_t word)
{
	size_t	i;
	size_t	letter;
	size_t	j;

	letter = 0;
	i = 0;
	j = 0;
	while (j < word)
	{
		while (str[i] == c)
			i++;
		while (str[i] != c)
			i++;
		j++;
	}
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		letter++;
	}
	return (letter);
}

static size_t		ft_found_start(char *str, char c, size_t word)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (j < word)
	{
		while (str[i] == c)
			i++;
		while (str[i] != c)
			i++;
		j++;
	}
	while (str[i] == c)
		i++;
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	k;

	i = 0;
	if (s == NULL)
		return (NULL);
	k = ft_count_words((char*)(s), c);
	if ((str = (char**)malloc(sizeof(char*) * (k + 1))) == 0)
		return (0);
	while (k > i)
	{
		str[i] = ft_strsub(s, ft_found_start((char*)(s),
					c, i), ft_count_letters((char*)(s), c, i));
		i++;
	}
	str[i] = 0;
	return (str);
}
