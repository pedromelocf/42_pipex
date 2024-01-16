/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 13:59:17 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	s_pipex;

	if (argc != 5)
		return (1);
	s_pipex = init_pipex(argv, envp);
	s_pipex.infile = open(argv[1], O_RDONLY);
	if (s_pipex.infile < 0)
	{
		dup2(s_pipex.outfile, STDOUT_FILENO);
		execve(s_pipex.pathname[1], argv[3], envp);
		printf("no such file or directory: %s\n", argv[1]);
		return (1);
	}
	s_pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	if (s_pipex.outfile < 0)
	{
		printf("error opening file: %s\n", argv[4]);
		return (1);
	}
	pipe(s_pipex.pipe_fd);
	if (s_pipex.validation == 0) // os dois comandos existem
	{
		s_pipex.pid = fork();
		if (s_pipex.pid == 0) //child process
		{
			close(s_pipex.pipe_fd[0]);
			dup2(s_pipex.pipe_fd[1], STDOUT_FILENO);
			close(s_pipex.pipe_fd[1]);
			dup2(s_pipex.infile, STDIN_FILENO);
			execve(s_pipex.pathname[0], argv[1], envp);
			exit(0);
		}
		else if (s_pipex.pid > 0) //parent process
		{
			wait(NULL);
			close(s_pipex.pipe_fd[1]);
			dup2(s_pipex.pipe_fd[0], STDIN_FILENO);
			close(s_pipex.pipe_fd[0]);
			dup2(s_pipex.outfile, STDOUT_FILENO);
			execve(s_pipex.pathname[1], argv[4], envp);
		}
	}
	else if (s_pipex.validation == 1)
		// argv[3] é um comando valido e argv[2] não é um comando valido
	{
		dup2(s_pipex.outfile, STDOUT_FILENO);
		execve(s_pipex.pathname[1], argv[3], envp);
		printf("invalid command: %s\n", argv[2]);
			//printar que o primeiro comando é invalido;
	}
	else if (s_pipex.validation == 2)
		// argv[2] é um comando valido e argv[3] não é um comando valido
		printf("invalid command: %s\n", argv[3]);
			//printar que o segundo comando é invalido;
	else
		// nenhum dos comandos são validos
	{
		printf("invalid command: %s\n", argv[3]);
			//printar que o segundo comando é invalido;
		printf("invalid command: %s\n", argv[2]);
			//printar que o primeiro comando é invalido;
	}
	close(s_pipex.infile);
	close(s_pipex.outfile);
	return (0);
}