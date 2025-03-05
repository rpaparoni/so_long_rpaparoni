/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:14:09 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/03 20:17:04 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*stash_filling(int fd, char *stash, char *buffer)
{
	int	size;

	size = 1;
	while (!ft_strchr(stash, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free (buffer), free (stash), stash = NULL);
		if (size == 0)
			return (free (buffer), stash);
		buffer[size] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free (buffer), NULL);
	}
	return (free (buffer), stash);
}

char	*extract_new_stash(char	*stash)
{
	int		len;
	int		i;
	char	*new_stash;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (!stash[len])
		return (free (stash), NULL);
	len++;
	new_stash = malloc((ft_strlen(stash) - len + 1) * sizeof(char));
	if (!new_stash)
		return (free (stash), NULL);
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i++;
	}
	free (stash);
	new_stash[i] = 0;
	return (new_stash);
}

char	*extract_line(char *stash)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (stash = NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), stash = NULL);
	stash = stash_filling(fd, stash, buffer);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free (stash), stash = NULL);
	stash = extract_new_stash(stash);
	if (!stash)
		return (free (line), NULL);
	if (*stash == '\0')
		return (free(stash), stash = NULL, line);
	return (line);
}

