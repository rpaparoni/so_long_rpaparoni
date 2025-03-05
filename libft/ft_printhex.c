/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:51:36 by rpaparon          #+#    #+#             */
/*   Updated: 2025/02/17 16:39:31 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hexlen(unsigned int value)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, c);
		ft_puthex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

void	ft_printhex(unsigned int value, const char c, int *counter)
{
	if (value == 0)
	{
		(*counter) += (write(1, "0", 1));
	}
	else
	{
		ft_puthex(value, c);
		(*counter) += ft_hexlen(value);
	}
}
