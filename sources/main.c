/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:04:58 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/20 17:57:24 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

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

int	main(void)
{
	t_game	game;
	int		width;
	int		height;
	char	*relative_path = "textures/gus.xpm";

	// Inicializar MiniLibX
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);

	// Crear ventana
	game.win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	if (!game.win)
		return (1);

	// Cargar imagen
	game.img = mlx_xpm_file_to_image(game.mlx, relative_path, &width, &height);
	if (!game.img)
		return (1);

	// Poner imagen en la ventana
	mlx_put_image_to_window(game.mlx, game.win, game.img, 500, 500);

	// Manejo de teclas
	mlx_key_hook(game.win, close_window, &game);

	// Iniciar loop de eventos
	mlx_loop(game.mlx);

	return (0);
}
