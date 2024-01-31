/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:47:50 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/31 09:59:13 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	short int	i;
	int			length;
	va_list		args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += ft_check_conversion_fd(str, i, args, fd);
		}
		else
			length += ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(args);
	return (length);
}
