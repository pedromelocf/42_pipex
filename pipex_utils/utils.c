/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/30 10:17:18 by pmelo-ca         ###   ########.fr       */
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
		path = cmd[0];
	if (execve(path, cmd, s_pipex->env)!= 0)
		error_handler(s_pipex, 3);
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
		return (NULL);
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

int	error_handler(t_pipex *s_pipex, int error)
{
	if (error == 1)
	{
		free(s_pipex);
		ft_putstr_fd("Error opening pipe.\n", 2);
		exit(1);
	}
	else if (error == 2)
	{
		ft_putstr_fd("zsh: no such file or directory\n", 2);
		free(s_pipex);
		exit(1);
	}
	else if (error == 3)
	{
		ft_putstr_fd("zsh: command not found\n", 2);
		free(s_pipex);
		exit(127);
	}
	return (0);
}
