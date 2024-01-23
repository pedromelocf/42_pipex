/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 11:05:54 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*s_pipex;

	if (argc == 5)
	{
		s_pipex = init_pipex(argv, env);
		child_process1(s_pipex);
		child_process2(s_pipex);
		waitpid(s_pipex->pid_child2, &s_pipex->status, 0);
		close(s_pipex->infile);
		close(s_pipex->outfile);
		free(s_pipex);
	}
	else
		printf("Bad arguments.");
	return (0);
}
