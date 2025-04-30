/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:48:18 by rpaparon          #+#    #+#             */
/*   Updated: 2025/04/30 13:50:52 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_moves(t_game *game)
{
	ft_printf("\033[95mTotal Moves: %d\n\033[0m", game->n_moves);
	game->n_moves++;
}

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

int	close_game(t_game *game)
{
	ft_kill("Game closed", game);
	return (0);
}
