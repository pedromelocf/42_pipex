/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 11:55:51 by pmelo-ca         ###   ########.fr       */
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
		ft_printf("./pipex file1 cmd1 cmd2 file2.\n");
	return (0);
}

void execute(t_pipex *s_pipex, char **argv)
{
	execve(s_pipex->pathname[0], s_pipex->argv, s_pipex->env);
}