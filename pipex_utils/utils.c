/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:57:22 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/24 15:40:16 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	while (!(ft_strnstr(s_pipex->env[i], "PATH=", 4)))
	{
		dprintf(2, "A\n%s\n", s_pipex->env[i]);
		i++;
	}
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
