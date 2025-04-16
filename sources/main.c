/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:04:58 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/16 13:10:16 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	check_map(argc, argv[1], &game);
	game.rows = game.rows * 64;
	game.columns = game.columns * 64;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.columns, game.rows, "so_long");
	render_game(&game);
	mlx_key_hook(game.win, hooks, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
