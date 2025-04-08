/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:30:01 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/08 17:33:45 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    check_walls(t_game *game)
{
    int	i;

	if (!game->map || game-> <= 0 || game->columns <= 0)
		return (0);
	i = 0;
	while (i < vars->columns)
	{
		if (vars->map[0][i] != '1' || vars->map[vars->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < vars->rows)
	{
		if (vars->map[i][0] != '1' || vars->map[i][vars->columns - 1] != '1')
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
        ft_error("Error\nMap file not found");
    
    close(fd);
}

void    cheack_file(char *map, size_t size)
{
    if (size < 4)
        ft_error("Map file is too short");
    if (ft_strncmp(map + size - 4, ".ber", 4))
        ft_error("Map file must have a .ber extension");
}

void    check_map(int argc, char *map, t_game *game)
{
    int    size;

    if (argc != 2)
    {
        if (argc < 2)
            ft_printf("Error\nToo few arguments\n");
        else
            ft_printf("Error\nToo many arguments\n");
        exit(EXIT_FAILURE);
    }
    size = ft_strlen(map);
    cheack_file(map, size);
    red_file(map, game);
    check_walls(game);
}