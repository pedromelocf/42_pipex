/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:00:03 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/30 13:16:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[length])
	{
		ft_putchar(str[length]);
		length++;
	}
	return (length);
}
