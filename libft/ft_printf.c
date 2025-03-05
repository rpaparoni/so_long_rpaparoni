/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:49 by rpaparon          #+#    #+#             */
/*   Updated: 2025/02/17 16:48:10 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *value, int *counter)
{
	int	i;

	i = 0;
	if (!value)
		value = "(null)";
	while (value[i] != '\0')
	{
		ft_putchar(value[i]);
		(*counter)++;
		i++;
	}
	return (1);
}

static void	ft_type(const char c, va_list value, int *counter)
{
	if (c == 'c')
	{
		(*counter)++;
		ft_putchar(va_arg(value, int));
	}
	else if (c == 's')
		ft_putstr(va_arg(value, char *), counter);
	else if (c == 'p')
		ft_printp(va_arg(value, unsigned long long), counter);
	else if (c == 'i' || c == 'd')
		ft_printid(va_arg(value, int), counter);
	else if (c == 'u')
		ft_printu(va_arg(value, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(value, unsigned int), c, counter);
	else if (c != 0)
	{
		(*counter)++;
		ft_putchar(c);
	}
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			counter += ft_putchar(str[0]);
		else
			ft_type(*++str, args, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
