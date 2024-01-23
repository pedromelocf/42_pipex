/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 10:38:51 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*s_pipex;

	if (argc == 5)
	{
		s_pipex = init_pipex();
		s_pipex->infile = open(argv[1], O_RDONLY);
		if (s_pipex->infile < 0) // infile não existe
		{
			dup2(s_pipex->outfile, STDOUT_FILENO);
			execve(s_pipex->pathname[1], argv[3], envp);
			return (clean_print_return(1, "no such file or directory", argv[1], s_pipex));
		}
		s_pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
		if (s_pipex->outfile < 0) // outfile não existe/ não pode ser criado
			return (clean_print_return(1, "error opening file:", argv[4], s_pipex));
		pipe(s_pipex->pipe_fd);
		validate_commands(argv, envp, s_pipex);
		s_pipex->pid_child1 = fork();
		if (s_pipex->pid_child1 == 0) //child process cmd1
		{
			close(s_pipex->pipe_fd[0]);
			dup2(s_pipex->pipe_fd[1], STDOUT_FILENO);
			close(s_pipex->pipe_fd[1]);
			dup2(s_pipex->infile, STDIN_FILENO);
			execve(s_pipex->pathname[0], argv[1], envp);
			exit(0);
		}
		s_pipex->pid_child2 = fork();
		if (s_pipex->pid_child2 == 0) //child process cmd2
		{
			close(s_pipex->pipe_fd[1]);
			dup2(s_pipex->pipe_fd[0], STDIN_FILENO);
			close(s_pipex->pipe_fd[0]);
			dup2(s_pipex->outfile, STDOUT_FILENO);
			execve(s_pipex->pathname[1], argv[4], envp);
			exit(0);
		}
		waitpid(s_pipex->pid_child2,&s_pipex->status, 0);
		close(s_pipex->infile);
		close(s_pipex->outfile);
		free(s_pipex);
	}
	else
		printf("Bad arguments.");
	return (0);
}
