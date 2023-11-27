/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:37:01 by chmoussa          #+#    #+#             */
/*   Updated: 2023/05/30 16:37:01 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(char const *str, ...);

void	ft_putint(unsigned int num, size_t *count);
void	ft_putchar(char c, size_t *count);
void	ft_putstr(char *str, size_t *count);
void	ft_putnbr(int num, size_t *count);
void	ft_putptr(void *ptr, size_t *count);
void	ft_puthex(unsigned int num, size_t *count, char *base);

char	*ft_base(unsigned long long n, char *base);

#endif