/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversion_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:21:54 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/31 09:59:29 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_check_conversion_fd(const char *str, int i, va_list args, int fd)
{
	int	length;

	length = 0;
	if (str[i] == 'c')
		length += ft_putchar(va_arg(args, int));
	if (str[i] == 's')
		length += ft_putstr_fd(va_arg(args, char *), fd);
	if (str[i] == 'p')
		length += ft_put_voidpointer(va_arg(args, char *));
	if (str[i] == 'd' || str[i] == 'i')
		length += ft_putnbr(va_arg(args, int));
	if (str[i] == 'u')
		length += ft_put_unsigned(va_arg(args, int));
	if (str[i] == 'x' || str[i] == 'X')
		length += ft_put_hex(va_arg(args, unsigned int), str, i);
	if (str[i] == '%')
		length += ft_putchar('%');
	return (length);
}
