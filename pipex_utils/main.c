/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/15 15:10:58 by pmelo-ca         ###   ########.fr       */
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
	validation = validate_command(char **argv, char **envp);
	if (validation == 0) // os dois comandos existem
		s_pipex.pid = fork;
		if (s_pipex.pid == 0) //child process
		{
			s_pipex.fd_parent = dup(open(argv[3], O_RDONLY));
			execve(s_pipex.pathname[0], argv[2], envp);
		}
		else if (s_pipex.pid > 0) //parent process
		{
			wait(NULL);
		}
	else if (validation == 1) // argv[3] existe e argv[2] não existe
		tentar executar segundo comando;
		printar que o primeiro comando é invalido;
	else if(validation == 2) // argv[2] existe e argv[3] não existe
		printar que o segundo comando é invalido;
	else // nenhum dos comandos existem
		printar que o segundo comando é invalido;
		printar que o primeiro comando é invalido;
	return 0;
}