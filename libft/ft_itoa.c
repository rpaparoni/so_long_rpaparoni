/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:15:11 by rpaparon          #+#    #+#             */
/*   Updated: 2025/02/17 16:19:20 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n != 0)
	{
		if (n < 0)
		{
			count++;
			n = -n;
		}
		while (n != 0)
		{
			n = n / 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_counter(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
