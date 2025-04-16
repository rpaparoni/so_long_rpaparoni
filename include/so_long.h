/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:05:31 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/16 15:13:32 by rpaparon         ###   ########.fr       */
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
	void	*exit_open;
	void	*exit_close;
	char	**map;
	int	columns;
	int	rows;
	int	n_moves;
	int	n_exit_close;
	int	n_exit_open;
	int	n_wall;
	int	n_floor;
	int	n_item;
	int	n_player;
	int	pos_x;
	int	pos_y;
	int	texture_width;
	int	texture_height;
	int	win_width;
	int	win_height;
}	t_game;

int		main(int argc, char *argv[]);
int		hooks(int keycode, t_game *game);
int		check_walls(t_game *game);
int		close_game(t_game *game);
void 	item_count(t_game *game);
void	load_images(t_game *game);
void	place_img(char lettre, int x, int y, t_game *game);
void	check_letters(t_game *game);
void	render_game(t_game *game);
void	ft_kill(char *msg, t_game *game);
void	check_file(char *map, size_t size);
void	red_file(char *map);
void	check_map(int argc, char *map, t_game *game);
void	ft_clean(t_game *game);
void	s_key(t_game *game);
void	a_key(t_game *game);
void	d_key(t_game *game);
void	w_key(t_game *game);
void	print_moves(t_game *game);



#endif
