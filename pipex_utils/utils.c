/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/31 10:00:54 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	error_handler(int exit_status, t_pipex *s_pipex, char **cmd, char *msg)
{
	if (exit_status == 1)
	{
		free(s_pipex);
		ft_putstr_fd("Error initializing pipe.\n", 2);
	}
	else if (exit_status == 2)
	{
		free(s_pipex);
		ft_dprintf(2, "zsh: no such file or directory: ");
		ft_dprintf(2, "%s\n", msg);
	}
	else if (exit_status == 3)
		ft_putstr_fd("Error initializing structure.\n", 2);
	else if (exit_status == 4)
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2.\n", 2);
	else if (exit_status == 127)
	{
		ft_dprintf(2, "zsh: command not found: ");
		ft_dprintf(2, "%s\n", msg);
		clean_matrix(cmd);
		free(s_pipex);
	}
	exit(exit_status);
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

int	get_exit(int exit)
{
	return (exit / 256);
}
