/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:30:01 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/16 12:36:05 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(t_game *game)
{
    int	i;

	if (!game->map || game->rows <= 0 || game->columns <= 0)
		return (0);
	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void    red_file(char *map, t_game *game)
{
    int     fd;
    char    *line;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        ft_kill("Error\nMap file not found", NULL);
    
    close(fd);
}

void    cheack_file(char *map, size_t size)
{
    if (size < 4)
        ft_kill("Map file is too short", NULL);
    if (ft_strncmp(map + size - 4, ".ber", 4))
        ft_kill("Map file must have a .ber extension", NULL);
}

void    check_map(int argc, char *map, t_game *game)
{
    int    size;

    if (argc != 2)
    {
        if (argc < 2)
            ft_kill("Error\nNo map file provided", NULL);
        else
            ft_kill("Error\nToo many arguments", NULL);
    }
    size = ft_strlen(map);
    cheack_file(map, size);
    red_file(map, game);
    check_walls(game);
}