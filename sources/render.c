/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:33 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/26 13:36:51 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

int	item_count

char    *get_texture(t_game *game, char c)
{
    if (c == '1')
        return (game->textures.wall);
    else if (c == '0')
        return (game->textures.floor);
    else if (c == 'C')
        return (game->textures.collectible);
    else if (c == 'E')
        return (game->textures.exit);
    else if (c == 'P')
        return (game->textures.player);
    return (NULL);
}