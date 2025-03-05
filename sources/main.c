/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:04:58 by rpaparon          #+#    #+#             */
/*   Updated: 2025/01/21 20:44:26 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdlib.h>

int close_window(int keycode, void *param)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}
int main(void)
{
    void	*mlx;
    void	*mlx_win;
	void	*img;
	int	width;
    int	height;
	char	*relative_path = "textures/open24.xpm";

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img = mlx_xpm_file_to_image(mlx, relative_path, &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 500, 500);
	mlx_key_hook(mlx_win, close_window, mlx_win);

    mlx_loop(mlx);

    return 0;
}
