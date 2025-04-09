/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/09 16:59:34 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_error(char *msg, t_game *game)
{
    ft_printf("Error\n%s\n", msg);
    ft_clean(game);
    exit(EXIT_FAILURE);
}
void ft_clean(t_game *game)
{
    if (game->img)
        mlx_destroy_image(game->mlx, game->img);
    if (game->player)
        mlx_destroy_image(game->mlx, game->player);
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if (game->floor)
        mlx_destroy_image(game->mlx, game->floor);
    if (game->collectible)
        mlx_destroy_window(game->mlx, game->collectible);
    if (game->exit)
        mlx_destroy_window(game->mlx, game->exit);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}

int	item_count(t_game *game)
{
    game->n_moves = 0;
    game->n_collectible = 0;
    game->n_exit = 0;
    game->n_player = 0;
}

