/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:22 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/23 13:57:01 by rpaparon         ###   ########.fr       */
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

void    move_player(int keycode, t_game *game)
{
    int     x;
    int     y;

    x = game->player->x;
    y = game->player->y;
    if (keycode == KEY_W)
        y--;
    if (keycode == KEY_A)
        x--;
    if (keycode == KEY_S)
        y++;
    if (keycode == KEY_D)
        x++;
    if (game->map->map[y][x] == '1')
        return ;
    if (game->map->map[y][x] == 'E')
    {
        if (game->map->collectibles == 0)
        {
            mlx_destroy_window(game->mlx, game->win);
            exit_game(game);
        }
        return ;
    }
    if (game->map->map[y][x] == 'C')
    {
        game->map->collectibles--;
        game->map->map[y][x] = '0';
    }
    game->map->map[game->player->y][game->player->x] = '0';
    game->player->x = x;
    game->player->y = y;
    game->map->map[y][x] = 'P';
    draw_map(game);
}