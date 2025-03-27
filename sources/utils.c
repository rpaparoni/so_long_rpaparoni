/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:15:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/27 15:31:31 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_error(char *msg)
{
    ft_printf("Error\n%s\n", msg);
    exit(EXIT_FAILURE);
}