/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:05:31 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/09 16:29:45 by rpaparon         ###   ########.fr       */
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
	char	**map;
	int	columns;
	int	rows;
	int	n_moves;
	int	n_collectible;
	int	n_exit;
	int	n_player;
}	t_game;

int	close_window(int keycode, t_game *game);
int	main(int argc, char *argv[]);
void	ft_error(char *msg, t_game *game);
void	cheack_file(char *map, size_t size);
void	red_file(char *map, t_game *game);
void	check_walls(t_game *game);
void	check_map(int argc, char *map, t_game *game);
void	ft_clean(t_game *game);
void	hooks(int keycode, t_game *game);
void	s_key(t_game *game);
void	a_key(t_game *game);
void	d_key(t_game *game);
void	w_key(t_game *game);



#endif
