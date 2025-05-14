/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:33 by rpaparon          #+#    #+#             */
/*   Updated: 2025/05/14 15:48:27 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	check_letters(t_game *game)
{
	if (game->n_player != 1)
		ft_kill("There must be one player", game);
	if (game->n_exit != 1)
		ft_kill("There must be one exit", game);
	if (game->n_item < 1)
		ft_kill("There must be at least one item", game);
	if (game->n_wall < 1)
		ft_kill("There must be at least one wall", game);
	if (game->n_floor < 1)
		ft_kill("There must be at least one floor", game);
}

void	load_images(t_game *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&game->texture_height, &game->texture_width);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->texture_height, &game->texture_width);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&game->texture_height, &game->texture_width);
	game->item = mlx_xpm_file_to_image(game->mlx, "./textures/item.xpm",
			&game->texture_height, &game->texture_width);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm",
			&game->texture_height, &game->texture_width);
	item_count(game);
}

void	place_img(char lettre, int x, int y, t_game *game)
{
	if (lettre == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * 64, y * 64);
	else if (lettre == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			x * 64, y * 64);
	else if (lettre == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->item,
			x * 64, y * 64);
	else if (lettre == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * 64, y * 64);
	else if (lettre == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * 64, y * 64);
	else
		ft_kill("Invalid character in map", game);
}

void	start_counter(char lettre, t_game *game, int x, int y)
{
	if (lettre == 'P')
	{
		game->pos_x = x * 64;
		game->pos_y = y * 64;
		game->n_player++;
	}
	else if (lettre == 'C')
		game->n_item++;
	else if (lettre == 'E')
		game->n_exit++;
	else if (lettre == '1')
		game->n_wall++;
	else if (lettre == '0')
		game->n_floor++;
	place_img(lettre, x, y, game);
}

void	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	load_images(game);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			start_counter(game->map[i][j], game, j, i);
			j++;
		}
		i++;
	}
	check_letters(game);
	check_rute(game);
}
