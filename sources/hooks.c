/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:22 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/16 12:57:28 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void    s_key(t_game *game)
{
    print_moves(game);
    game->pos_y += 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
}
void    a_key(t_game *game)
{
    print_moves(game);
    game->pos_x -= 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
}
void    d_key(t_game *game)
{
    print_moves(game);
    game->pos_x += 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
}
void    w_key(t_game *game)
{
    print_moves(game);
    game->pos_y -= 64;
    mlx_put_image_to_window(game->mlx, game->win, game->player,
        game->pos_x, game->pos_y);
}

void    hooks(int keycode, t_game *game)
{
    if (keycode == 65362 || keycode == 119)
        w_key(game);
    else if (keycode == 65364 || keycode == 115)
        a_key(game);
    else if (keycode == 65361 || keycode == 100)
        s_key(game);
    else if (keycode == 65363 || keycode == 97)
        d_key(game);
    else if (keycode == 65307)
        ft_kill("Game closed", game);
    else
        return ;
}
