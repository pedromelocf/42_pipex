/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:42 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/24 11:38:28 by pmelo-ca         ###   ########.fr       */
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

void	execute(t_pipex *s_pipex, char *argv)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = get_path(s_pipex, cmd[0]);
	if (!path)
		path = cmd[0];
	execve(path, cmd, s_pipex->env);
}

char	*get_path(t_pipex *s_pipex, char *cmd)
{
	char	*part_path;
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr(&cmd[0], '/'))
		return (NULL);
	while (!(ft_strnstr(s_pipex->env[i], "PATH=", 5)))
		i++;
	i += 5;
	paths = ft_split(s_pipex->env[i], ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(&path[i], "/");
		path = ft_strjoin(&part_path[i], cmd);
		if (access(path, X_OK))
			return (path);
		i++;
	}
	return (NULL);
}
