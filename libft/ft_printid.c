/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:42:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/02/17 16:41:55 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int value)
{
	size_t	len;

	len = 0;
	if (value <= 0)
		len++;
	while (value)
	{
		len++;
		value /= 10;
	}
	return (len);
}

void	ft_printid(int value, int *counter)
{
	ft_putnbr_fd(value, 1);
	(*counter) += ft_intlen(value);
}
