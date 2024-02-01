/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/02/01 18:13:23 by pmelo-ca         ###   ########.fr       */
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
		return (validate_acess(cmd));
	while (ft_strncmp(s_pipex->env[i], "PATH=", 4))
		i++;
	paths = ft_split(s_pipex->env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i++], "/");
		possible_path = ft_strjoin(part_path, cmd);
		if (!(access(possible_path, X_OK)))
		{
			clean_child_data(paths, NULL, part_path);
			return (possible_path);
		}
		clean_child_data(NULL, possible_path, part_path);
	}
	clean_matrix(paths);
	return (NULL);
}

char	*validate_acess(char *cmd)
{
	if (!(access(cmd, X_OK)))
		return (cmd);
	else
		return ("invalid");
}

void	error_handler(int exit_status, t_pipex *s_pipex, char **cmd, char *msg)
{
	if (exit_status == 1 || exit_status == 2 || exit_status == 5
		|| exit_status == 6 || exit_status == 127)
	{
		free(s_pipex);
		if (exit_status == 1)
			ft_dprintf(2, "pipex: permision denied: %s\n", msg);
		else if (exit_status == 2)
			ft_dprintf(2, "pipex: no such file or directory: %s\n", msg);
		else if (exit_status == 5)
		{
			ft_dprintf(2, "pipex: no such file or directory: %s\n", msg);
			exit_status = 127;
		}
		else if (exit_status == 6)
			ft_dprintf(2, "pipex: error initializing pipe.\n");
		else if (exit_status == 127)
			ft_dprintf(2, "pipex: command not found: %s\n", msg);
		clean_matrix(cmd);
	}
	else if (exit_status == 3)
		ft_dprintf(2, "pipex: error initializing structure.\n");
	else if (exit_status == 4)
		ft_dprintf(2, "./pipex file1 cmd1 cmd2 file2.\n");
	exit(exit_status);
}

void	clean_child_data(char **matrix, char *possible_path, char *part_path)
{
	if (matrix)
		clean_matrix(matrix);
	if (possible_path)
		free(possible_path);
	if (part_path)
		free(part_path);
}

void	clean_matrix(char **matrix)
{
	int	x;

	x = 0;
	if (!matrix)
		return ;
	while (matrix[x])
		free(matrix[x++]);
	if (matrix)
		free(matrix);
}
