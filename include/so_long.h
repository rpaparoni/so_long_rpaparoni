/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:05:31 by rpaparon          #+#    #+#             */
/*   Updated: 2025/05/01 12:44:08 by rpaparon         ###   ########.fr       */
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
	void	*item;
	void	*exit;
	char	**map;
	int		columns;
	int		rows;
	int		n_moves;
	int		n_exit_close;
	int		n_exit_found;
	int		n_exit;
	int		n_wall;
	int		n_floor;
	int		n_item;
	int		n_item_found;
	int		n_player;
	int		pos_x;
	int		pos_y;
	int		texture_width;
	int		texture_height;
	int		win_width;
	int		win_height;
}	t_game;

int		main(int argc, char *argv[]);
int		hooks(int keycode, t_game *game);
int		check_walls(t_game *game);
int		close_game(t_game *game);
void	item_count(t_game *game);
void	load_images(t_game *game);
void	place_img(char lettre, int x, int y, t_game *game);
void	check_letters(t_game *game);
void	check_rute(t_game *game);
void	render_game(t_game *game);
void	ft_kill(char *msg, t_game *game);
void	check_file(char *map);
void	read_file(char *map, t_game *game);
void	check_map(char *map, t_game *game);
void	ft_clean(t_game *game);
void	print_moves(t_game *game);
void	flood_fill(char **map, int items_found, int exit_found, t_game *game);
void	ft_error(char *msg);
char	**copy_map(t_game *game);

#endif
