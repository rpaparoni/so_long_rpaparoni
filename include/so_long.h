/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:05:31 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/08 13:23:58 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	**map;
	void	*map_width;
	void	*map_height;
}	t_game;

int	close_window(int keycode, t_game *game);
int	main(int argc, char *argv[]);
void	ft_error(char *msg);
void	cheack_file(char *map, size_t size);
void	red_file(char *map, t_game *game);
void	check_walls(t_game *game);
void	cheak_map(int argc, char *map, t_game *game);

#endif
