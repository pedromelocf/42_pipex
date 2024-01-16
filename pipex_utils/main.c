/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 11:27:58 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex		s_pipex;
	int validation;

	if (argc != 5)
		return(1);
	s_pipex.fd = open(argv[1], O_RDWR);
	if (s_pipex.fd < 0)
		printf("no such file or directory: %s\n", argv[1]);
		return 1;
	pipe(s_pipex.pipe_fd);
	validation = validate_command(char **argv, char **envp);
	if (validation == 0) // os dois comandos existem
	{
		s_pipex.pid = fork;
		if (s_pipex.pid == 0) //child process
		{
			close(s_pipex.pipe_fd[0]);
			dup2(s_pipex.pipe_fd[1], STDOUT_FILENO);
			close(s_pipex.pipe_fd[1]);
			execve(s_pipex.pathname[0], argv[1], envp);
			exit;
		}
		else if (s_pipex.pid > 0) //parent process
		{
			wait(NULL);
			close(s_pipex.pipe_fd[1]);
			void *buffer = read(s_pipex.pipe_fd[0], buffer, 1024);
			close(s_pipex.pipe_fd[0]);
			execve(s_pipex.pathname[1], argv[4], envp);
		}
	}
	else if (validation == 1) // argv[3] é um comando valido e argv[2] não é um comando valido
		executar segundo comando;
		printar que o primeiro comando é invalido;
	else if(validation == 2) // argv[2] é um comando valido e argv[3] não é um comando valido
		printar que o segundo comando é invalido;
	else // nenhum dos comandos são validos
		printar que o segundo comando é invalido;
		printar que o primeiro comando é invalido;
	close(s_pipex.fd);
	return 0;
}