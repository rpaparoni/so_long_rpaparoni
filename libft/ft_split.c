/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:08:26 by rpaparon          #+#    #+#             */
/*   Updated: 2024/10/28 19:14:59 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, int j)
{
	while (j >= 0)
		free(split[j--]);
	free(split);
}

static int	counter(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	split_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**create_word(const char *s, char c, char **split)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = split_len(s + i, c);
			split[j] = (char *)malloc((len + 1) * sizeof(char));
			if (!split[j])
			{
				free_split(split, j);
				return (NULL);
			}
			ft_strlcpy(split[j], s + i, len + 1);
			i += len;
			j++;
		}
		else
			i++;
	}
	return (split[j] = NULL, split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word;

	if (!s)
		return (NULL);
	word = counter(s, c);
	split = (char **)malloc((word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (create_word(s, c, split));
}
