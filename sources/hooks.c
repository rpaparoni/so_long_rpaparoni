/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:22 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/21 18:23:28 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void    key_down(t_game *game)
{
    if (game->map[(game->pos_y + 64) / 64][game->pos_x / 64] == '1')
        return ;
    if (game->map[(game->pos_y + 64) / 64][game->pos_x / 64] == 'E'
        && game->n_item != 0)
        return ;
    if (game->map[(game->pos_y + 64) / 64][game->pos_x / 64] == 'C')
    {
        game->map[(game->pos_y + 64) / 64][game->pos_x / 64] = '0';
        game->n_item--;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->floor,
        game->pos_x, game->pos_y);
    game->pos_y += 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
    print_moves(game);
    if (game->map[game->pos_y / 64][game->pos_x / 64] == 'E' 
        && game->n_item == 0)
        ft_kill("You Won", game); 
}

void    key_up(t_game *game)
{
    if (game->map[(game->pos_y - 64) / 64][game->pos_x / 64] == '1')
        return ;
    if (game->map[(game->pos_y - 64) / 64][game->pos_x / 64] == 'E'
        && game->n_item != 0)
        return ;
    if (game->map[(game->pos_y - 64) / 64][game->pos_x / 64] == 'C')
    {
        game->map[(game->pos_y - 64) / 64][game->pos_x / 64] = '0';
        game->n_item--;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->floor,
        game->pos_x, game->pos_y);
    game->pos_y -= 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
    print_moves(game);
    if (game->map[game->pos_y / 64][game->pos_x / 64] == 'E' 
        && game->n_item == 0)
        ft_kill("You Won", game);
}

void    key_right(t_game *game)
{
    if (game->map[game->pos_y / 64][(game->pos_x + 64)/ 64] == '1')
        return ;
    if (game->map[game->pos_y / 64][(game->pos_x + 64)/ 64] == 'E'
        && game->n_item != 0)
        return ;
    if (game->map[game->pos_y / 64][(game->pos_x + 64)/ 64] == 'C')
    {
        game->map[game->pos_y / 64][(game->pos_x + 64)/ 64] = '0';
        game->n_item--;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->floor,
        game->pos_x, game->pos_y);
    game->pos_x += 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
    print_moves(game);
    if (game->map[game->pos_y / 64][game->pos_x / 64] == 'E' 
        && game->n_item == 0)
        ft_kill("You Won", game);
}

void    key_left(t_game *game)
{
    if (game->map[game->pos_y / 64][(game->pos_x - 64 )/ 64] == '1')
        return ;
    if (game->map[game->pos_y / 64][(game->pos_x - 64 )/ 64] == 'E'
        && game->n_item != 0)
        return ;
    if (game->map[game->pos_y / 64][(game->pos_x - 64 )/ 64] == 'C')
    {
        game->map[game->pos_y / 64][(game->pos_x - 64 )/ 64] = '0';
        game->n_item--;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->floor,
        game->pos_x, game->pos_y);
    game->pos_x -= 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
    print_moves(game);
    if (game->map[game->pos_y / 64][game->pos_x / 64] == 'E' 
        && game->n_item == 0)
        ft_kill("You Won", game);
}

int    hooks(int keycode, t_game *game)
{
    if (keycode == 65362 || keycode == 119)
        key_up(game);
    else if (keycode == 65364 || keycode == 115)
        key_down(game);
    else if (keycode == 65363 || keycode == 100)
        key_right(game);
    else if (keycode == 65361 || keycode == 97)
        key_left(game);
    else if (keycode == 65307)
        ft_kill("Game closed", game);
    return (0);
}
