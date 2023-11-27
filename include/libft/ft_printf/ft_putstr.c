/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:15:00 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 17:15:00 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, size_t *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}
