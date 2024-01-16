/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 14:04:02 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex *s_pipex;

	s_pipex = malloc(sizeof(t_pipex));
	s_pipex->infile = open(argv[1], O_RDONLY);
	s_pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	pipe(s_pipex->pipe_fd);
	s_pipex->pathname = validate_command(argv, envp);
}