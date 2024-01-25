/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/25 12:02:56 by pmelo-ca         ###   ########.fr       */
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
		waitpid(s_pipex->pid_child1, NULL, 0);
		child_process2(s_pipex);
		// waitpid(s_pipex->pid_child2, NULL, 0);
		close(s_pipex->infile);
		close(s_pipex->outfile);
		free(s_pipex);
	}
	else
		ft_printf("./pipex file1 cmd1 cmd2 file2.\n");
	return (0);
}

t_pipex	*init_pipex(char **argv, char **env)
{
	t_pipex	*s_pipex;

	s_pipex = malloc(sizeof(t_pipex));
	s_pipex->argv = argv;
	s_pipex->env = env;
	if (pipe(s_pipex->pipe_fd) == -1)
		exit(0);
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
		dup2(s_pipex->infile, STDIN_FILENO);
		close(s_pipex->pipe_fd[1]);
		execute(s_pipex, s_pipex->argv[2]);
		exit(0);
	}
}

void	child_process2(t_pipex *s_pipex)
{
	s_pipex->pid_child2 = fork();
	if (s_pipex->pid_child2 == 0)
	{
		s_pipex->outfile = open(s_pipex->argv[4], O_CREAT | O_RDWR | O_TRUNC,
				S_IRWXU | S_IRWXG | S_IRWXO);
		if (s_pipex->outfile == -1)
		{
			exit(1);
		}
		close(s_pipex->pipe_fd[1]);
		dup2(s_pipex->pipe_fd[0], STDIN_FILENO);
		dup2(s_pipex->outfile, STDOUT_FILENO);
		close(s_pipex->pipe_fd[0]);
		execute(s_pipex, s_pipex->argv[3]);
		exit(0);
	}
}
