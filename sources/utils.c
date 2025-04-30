/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/30 15:21:10 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->item)
		mlx_destroy_image(game->mlx, game->item);
	if (game->exit_close)
		mlx_destroy_image(game->mlx, game->exit_close);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	if (map[x][y] == 'C')
		(game->n_item_found)++;
	if (map[x][y] == 'E')
		game->n_exit_found = 1;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

char	**copy_map(t_game *game)
{
	int		i;
	char	**copy_map;

	i = 0;
	copy_map = malloc(sizeof(char *) * (game->rows + 1));
	if (!copy_map)
		return (NULL);
	while (game->map[i])
	{
		copy_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	item_count(t_game *game)
{
	game->n_exit_close = 0;
	game->n_wall = 0;
	game->n_floor = 0;
	game->n_item = 0;
	game->n_player = 0;
	game->n_moves = 1;
}
