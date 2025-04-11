/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:04:58 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/11 01:38:47 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

//mandar para otro archivo

int	close_window(int keycode, t_game *game)
{
	if (keycode == 65307) // Tecla ESC
	{
		if (game->img)
			mlx_destroy_image(game->mlx, game->img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	cheak_map(argc, argv[1], &game);
	game.rows = game.rows * 64;
	game.columns = game.columns * 64;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.columns, game.rows, "so_long");
	render_game(&game);
	//inicializar el loop
	mlx_key_hook(game.win, hooks, &game);
	return (0);
}
