/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:33 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/09 18:28:00 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

// cargar lS LETRAS

void load_images(t_game *game)
{
    game->player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &game->columns, &game->rows);
    game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &game->columns, &game->rows);
    game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &game->columns, &game->rows);
    game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm", &game->columns, &game->rows);
    game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &game->columns, &game->rows);
    item_count(game);
}