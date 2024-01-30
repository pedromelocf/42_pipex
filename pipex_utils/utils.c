/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/30 13:24:59 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(t_pipex *s_pipex, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(s_pipex, cmd[0]);
	if (!path)
		error_handler(127, s_pipex, cmd, argv);
	execve(path, cmd, s_pipex->env);
	clean_matrix(cmd);
}

char	*get_path(t_pipex *s_pipex, char *cmd)
{
	char	*part_path;
	char	*possible_path;
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (ft_strncmp(s_pipex->env[i], "PATH=", 4))
		i++;
	paths = ft_split(s_pipex->env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		possible_path = ft_strjoin(part_path, cmd);
		if (!(access(possible_path, X_OK)))
		{
			clean_child_data(paths, NULL, part_path);
			return (possible_path);
		}
		clean_child_data(NULL, possible_path, part_path);
		i++;
	}
	clean_matrix(paths);
	return (NULL);
}

void	clean_child_data(char **matrix, char *possible_path, char *part_path)
{
	if (matrix)
		clean_matrix(matrix);
	if (possible_path)
		free(possible_path);
	free(part_path);
}

void	clean_matrix(char **matrix)
{
	int	x;

	x = 0;
	while (matrix[x])
		free(matrix[x++]);
	free(matrix);
}

void		error_handler(int error, t_pipex *s_pipex, char **cmd, char *msg)
{
	if (error == 1)
	{
		free(s_pipex);
		ft_putstr_fd("Error initializing pipe.\n", 2);
	}
	else if (error == 2)
	{
		free(s_pipex);
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_dprintf(2, "%s\n", msg);
	}
	else if (error == 3)
		ft_putstr_fd("Error initializing structure.\n", 2);
	else if (error == 127)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_dprintf(2, "%s\n", msg);
		clean_matrix(cmd);
		free(s_pipex);
	}
	exit(error);
}
