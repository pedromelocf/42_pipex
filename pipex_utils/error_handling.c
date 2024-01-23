/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:52:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/18 17:56:30 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	clean_print_return(int error, char *message, char *argv, t_pipex **s_pipex)
{
	ft_printf("%s", message);
	ft_printf("%s\n", argv);
	free(s_pipex);
	return (error);
}
