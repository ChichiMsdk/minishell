/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:11 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 17:31:11 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, size_t *count)
{
	if (num == -2147483648)
	{
		ft_putnbr((num / 10), count);
		ft_putchar('8', count);
	}
	else if (num < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-num, count);
	}
	else
	{
		if (num > 9)
			ft_putnbr((num / 10), count);
		ft_putchar(('0' + num % 10), count);
	}
}
