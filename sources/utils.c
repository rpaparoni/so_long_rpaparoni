/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/22 18:13:48 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_kill(char *msg, t_game *game)
{
	if (game->n_item == 0)
	{
		ft_printf("\033[92m\n\t%s\n\n\033[0m", msg);
		ft_clean(game);
		exit(EXIT_FAILURE);
	}
	ft_printf("\033[91mError:\n\t%s\n\033[0m", msg);
	ft_clean(game);
	exit(EXIT_FAILURE);
}

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

int	close_game(t_game *game)
{
	ft_kill("Game closed", game);
	return (0);
}

void	print_moves(t_game *game)
{
	ft_printf("\033[95mTotal Moves: %d\n\033[0m", game->n_moves);
	game->n_moves++;
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
