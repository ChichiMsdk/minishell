/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:17:20 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 17:17:20 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, size_t *count)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (size_t)ptr;
	ft_putstr("0x", count);
	str = ft_base(ptr_address, "0123456789abcdef");
	ft_putstr(str, count);
	free(str);
}
