/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:30:01 by rpaparon          #+#    #+#             */
/*   Updated: 2025/05/13 16:55:08 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_file(char *map)
{
	size_t	size;

	size = ft_strlen(map);
	if (size <= 4 || ft_strncmp(map + size - 4, ".ber", 4) != 0)
		ft_error("File extension must be a .ber file");
}

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

void	read_file(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	**map_lines;

	game->rows = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Map file not found");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map file");
	game->columns = ft_strlen(line) - 1;
	map_lines = malloc(sizeof(char *) * 1000);
	if (!map_lines)
		ft_error("Memory allocation failed");
	while (line != NULL)
	{
		map_lines[game->rows] = ft_strdup(line);
		game->rows++;
		free(line);
		line = get_next_line(fd);
	}
	map_lines[game->rows] = NULL;
	game->map = map_lines;
	close(fd);
}

void	check_rute(t_game *game)
{
	char	**copy;

	game->n_item_found = 0;
	game->n_exit_found = 0;
	copy = copy_map(game);
	if (!copy)
		ft_kill("Error duplicating map", game);
	flood_fill(copy, game->pos_y / 64, game->pos_x / 64, game);
	if (game->n_item_found != game->n_item || game->n_exit_found != 1)
		ft_kill("Unreachable items or exit", game);
}

void	check_map(char *map, t_game *game)
{
	check_file(map);
	read_file(map, game);
	if (!check_walls(game))
	{
		ft_kill("Map is not surrounded by walls", game);
	}
}
