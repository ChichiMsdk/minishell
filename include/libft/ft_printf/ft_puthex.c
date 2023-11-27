/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:33:13 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 17:33:13 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, size_t *count, char *base)
{
	char	*str;

	str = ft_base(num, base);
	ft_putstr(str, count);
	free(str);
}
