/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:09:30 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 17:09:30 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(unsigned int num, size_t *count)
{
	char	*str;

	str = ft_base(num, "0123456789");
	ft_putstr(str, count);
	free(str);
}
