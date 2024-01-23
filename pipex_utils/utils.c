/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 11:53:40 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*init_pipex(char **argv, char **env)
{
	t_pipex	*s_pipex;

	s_pipex = malloc(sizeof(t_pipex));
	s_pipex->argv = argv;
	s_pipex->env = env;
	pipe(s_pipex->pipe_fd);
	return (s_pipex);
}

void	child_process1(t_pipex *s_pipex)
{
	s_pipex->pid_child1 = fork();
	if (s_pipex->pid_child1 == 0)
	{
		s_pipex->infile = open(s_pipex->argv[1], O_RDONLY);
		if (s_pipex->infile == -1)
		{
			exit(1);
		}
		close(s_pipex->pipe_fd[0]);
		dup2(s_pipex->pipe_fd[1], STDOUT_FILENO);
		close(s_pipex->pipe_fd[1]);
		dup2(s_pipex->infile, STDIN_FILENO);
		execute(s_pipex, s_pipex->argv[1]);
		exit(0);
	}
}

void	child_process2(t_pipex *s_pipex)
{
	s_pipex->pid_child2 = fork();
	if (s_pipex->pid_child2 == 0)
	{
		s_pipex->outfile = open(s_pipex->argv[4], O_TRUNC | O_CREAT | O_RDWR);
		if (s_pipex->outfile == -1)
		{
			exit(1);
		}
		close(s_pipex->pipe_fd[1]);
		dup2(s_pipex->pipe_fd[0], STDIN_FILENO);
		close(s_pipex->pipe_fd[0]);
		dup2(s_pipex->outfile, STDOUT_FILENO);
		execute(s_pipex, s_pipex->argv[4]);
		exit(0);
	}
}
