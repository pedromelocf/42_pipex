/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:40 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/23 10:49:45 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../../lib/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid_child1;
	pid_t	pid_child2;
	char	**pathname;
	char	**argv;
	char	**env;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	int		status;
}			t_pipex;

t_pipex *init_pipex(char **argv, char **env);

#endif
