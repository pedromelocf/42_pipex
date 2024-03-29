/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/28 20:39:37 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*s_pipex;
	int		exit_status;

	exit_status = 0;
	if (argc == 5)
	{
		s_pipex = init_pipex(argv, env);
		if (!s_pipex)
		{
			error_handler(3, NULL, NULL, NULL);
			exit(3);
		}
		child_process1(s_pipex);
		child_process2(s_pipex);
		close(s_pipex->pipe_fd[0]);
		close(s_pipex->pipe_fd[1]);
		waitpid(s_pipex->pid_child2, &exit_status, 0);
		free(s_pipex);
	}
	else
		error_handler(4, NULL, NULL, NULL);
	exit(exit_status / 256);
}

t_pipex	*init_pipex(char **argv, char **env)
{
	t_pipex	*s_pipex;

	s_pipex = malloc(sizeof(t_pipex));
	if (s_pipex == NULL)
		return (NULL);
	s_pipex->argv = argv;
	s_pipex->env = env;
	if (pipe(s_pipex->pipe_fd) == -1)
	{
		error_handler(6, s_pipex, NULL, NULL);
		exit(1);
	}
	return (s_pipex);
}

void	child_process1(t_pipex *s_pipex)
{
	s_pipex->pid_child1 = fork();
	if (s_pipex->pid_child1 == 0)
	{
		close(s_pipex->pipe_fd[0]);
		s_pipex->infile = open(s_pipex->argv[1], O_RDONLY);
		if (s_pipex->infile == -1)
		{
			close(s_pipex->pipe_fd[1]);
			if (errno == EACCES)
				error_handler(1, s_pipex, NULL, s_pipex->argv[1]);
			error_handler(2, s_pipex, NULL, s_pipex->argv[1]);
		}
		dup2(s_pipex->pipe_fd[1], STDOUT_FILENO);
		dup2(s_pipex->infile, STDIN_FILENO);
		close(s_pipex->pipe_fd[1]);
		close(s_pipex->infile);
		execute(s_pipex, s_pipex->argv[2]);
		exit(EXIT_SUCCESS);
	}
}

void	child_process2(t_pipex *s_pipex)
{
	s_pipex->pid_child2 = fork();
	if (s_pipex->pid_child2 == 0)
	{
		close(s_pipex->pipe_fd[1]);
		s_pipex->outfile = open(s_pipex->argv[4], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRWXU | S_IRWXG | S_IRWXO);
		if (s_pipex->outfile == -1)
		{
			close(s_pipex->pipe_fd[0]);
			error_handler(1, s_pipex, NULL, s_pipex->argv[4]);
		}
		dup2(s_pipex->pipe_fd[0], STDIN_FILENO);
		dup2(s_pipex->outfile, STDOUT_FILENO);
		close(s_pipex->pipe_fd[0]);
		close(s_pipex->outfile);
		execute(s_pipex, s_pipex->argv[3]);
		exit(EXIT_SUCCESS);
	}
}

void	execute(t_pipex *s_pipex, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd[0])
		error_handler(127, s_pipex, cmd, argv);
	path = get_path(s_pipex, cmd[0]);
	if (!path)
		error_handler(127, s_pipex, cmd, argv);
	if (!ft_strncmp(path, "invalid", 8))
		error_handler(5, s_pipex, cmd, argv);
	execve(path, cmd, s_pipex->env);
	clean_matrix(cmd);
}
