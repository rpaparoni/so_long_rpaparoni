/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:22 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/23 13:56:14 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

int		key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit_game(game);
    }
    if (game->player->movements < game->map->movements)
    {
        if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
            || keycode == KEY_D)
        {
            move_player(keycode, game);
            game->player->movements++;
        }
    }
    if (game->player->movements == game->map->movements)
    {
        if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
            || keycode == KEY_D)
            move_player(keycode, game);
    }
    return (0);
}