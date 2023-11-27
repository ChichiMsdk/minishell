/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:33:38 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 16:33:38 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), count);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), count);
	else if (*str == 'p')
		ft_putptr(va_arg(va, void *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(va, int), count);
	else if (*str == 'u')
		ft_putint(va_arg(va, unsigned int), count);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(va, unsigned int), count, "0123456789abcdef");
		else
			ft_puthex(va_arg(va, unsigned int), count, "0123456789ABCDEF");
	}
	else if (*str == '%')
		ft_putchar(*str, count);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		count;

	if (!str)
		return (0);
	count = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &count);
		}
		else
			ft_putchar(*str, &count);
		str++;
	}
	va_end(va);
	return (count);
}
