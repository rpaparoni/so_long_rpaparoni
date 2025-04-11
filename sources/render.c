/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:33 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/11 02:33:00 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	place_img(char lettre, int x, int y, t_game *game)
{
	if (lettre == 'P')
	{
		game->pos_x = x * 64;
		game->pos_y = y * 64;
		game->n_player++;
		mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y * 64);
	}
	else if (lettre == '1')
	{
		game->n_wall++;
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);
	}
	else if (lettre == '0')
	{
		game->n_floor++;
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 64, y * 64);
	}
	else if (lettre == 'C')
	{
		game->n_item++;
		mlx_put_image_to_window(game->mlx, game->win, game->item, x * 64, y * 64);
	}
	else if (lettre == 'E')
	{
		game->n_exit_close++;
		mlx_put_image_to_window(game->mlx, game->win, game->exit_close, x * 64, y * 64);
	}
} 

void load_images(t_game *game)
{
    game->player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &game->columns, &game->rows);
    game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &game->columns, &game->rows);
    game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &game->columns, &game->rows);
    game->item = mlx_xpm_file_to_image(game->mlx, "./textures/item.xpm", &game->columns, &game->rows);
    game->exit_close = mlx_xpm_file_to_image(game->mlx, "./textures/exit_close.xpm", &game->columns, &game->rows);
    game->exit_open = mlx_xpm_file_to_image(game->mlx, "./textures/exit_open.xpm", &game->columns, &game->rows);
    item_count(game);
}

void render_game(t_game *game)
{
    int i;
    int j;

    load_images(game);
    i = 0;
    while (i < game->rows)
    {
        j = 0;
        while (j < game->columns)
        {
            place_image(game->map[i][j], j, i, game);
        }
    }
        i++;
    }