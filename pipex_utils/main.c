/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 10:57:34 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*s_pipex;

	if (argc == 5)
	{
		s_pipex = init_pipex(argv, env);
		s_pipex->pid_child1 = fork();
		if (s_pipex->pid_child1 == 0)
		{
			s_pipex->infile = open(argv[1], O_RDONLY);
			if (s_pipex->infile == -1)
			{

			}
			close(s_pipex->pipe_fd[0]);
			dup2(s_pipex->pipe_fd[1], STDOUT_FILENO);
			close(s_pipex->pipe_fd[1]);
			dup2(s_pipex->infile, STDIN_FILENO);
			execve(s_pipex->pathname[0], argv[1], env);
			exit(0);
		}
		s_pipex->pid_child2 = fork();
		if (s_pipex->pid_child2 == 0)
		{
			s_pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
			if (s_pipex->outfile == -1)
			{
				
			}
			close(s_pipex->pipe_fd[1]);
			dup2(s_pipex->pipe_fd[0], STDIN_FILENO);
			close(s_pipex->pipe_fd[0]);
			dup2(s_pipex->outfile, STDOUT_FILENO);
			execve(s_pipex->pathname[1], argv[4], env);
			exit(0);
		}
		waitpid(s_pipex->pid_child2, &s_pipex->status, 0);
		close(s_pipex->infile);
		close(s_pipex->outfile);
		free(s_pipex);
	}
	else
		printf("Bad arguments.");
	return (0);
}
