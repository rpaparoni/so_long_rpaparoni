/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:06:03 by rpaparon          #+#    #+#             */
/*   Updated: 2025/02/17 16:40:59 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ptrlen(uintptr_t value)
{
	size_t	len;

	len = 0;
	if (value <= 0)
		len++;
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	ft_printp(unsigned long long value, int *counter)
{
	if (value == 0)
		(*counter) += (write(1, "(nil)", 5));
	else
	{
		(*counter) += (write(1, "0x", 2));
		ft_putptr(value);
		(*counter) += ft_ptrlen(value);
	}
}
