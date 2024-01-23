/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 10:55:54 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex *init_pipex(char **argv, char **env)
{
	t_pipex *s_pipex;

	s_pipex = malloc(sizeof(t_pipex));
	s_pipex->argv = argv;
	s_pipex->env = env;
	pipe(s_pipex->pipe_fd);
	return(s_pipex);
}
